#include "Labyrinthe.h"
#include "affichage.h"

/************************************************************************************************/
/*                                        DEFINITION                                            */
/************************************************************************************************/


static int obtenir_etat(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int position)
{
	//Cette Fonction est � changer pour l'algorithme trouver plus bas pour trouver les i et les j
	int position_x, position_y;

	position_x = position / LABYRINTHE_NB_LIGNES;
	position_y = position % LABYRINTHE_NB_LIGNES;
	return labyrinthe[position_y][position_x];
}

static int est_vide(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int position)
{
	int vide = obtenir_etat(labyrinthe, position);

	if (vide == LABYRINTHE_VIDE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int est_sortie(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int position)
{
	int sortie = obtenir_etat(labyrinthe, position);

	if (sortie == LABYRINTHE_SORTIE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static void ajouter_sortie(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	//labyrinthe[LABYRINTHE_NB_LIGNES-2][LABYRINTHE_NB_COLONNES-2] = LABYRINTHE_SORTIE;

	
	int position = (LABYRINTHE_NB_LIGNES * LABYRINTHE_NB_COLONNES - 1) - (LABYRINTHE_NB_LIGNES + 1);
    int voisins[NB_VOISINS] = {-2, -2, -2, -2};
    int direction = 0;
	int x,y,r, i;
	int nb_voisin = obtenir_voisins(labyrinthe, position,voisins, LABYRINTHE_MUR);
	r=0;
	printf("position = %d, ", position);
	printf("nb_voisin = %d de %d\n", nb_voisin, r);
    while(nb_voisin != 3)
    {
		
		position -=2;
		nb_voisin = obtenir_voisins(labyrinthe, position,voisins, LABYRINTHE_MUR);
		r++;
		printf("position = %d, ", position);
		printf("nb_voisin = %d de %d\n", nb_voisin, r);
    }

		x = position / LABYRINTHE_NB_LIGNES;
		y = position % LABYRINTHE_NB_LIGNES;
		printf("\nposition = %d", position);
		printf("\ny = %d", y);
		printf("\nx = %d", x);

		system("pause");
		labyrinthe[y][x]= LABYRINTHE_SORTIE; 
	 
}




void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	int i, j;

	//Parcour le tableau[][] au complet et place un "mur" dans toutes les cases
	for (i = 0; i < LABYRINTHE_NB_LIGNES; i++)
	{
		for (j = 0; j < LABYRINTHE_NB_COLONNES; j++)
		{
			labyrinthe[i][j] = LABYRINTHE_MUR;
		}
	}
}

void labyrinthe_dessiner_solution(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int solution[], int longueur, int type_solution)
{
	int k;

	for (k = 0; k < longueur; k++)
	{
		int position_actuel = solution[k];
		int prochaine_position = solution[k + 1];
		int y = 1, x = 1;

		//Prochaine position est en dessous de la position actuel
		if (prochaine_position == position_actuel + 1)
		{
			x++; //Modification de i++
			if (type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if (k != longueur - 1)
				{
					x++; //Modification de i++
					labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if (type_solution == LABYRINTHE_SOLUTION)
			{
				labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				if (k != longueur - 1)
				{
					y++;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est a droite de la position actuel
		else if (prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES - 1) / 2))
		{
			if (type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				x++;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if (k != longueur - 1)
				{
					x++;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if (type_solution == LABYRINTHE_SOLUTION)
			{
				x++;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				if (k != longueur - 1)
				{
					x++;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est au dessus de la position actuel
		else if (prochaine_position == position_actuel - 1)
		{
			if (type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				y--;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if (k != longueur - 1)
				{
					y--;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if (type_solution == LABYRINTHE_SOLUTION)
			{
				y--;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				if (k != longueur - 1)
				{
					y--;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est a gauche de la position actuel
		else if (prochaine_position == position_actuel - ((LABYRINTHE_NB_LIGNES - 1) / 2))
		{
			if (type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				x--;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if (k != longueur - 1)
				{
					x--;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if (type_solution == LABYRINTHE_SOLUTION)
			{
				x--;
				labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				if (k != longueur - 1)
				{
					x--;
					labyrinthe[y][x] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}
	}
}
/*
void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin)
{
	int k;

	for (k = 0; k < longueur_chemin; k++)
	{
		int position_actuel = chemin[k];
		int prochaine_position = chemin[k + 1];
		int x, c;
		int y = 0;
		//Prochaine position est en dessous de la position actuel
		if (prochaine_position == position_actuel + 1)
		{
			//Pour trouver x
			x = (2 * (position_actuel / (LABYRINTHE_NB_COLONNES - 1) / 2))+1;

			//Pour trouvez y
			y = (position_actuel % ((LABYRINTHE_NB_LIGNES - 1) / 2) * 2) + 1;
			//y = (prochaine_position + position_actuel) % (LABYRINTHE_NB_LIGNES - 1);
			
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			y++; 
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			if (k != longueur_chemin - 1)
			{
				y++; 
				labyrinthe[x][y] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est a droite de la position actuel
		else if (prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES - 1) / 2))
		{
			//Pour trouver y
			y = (position_actuel % ((LABYRINTHE_NB_LIGNES - 1) / 2) * 2) + 1;

			//Pour trouver j et creuser
			x = (2 * (position_actuel / (LABYRINTHE_NB_COLONNES - 1) / 2)) + 1;

			labyrinthe[x][y] = LABYRINTHE_VIDE;
			x++;
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			if (k != longueur_chemin - 1)
			{
				x++;
				labyrinthe[x][y] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est au dessus de la position actuel
		else if (prochaine_position == position_actuel - 1)
		{
			//Pour trouver j
			x = (2 * (position_actuel / (LABYRINTHE_NB_COLONNES - 1) / 2)) + 1;
			//Pour trouver i
			y = (position_actuel % ((LABYRINTHE_NB_LIGNES - 1) / 2) * 2) + 1;
			
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			y--;
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			if (k != longueur_chemin - 1)
			{
				y--;
				labyrinthe[x][y] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est a gauche de la position actuel
		else if (prochaine_position == position_actuel - ((LABYRINTHE_NB_LIGNES - 1) / 2))
		{
			//Pour trouver i
			y = (position_actuel % ((LABYRINTHE_NB_LIGNES - 1) / 2) * 2) + 1;

			//Pour trouver j et creuser
			x = (2 * (position_actuel / (LABYRINTHE_NB_COLONNES - 1) / 2)) + 1;

			labyrinthe[x][y] = LABYRINTHE_VIDE;
			x--;
			labyrinthe[x][y] = LABYRINTHE_VIDE;
			if (longueur_chemin != 0)
			{
				x--;
				labyrinthe[x][y] = LABYRINTHE_VIDE;
			}
		}
	}
}*/

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin)
{
	int x, position_x, position_y, position_x_apres, position_y_apres;
	int position_x_milieu, position_y_milieu;
	for (x = longueur_chemin-1; x > 0; x--)
	{
		position_x = chemin[x] / ((LABYRINTHE_NB_LIGNES - 1) / 2);	//coordonee en x dans le tableau de 4x4
		position_y = chemin[x] % ((LABYRINTHE_NB_LIGNES - 1) / 2); //coordonee en y dans le tableau de 4x4
		position_x_apres = chemin[x-1] / ((LABYRINTHE_NB_LIGNES - 1) / 2); //coordonee en x de le prochaine position dans le tableau de 4x4
		position_y_apres = chemin[x-1] % ((LABYRINTHE_NB_LIGNES - 1) / 2); //coordonee en y de le prochaine position dans le tableau de 4x4
		position_x = position_x * 2 + 1;	//coordonee en x dans le tableau de 9x9
		position_y = position_y * 2 + 1;	//coordonee en y dans le tableau de 9x9
		position_x_apres = position_x_apres * 2 + 1;	//coordonee en x du future dans le tableau de 9x9
		position_y_apres = position_y_apres * 2 + 1;	//coordonee en y du future dans le tableau de 9x9
		position_x_milieu = (position_x + position_x_apres)/2;
		position_y_milieu = (position_y + position_y_apres)/2;
	
		labyrinthe[position_y][position_x]=0;
		labyrinthe[position_y_milieu][position_x_milieu]=0;
		labyrinthe[position_y_apres][position_x_apres]=0;
	}
}
void labyrinthe_generer(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	int k, x, y, h;
	int i = 0;
	int nb_colonnes = ((LABYRINTHE_NB_COLONNES - 1) / 2);
	int nb_lignes = ((LABYRINTHE_NB_LIGNES - 1) / 2);
	int *chemins[] = { NULL };
	int longueurs_chemins =0;

	labyrinthe_initialiser(labyrinthe);
	
	labyrinthe[1][1] = LABYRINTHE_VIDE;
	
	for (k = 0; k < (nb_colonnes * nb_lignes); k++)
	{
		x = (2 * (k / ((LABYRINTHE_NB_LIGNES - 1) / 2))) + 1;
		y = ((k % ((LABYRINTHE_NB_LIGNES - 1) / 2)) * 2) + 1;
		
				if (labyrinthe[y][x] == LABYRINTHE_MUR)
		{
			
			//

			ajouter_un_chemin(labyrinthe, chemins, &longueurs_chemins, k);

			labyrinthe_dessiner_chemin(labyrinthe, *chemins, longueurs_chemins);
		}
	}
	
	ajouter_sortie(labyrinthe);
	labyrinthe[1][1] = LABYRINTHE_ENTREE;
	
}

int labyrinthe_resoudre(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* solution[], int* longueur_solution)
{
	int i, j, k;
	int depart = 0;
	int *pile_visite[] = { NULL };
	int *voisins[] = { NULL };
	int longueur_visite = 0;

	for (i = 0; i < LABYRINTHE_NB_LIGNES; i++)
	{
		for (j = 0; j < LABYRINTHE_NB_COLONNES; j++)
		{
			if (labyrinthe[i][j] == LABYRINTHE_ENTREE)
			{
				depart = (i / 2) + (4 * (j / 2));
			}
		}
	}
	pile_ajouter(solution, longueur_solution, depart);
	pile_ajouter(pile_visite, &longueur_visite, depart);

	while (longueur_solution > 0 && (*solution)[0] != LABYRINTHE_SORTIE)
	{
		int sortie_trouve = 0;
		obtenir_voisins(labyrinthe, (*solution)[0], *voisins, LABYRINTHE_SORTIE);
		for (k = 0; k < NB_VOISINS - 1; k++)
		{
			if ((*voisins)[k] != -1)
			{
				pile_ajouter(solution, longueur_solution, (*voisins)[k]);
				sortie_trouve = 1;
			}
		}
		if (!sortie_trouve)
		{
			int voisin_disponible = 0;

			obtenir_voisins(labyrinthe, (*solution)[0], *voisins, LABYRINTHE_VIDE);

			//comparer a pile_visite

			for (k = 0; k < NB_VOISINS; k++)
			{
				if (pile_est_present(*solution, *longueur_solution, (*voisins)[k]) != -1)
				{
					(*voisins)[k] = -1;
				}
			}
			for (k = 0; k < NB_VOISINS; k++)
			{

			}
			for (k = 0; k < NB_VOISINS; k++)
			{
				if ((*voisins)[k] != -1)
				{
					voisin_disponible++;
				}
			}

			//Gestion des voisin commence ici

			pile_ajouter(solution, longueur_solution, (*voisins)[rand() % voisin_disponible]);
			pile_ajouter(pile_visite, &longueur_visite, (*voisins)[rand() % voisin_disponible]);

			//si pu de voisin
			if (voisin_disponible == 0)
			{
				//A DEFINIR
			}

		}
	}
	return 0; //A ENLEVER
}

void ajouter_un_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* chemins[], int* longueurs_chemins, int depart)
{
	int position_x;
	int position_y;
	int position_gros_tableau;
	int k=0;
	pile_initialiser_version_utile(chemins, longueurs_chemins, 1);
	*chemins[0] = depart;

	do
	{
		chemin_aleatoire_ajouter_un_pas(chemins, longueurs_chemins, (LABYRINTHE_NB_LIGNES - 1) / 2, (LABYRINTHE_NB_COLONNES - 1) / 2);//ajoute un nouveau pas au chemin

		position_x = *chemins[0] / ((LABYRINTHE_NB_LIGNES - 1) / 2);	//coordonee en x dans le tableau de 4x4
		position_y = *chemins[0] % ((LABYRINTHE_NB_LIGNES - 1) / 2); //coordonee en y dans le tableau de 4x4

		position_x = position_x * 2 + 1;	//coordonee en x dans le tableau de 9x9
		position_y = position_y * 2 + 1;	//coordonee en y dans le tableau de 9x9

		position_gros_tableau = ((LABYRINTHE_NB_LIGNES*position_x) + position_y);
		//*longueurs_chemins++;
	} while (!est_vide(labyrinthe, position_gros_tableau));
	//donne prochaine position a ajouter au chemin, si valide, ajoute, sinon tronque
}

static int obtenir_voisins(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int no_case, int voisins[NB_VOISINS], int etat)
{
	int x = 0;
	int buffer;
	int nb_voisins_valides = 0;
	printf("position : %d", no_case);
	if (obtenir_etat(labyrinthe, no_case + 1) == etat) //case du bas
	{
		printf("Bas ");
		voisins[0] = no_case + 1;
		nb_voisins_valides++;
	}
	else
		voisins[0] = -1;

	if (obtenir_etat(labyrinthe, no_case - 1) == etat) //case du haut
	{
		printf("Haut ");
		voisins[1] = no_case - 1;
		nb_voisins_valides++;
	}
	else
		voisins[1] = -1;

	if (obtenir_etat(labyrinthe, no_case + LABYRINTHE_NB_LIGNES) == etat) //case a droite
	{
		printf("Droite ");
		voisins[2] = no_case + LABYRINTHE_NB_LIGNES;
		nb_voisins_valides++;
	}
	else
		voisins[2] = -1;

	if (obtenir_etat(labyrinthe, no_case - LABYRINTHE_NB_LIGNES) == etat) //case a gauche
	{
		printf("Gauche ");
		voisins[3] = no_case - LABYRINTHE_NB_LIGNES;
		nb_voisins_valides++;
	}
	else
		voisins[3] = -1;

	while (!(x == 4))
	{
		if (voisins[x + 1] > voisins[x])
		{
			buffer = voisins[x];
			voisins[x] = voisins[x + 1];
			voisins[x + 1] = buffer;
			x = 0;
		}
		else
			x++;
	}
	printf("\n");
	return nb_voisins_valides; 

	//Cette fonction permet d'obtenir le nombre de voisins d'une case du labyrinthe ainsi que leurs indices de position. 
	//Seulement les voisins valides (dans la grille du labyrinthe) et qui ont un etat correspondant a celui recu en parametre sont retournes dans le tableau voisins. 
}
