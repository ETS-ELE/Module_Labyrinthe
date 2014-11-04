
#include "Labyrinthe.h"


/************************************************************************************************/
/*                                        DEFINITION                                            */
/************************************************************************************************/

void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	int i, j;
	
	//Parcour le tableau[][] au complet et place un "mur" dans toutes les cases
	for(i = 0; i < LABYRINTHE_NB_LIGNES; i++)
	{
		for(j = 0; j < LABYRINTHE_NB_COLONNES; j++)
		{
			labyrinthe[i][j] = LABYRINTHE_MUR;
		}
	}
}

static int obtenir_etat(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int position)
{
	//Cette Fonction est à changer pour l'algorithme trouver plus bas pour trouver les i et les j
	int i, j;
	int position_actuel = 0;
	
	//Parcour le tableau[][] jusqu'à ce que la position du tableau[][] corresponde à la position
	for(j = 1; j < LABYRINTHE_NB_COLONNES; j += 2)
	{
		for(i = 1; i < LABYRINTHE_NB_LIGNES; i += 2)
		{
			position_actuel++;
			if(position_actuel == position)
			{
				return labyrinthe[i][j];
			}
		}
	}
	return -1;
}

static int est_vide(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int position)
{
	int vide = obtenir_etat(labyrinthe,position);

	if(vide == LABYRINTHE_VIDE)
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
	int sortie = obtenir_etat(labyrinthe,position);

	if(sortie == LABYRINTHE_SORTIE)
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
	int i, j;
	
	//Regarde le premier "couloir vide" depuis le bas à droite, et en fait la sortie
	for(j = LABYRINTHE_NB_COLONNES; j > LABYRINTHE_NB_COLONNES; j -= 2)
	{
		for(i = LABYRINTHE_NB_LIGNES; i > LABYRINTHE_NB_LIGNES; i -= 2)
		{
			if(labyrinthe[i][j] == LABYRINTHE_VIDE)
			{
				labyrinthe[i][j] = LABYRINTHE_SORTIE;
				return;
			}
		}
	}
}

