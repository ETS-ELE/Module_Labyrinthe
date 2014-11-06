/************************************************************************************************/
//Projet   : Projet TP_2_Labyrinthe
//Fichier  : Module_Pile.c
//Contenu  : Contient des fonctions qui gere un labyrinthe. Un labyrinthe est represente par une 
//	     tableau 2D qui contient des murs, des passages, un depart et une sortie.
//Objectif : Creation d'un algorithme de realisation de labyrinthe.
//Creation : 27 Octobre 2014
//                                                  Creer par Samuel - Link - Geoffroy-Heroux
//                                                            Francis Masse
//                                                            Christopher Dom
//                                                            Vincent Lynch
//
/************************************************************************************************/

/*                                          DEFINE                                              */
/************************************************************************************************/
#ifndef MOD_LABYRINTHE
#define MOD_LABYRINTHE

// Le nombre de ligne et de colonne du labyrinthe.
#define LABYRINTHE_NB_LIGNES 61
#define LABYRINTHE_NB_COLONNES 49

// L'etat possible des cases du labyrinthe.
#define LABYRINTHE_VIDE 0
#define LABYRINTHE_MUR 1
#define LABYRINTHE_ENTREE 2
#define LABYRINTHE_SORTIE 3
#define LABYRINTHE_SOLUTION 4
#define LABYRINTHE_SOLUTION_TEMPORAIRE 5

// Le nombre de voisins possible.
#define NB_VOISINS 4
/************************************************************************************************/

/*                                         INCLUDES                                             */
/************************************************************************************************/
#include "Aleatoire.h"
#include "Module_Pile.h"
/************************************************************************************************/

/*                                        DECLARATION                                           */
/************************************************************************************************/

void labyrinthe_afficher(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);
/*
LABYRINTHE_AFFICHER
Cette fonction sert a afficher un labyrinte dans la console.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe a afficher.

Return : 	Void.
*/
/************************************************************************************************/

void labyrinthe_convertir_en_image(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], unsigned char image[]);

/************************************************************************************************/

void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);
/*
LABYRINTHE_INITIALISER
Cette fonction sert a initialiser un tableau 2D representant un labyrinthe. Il est initialiser
seulement avec des murs.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.

Return : 	Void.
*/
/************************************************************************************************/

void labyrinthe_generer(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);
/*
LABYRINTHE_GENERER
Cette fonction sert a generer un labyrinthe a l'aide de l'algorithme de Wilson.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.

Return : 	Void.
*/
/************************************************************************************************/

int labyrinthe_resoudre(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* solution[], int* longueur_solution);
/*
LABYRINTHE_RESOUDRE
Cette fonction permet de resoudre un labyrinthe, c'est-a-dire trouver le chemin qui mene de l'entree a la sortie.
Si une solution est trouvae, elle est placee dans la pile recue en parametre et fonction retourne la valeur 1.
S'il n'y a pas de solution, la fonction retourne 0.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
int* solution[]		--> Pile contenant les cases de la solution, de l'entree a la sortie.
int* longueur_solution	--> Adresse de la variable contenant la longeur de la pile solution[].

Return : 	int 1;	--> La fonction a trouver une solution.
int 0; --> La fonction n'a pas trouver de solution.
*/
/************************************************************************************************/

void labyrinthe_dessiner_solution(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int solution[], int longueur, int type_solution);
/*
LABYRINTHE_DESSINER_SOLUTION
Cette procedure dessine une solution sur la grille du labyrinthe. Pour la dessiner,
il suffit de modifier l'etat de chaque case du labyrinthe qui se trouve dans la solution.
Le type de solution peut etre soit SOLUTION_TEMPORAIRE ou SOLUTION_FINALE.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
int* solution[]		--> Pile contenant les cases de la solution, de l'entree a la sortie.
int* longueur_solution	--> Adresse de la variable contenant la longeur de la pile solution[].
int type_solution	--> Variable contenant SOLUTION_TEMPORAIRE ou SOLUTION_FINALE

Return : 	Void
*/
/************************************************************************************************/

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin);
/*
LABYRINTHE_DESSINER_CHEMIN
Cette procedure dessine un chemin (enleve les murs) sur la grille du labyrinthe.
Attention, parce que le chemin est base sur une grille de la moitie de la taille de la grille du labyrinthe,
il faut dessiner les cases du chemin en plus des cases entre les cases du chemin.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
int* chemin[]		--> Pile contenant les cases de la solution a dessiner.
int* longueur_chemin	--> Adresse de la variable contenant la longeur de la pile chemin[].

Return : 	Void.
*/
/************************************************************************************************/

void ajouter_un_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int *chemins[], int* longueurs_chemins, int depart);
/*
LABYRINTHE_AJOUTER_CHEMIN
Cette procedure ajoute un chemin au labyrinthe qui part de la case depart.
Pour generer un chemin, on demarre un nouveau chemin aleatoire a la case depart
puis on lui ajoute des pas jusqu'a ce qu'il touche a un chemin du labyrinthe deja existant.
Le parametre chemins est une pile qui contient tous les chemins du labyrinthe jusqu'a maintenant.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
int* chemin[]		--> Pile contenant les cases d'e la solution'un a dessiner.
int* longueur_chemin	--> Adresse de la variable contenant la longeur de la pile chemin[].
int depart		--> Case depart du nouveau chemin

Return : 	Void.
*/
/************************************************************************************************/

static int obtenir_voisins(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int no_case, int voisins[NB_VOISINS], int etat);
/*
OBTENIR_VOISINS
Cette fonction permet d'obtenir le nombre de voisins d'une case du labyrinthe ainsi que leurs indices de position.
Seulement les voisins valides (dans la grille du labyrinthe) et qui ont un etat correspondant a celui recu
en parametre sont retournes dans le tableau voisins.

Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
int no_case		--> Variable contenant la position que l'on veut regarder les voisins.
int voisins[]		--> Tableau[] contenant les positions des voisins possibles.
Remplace par "-1" si la cases n'est pas un voisin
int etat		--> Type d'etat que doit regarder la fonction : "solution" ou "vide"

Return : 	int nombre de voisins
*/
/************************************************************************************************/
#endif
