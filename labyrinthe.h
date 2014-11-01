/*  LABYRINTHE.H
	Contient des sous-programmes qui gere un labyrinthe. Un labyrinthe 
	est represente par une grille qui contient des murs, des espaces vides,
	un point de depart et un point de sortie.

	Liste des sous-programmes:
		labyrinthe_initialiser: Rempli le labyrinthe de murs.

	Samuel Deslauriers-Gauthier
	6 octobre 2014
*/

// Le nombre de ligne et de colonne du labyrinthe.
#define LABYRINTHE_NB_LIGNES 9
#define LABYRINTHE_NB_COLONNES 9

// L'etat possible des cases du labyrinthe.
#define LABYRINTHE_VIDE 0
#define LABYRINTHE_MUR 1
#define LABYRINTHE_ENTREE 2
#define LABYRINTHE_SORTIE 3
#define LABYRINTHE_SOLUTION 4
#define LABYRINTHE_SOLUTION_TEMPORAIRE 5

// Le nombre de voisins possible.
#define NB_VOISINS 4

/*  LABYRINTHE_AFFICHER
	Affiche un labyrinthe dans la console.

	Parametre:
		labyrinthe: Un tableau d'entiers qui represente le labyrinthe.

	Retour: Aucun.
*/
void labyrinthe_afficher(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);


void labyrinthe_convertir_en_image(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], unsigned char image[]);

/*  LABYRINTHE_INITIALISER
	Initialiser une grille qui represente un labyrinthe. Un labyrinthe
	initialise ne contient que des murs.

	Parametre:
		labyrinthe: Un tableau d'entiers qui represente le labyrinthe
			a initialiser.

	Retour: Aucun.
*/
void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);

/*  LABYRINTHE_GENERER
	Genere un labyrinthe e l'aide de l'algorithme de Wilson. 

	Parametre:
		labyrinthe: Le tableau qui contiendra le labyrinthe.

	Retour: Aucun.
*/
void labyrinthe_generer(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);



int labyrinthe_resoudre(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* solution[], int* longueur_solution);


void labyrinthe_dessiner_solution(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int solution[], int longueur, int type_solution);

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin);