void labyrinthe_dessiner_solution(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int solution[], int longueur, int type_solution)
{
	int k;

	for(k = 0; k < longueur; k++)
	{
		int position_actuel = solution[k];
		int prochaine_position = solution[k + 1];
		int i = 1, j = 1;

		//Prochaine position est en dessous de la position actuel
		if(prochaine_position == position_actuel + 1)
		{
			j++; //Modification de i++
			if(type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if(k != longueur - 1)
				{
					j++; //Modification de i++
					labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if(type_solution == LABYRINTHE_SOLUTION)
			{
				labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				if(k != longueur - 1)
				{
					i++;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est a droite de la position actuel
		else if(prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES -1)/2))
		{
			if(type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				j++;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if(k != longueur - 1)
				{
					j++;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if(type_solution == LABYRINTHE_SOLUTION)
			{
				j++;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				if(k != longueur - 1)
				{
					j++;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est au dessus de la position actuel
		else if(prochaine_position == position_actuel - 1)
		{
			if(type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				i--;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if(k != longueur - 1)
				{
					i--;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if(type_solution == LABYRINTHE_SOLUTION)
			{
				i--;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				if(k != longueur - 1)
				{
					i--;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}

		//Prochaine position est a gauche de la position actuel
		else if(prochaine_position == position_actuel - ((LABYRINTHE_NB_LIGNES -1)/2))
		{
			if(type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				j--;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if(k != longueur - 1)
				{
					j--;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				}
			}
			else if(type_solution == LABYRINTHE_SOLUTION)
			{
				j--;
				labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				if(k != longueur - 1)
				{
					j--;
					labyrinthe[i][j] = LABYRINTHE_SOLUTION;
				}
			}
			else
			{
				printf("Type de solution inconnue");
			}
		}
	}
}

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin)
{
	int k;

	for(k = 0; k < longueur_chemin; k++)
	{
		int position_actuel = chemin[k];
		int prochaine_position = chemin[k + 1];
		int i, j, c;

		//Prochaine position est en dessous de la position actuel
		if(prochaine_position == position_actuel + 1)
		{
			//Pour trouver j
			for(c = 0; c < ((LABYRINTHE_NB_COLONNES - 1) / 2) - 1; c++)
			{
				if(position_actuel > (((LABYRINTHE_NB_LIGNES - 1) / 2) * c) && position_actuel <= (((LABYRINTHE_NB_LIGNES - 1) / 2) * (c + 1)))
				{
					j = (c + (c + 1));
				}
			}

			//Pour trouvez i
			i = (prochaine_position + position_actuel)%(LABYRINTHE_NB_LIGNES - 1);
			i++; //Modification de i++

			labyrinthe[i][j] = LABYRINTHE_VIDE;
			if(k != longueur_chemin - 1)
			{
				i++; //Modification de i++
				labyrinthe[i][j] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est a droite de la position actuel
		else if(prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES - 1)/2))
		{
			//Pour trouver i
			i = (position_actuel%(((LABYRINTHE_NB_LIGNES - 1)/2) * 2) + 1);

			//Pour trouver j et creuser
			for(c = 0; c < ((LABYRINTHE_NB_COLONNES - 1) / 2) - 1; c++)
			{
				if(position_actuel > (((LABYRINTHE_NB_LIGNES - 1) / 2) * c) && position_actuel <= (((LABYRINTHE_NB_LIGNES - 1) / 2) * (c + 1)))
				{
					j = (c + (c + 1));
					labyrinthe[i][j] = LABYRINTHE_VIDE;
					j++;
					labyrinthe[i][j] = LABYRINTHE_VIDE;
					if(k != longueur_chemin - 1)
					{
						j++;
						labyrinthe[i][j] = LABYRINTHE_VIDE;
					}
				}
			}
		}

		//Prochaine position est au dessus de la position actuel
		else if(prochaine_position == position_actuel - 1)
		{
			//Pour trouver j
			for(c = 0; c < ((LABYRINTHE_NB_COLONNES - 1) / 2) - 1; c++)
			{
				if(position_actuel > (((LABYRINTHE_NB_LIGNES - 1) / 2) * c) && position_actuel <= (((LABYRINTHE_NB_LIGNES - 1) / 2) * (c + 1)))
				{
					j = (c + (c + 1));
				}
			}

			//Pour trouver i
			i = (prochaine_position + position_actuel)%(LABYRINTHE_NB_LIGNES - 1);
			i++;

			labyrinthe[i][j] = LABYRINTHE_VIDE;
			if(k != longueur_chemin - 1)
			{
				i++; 
				labyrinthe[i][j] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est a gauche de la position actuel
		else if(prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES - 1)/2))
		{
			//Pour trouver i
			i = (position_actuel%(((LABYRINTHE_NB_LIGNES - 1)/2) * 2) + 1);

			//Pour trouver j et creuser
			for(c = 0; c < ((LABYRINTHE_NB_COLONNES - 1) / 2) - 1; c++)
			{
				if(position_actuel > (((LABYRINTHE_NB_LIGNES - 1) / 2) * c) && position_actuel <= (((LABYRINTHE_NB_LIGNES - 1) / 2) * (c + 1)))
				{
					j = (c + (c + 1));
					labyrinthe[i][j] = LABYRINTHE_VIDE;
					j--;
					labyrinthe[i][j] = LABYRINTHE_VIDE;
					if(longueur_chemin != 0)
					{
						j--;
						labyrinthe[i][j] = LABYRINTHE_VIDE;
					}
				}
			}
		}
	}
}

void labyrinthe_generer(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	int k;
	int nb_colonnes = ((LABYRINTHE_NB_COLONNES - 1) / 2);
	int nb_lignes = ((LABYRINTHE_NB_LIGNES - 1) / 2);
	int *chemins[] = {NULL};
	int longueurs_chemins;

	labyrinthe_initialiser(labyrinthe);
	labyrinthe[1][1] = LABYRINTHE_VIDE;

	for(k = 0; k < (nb_colonnes * nb_lignes) - 1; k++)
	{
		if(k == LABYRINTHE_MUR)
		{
			ajouter_un_chemin(labyrinthe,chemins,&longueurs_chemins,k);
			labyrinthe_dessiner_chemin(labyrinthe,*chemins,longueurs_chemins);
		}
	}
	ajouter_sortie(labyrinthe);
	labyrinthe[1][1] = LABYRINTHE_ENTREE;
}

int labyrinthe_resoudre(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* solution[], int* longueur_solution)
{
	int i, j, k;
	int depart = 0;
	int *pile_visite[] = {NULL};
	int *voisins[] = {NULL};
	int longueur_visite = 0;

	for(i = 0; i < LABYRINTHE_NB_LIGNES; i++)
	{
		for(j = 0; j < LABYRINTHE_NB_COLONNES; j++)
		{
			if(labyrinthe[i][j] == LABYRINTHE_ENTREE)
			{
				depart = (i/2)+(4*(j/2));
			}
		}
	}
	pile_ajouter(solution, longueur_solution, depart);
	pile_ajouter(pile_visite, &longueur_visite, depart);

	while(longueur_solution > 0 && (*solution)[0] != LABYRINTHE_SORTIE)
	{
		int sortie_trouve = 0;
		obtenir_voisins(labyrinthe, (*solution)[0], *voisins, LABYRINTHE_SORTIE);
		for(k = 0; k < NB_VOISINS - 1; k++)
		{
			if((*voisins)[k] != -1)
			{
				pile_ajouter(solution, longueur_solution, (*voisins)[k]);
				sortie_trouve = 1;
			}
		}
		if(!sortie_trouve)
		{
			int voisin_disponible = 0;

			obtenir_voisins(labyrinthe, (*solution)[0], *voisins, LABYRINTHE_VIDE);

			//comparer a pile_visite
			
			for(k = 0; k < NB_VOISINS; k++)
			{
				if(pile_est_present(*solution, *longueur_solution, (*voisins)[k]) != -1)
				{
					(*voisins)[k] = -1;
				}
			}
			for(k = 0; k < NB_VOISINS; k++)
			{

			}
			for(k = 0; k < NB_VOISINS; k++)
			{
				if((*voisins)[k] != -1)
				{
					voisin_disponible++;
				}
			}		

			//Gestion des voisin commence ici

			pile_ajouter(solution, longueur_solution, (*voisins)[rand() % voisin_disponible]);
			pile_ajouter(pile_visite, &longueur_visite, (*voisins)[rand() % voisin_disponible]);
			
			//si pu de voisin
			if(voisin_disponible == 0)

		}
	}
}

void ajouter_un_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* chemins[], int* longueurs_chemins, int depart)
{
	int position_x;
	int position_y;
	int position_gros_tableau;

	pile_initialiser_version_utile(chemins, longueurs_chemins, 1);
	*chemins[0] = depart;
	
	do
	{
	chemin_aleatoire_ajouter_un_pas(chemins, longueurs_chemins, (LABYRINTHE_NB_LIGNES - 1)/2, (LABYRINTHE_NB_COLONNES - 1)/2);//ajoute un nouveau pas au chemin

	position_x = *chemins[0] / ((LABYRINTHE_NB_LIGNES-1) / 2);	//coordonee en x dans le tableau de 4x4
	position_y = *chemins[0] % ((LABYRINTHE_NB_COLONNES-1) / 2); //coordonee en y dans le tableau de 4x4

	position_x = position_x*2 + 1;	//coordonee en x dans le tableau de 9x9
	position_y = position_y*2 + 1;	//coordonee en y dans le tableau de 9x9

	position_gros_tableau = ((LABYRINTHE_NB_LIGNES*position_x) + position_y);


	}	while (!est_vide(labyrinthe, position_gros_tableau));
	//donne prochaine position à ajouter au chemin, si valide, ajoute, sinon tronque
}

static int obtenir_voisins( int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int no_case, int voisins[NB_VOISINS], int etat)
{
	int x=0;
	int buffer;
	
	if (obtenir_etat(labyrinthe, no_case+1) == etat) //case du bas
		voisins[0] = no_case+1;
	else
		voisins[0] = -1;

	if (obtenir_etat(labyrinthe, no_case-1) == etat) //case du haut
		voisins[1] = no_case-1;
	else
		voisins[1] = -1;

	if (obtenir_etat(labyrinthe, no_case + LABYRINTHE_NB_COLONNES) == etat) //case a droite
		voisins[2] = no_case + LABYRINTHE_NB_COLONNES;
	else
		voisins[2] = -1;

	if (obtenir_etat(labyrinthe, no_case - LABYRINTHE_NB_COLONNES) == etat) //case a gauche
		voisins[3] = no_case - LABYRINTHE_NB_COLONNES;
	else
		voisins[3] = -1;

	while (!(x==4))
	{
		if (voisins[x+1] > voisins[x])
		{
			buffer = voisins[x];
			voisins[x] = voisins[x+1];
			voisins[x+1] = buffer;
			x=0;
		}
		else
			x++;
	}

	//Cette fonction permet d’obtenir le nombre de voisins d’une case du labyrinthe ainsi que leurs indices de position. 
	//Seulement les voisins valides (dans la grille du labyrinthe) et qui ont un état correspondant à celui reçu en paramètre sont retournés dans le tableau voisins. 
}
