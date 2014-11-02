#include "Module_Pile.h"
#include "Labyrinthe.h"

/************************************************************************************************/
/*                                        DEFINITION                                            */
/************************************************************************************************/

void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES])
{
	int i, j;
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

	int i, j;
	int position_actuel = 0;
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
			i++;
			if(type_solution == LABYRINTHE_SOLUTION_TEMPORAIRE)
			{
				labyrinthe[i][j] = LABYRINTHE_SOLUTION_TEMPORAIRE;
				if(k != longueur - 1)
				{
					i++;
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

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin)
{
	int k;

	for(k = 0; k < longueur_chemin; k++)
	{
		int position_actuel = chemin[k];
		int prochaine_position = chemin[k + 1];
		int i, j;

		//Prochaine position est en dessous de la position actuel
		if(prochaine_position == position_actuel + 1)
		{
			i = 0; //Je n'es pas pense au i; encore
			j = prochaine_position + position_actuel;
			j++; //Modification de i++

			labyrinthe[i][j] = LABYRINTHE_VIDE;
			if(k != longueur - 1)
			{
				j++; //Modification de i++
				labyrinthe[i][j] = LABYRINTHE_VIDE;
			}
		}

		//Prochaine position est a droite de la position actuel
		else if(prochaine_position == position_actuel + ((LABYRINTHE_NB_LIGNES -1)/2))
		{
			int i, j, c; //c pour colonne

			for(c = 0; c < LABYRINTHE_NB_COLONNES; c++)
			{
				if(position_actuel > (LABYRINTHE_NB_LIGNES * c) && position_actuel <= (LABYRINTHE_NB_COLONNES * (c + 1))
				{
					i = (c + (c + 1));
					j = 0; //Je n'es pas pense au j encore
					labyrinthe[i][j] = LABYRINTHE_VIDE;
					i++;
					labtrinthe[i][j] = LABYRINTHE_VIDE;
					if(k != longeur_chemin - 1)
					{
						i++;
						labyrinthe[i][j] = LABYRINTHE_VIDE;
					}
				}
			}
		}
		else if(position_actuel == prochaine_position - 1)
		{
			i = 0; //Je n'es pas pense au i; encore
			j = prochaine_position + position_actuel;
			j--; //Modification de i++

			labyrinthe[i][j] = LABYRINTHE_VIDE;
			if(k != longueur - 1)
			{
				j--; //Modification de i++
				labyrinthe[i][j] = LABYRINTHE_VIDE;
			}
		}
	}
}
