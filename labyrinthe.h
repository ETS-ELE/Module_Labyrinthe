/************************************************************************************************/
//Projet   : Projet TP_2_Labyrinthe
//Fichier  : Module_Pile.c
//Contenu  : Contient des fonctions qui gère un labyrinthe. Un labyrinthe est represente par une 
//	     tableau 2D qui contient des murs, des passages, un départ et une sortie.
//Objectif : Création d'un algorithme de réalisation de labyrinthe.
//Création : 27 Octobre 2014
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

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe à afficher.

	Return : 	Void.
*/
/************************************************************************************************/

void labyrinthe_convertir_en_image(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], unsigned char image[]);

/************************************************************************************************/

void labyrinthe_initialiser(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);
/* 
LABYRINTHE_INITIALISER
	Cette fonction sert a initialiser un tableau 2D représentant un labyrinthe. Il est initialiser
		seulement avec des murs.

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.

	Return : 	Void.
*/
/************************************************************************************************/

void labyrinthe_generer(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES]);
/* 
LABYRINTHE_GENERER
	Cette fonction sert a generer un labyrinthe à l'aide de l'algorithme de Wilson.

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.

	Return : 	Void.
*/
/************************************************************************************************/

int labyrinthe_resoudre(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int* solution[], int* longueur_solution);
/* 
LABYRINTHE_RESOUDRE
	Cette fonction permet de résoudre un labyrinthe, c’est-à-dire trouver le chemin qui mène de l’entrée à la sortie. 
	Si une solution est trouvée, elle est placée dans la pile reçue en paramètre et fonction retourne la valeur 1. 
	S’il n’y a pas de solution, la fonction retourne 0.

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
			int* solution[]		--> Pile contenant les cases de la solution, de l'entrée à la sortie.
			int* longueur_solution	--> Adresse de la variable contenant la longeur de la pile solution[].

	Return : 	int 1;	--> La fonction à trouver une solution.
			int 0; --> La fonction n'a pas trouver de solution.
*/
/************************************************************************************************/

void labyrinthe_dessiner_solution(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int solution[], int longueur, int type_solution);
/* 
LABYRINTHE_DESSINER_SOLUTION
	Cette procédure dessine une solution sur la grille du labyrinthe. Pour la dessiner, 
	il suffit de modifier l’état de chaque case du labyrinthe qui se trouve dans la solution. 
	Le type de solution peut être soit SOLUTION_TEMPORAIRE ou SOLUTION_FINALE.

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
			int* solution[]		--> Pile contenant les cases de la solution, de l'entrée à la sortie.
			int* longueur_solution	--> Adresse de la variable contenant la longeur de la pile solution[].
			int type_solution	--> Variable contenant SOLUTION_TEMPORAIRE ou SOLUTION_FINALE

	Return : 	Void
*/
/************************************************************************************************/

void labyrinthe_dessiner_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int chemin[], int longueur_chemin);
/* 
LABYRINTHE_DESSINER_CHEMIN
	Cette procédure dessine un chemin (enlève les murs) sur la grille du labyrinthe. 
	Attention, parce que le chemin est basé sur une grille de la moitié de la taille de la grille du labyrinthe, 
	il faut dessiner les cases du chemin en plus des cases entre les cases du chemin.

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
			int* chemin[]		--> Pile contenant les cases d'e la solution'un à dessiner.
			int* longueur_chemin	--> Adresse de la variable contenant la longeur de la pile chemin[].

	Return : 	Void.
*/
/************************************************************************************************/

void ajouter_un_chemin(int labyrinthe[LABYRINTHE_NB_LIGNES][LABYRINTHE_NB_COLONNES], int *chemins[], int* longueurs_chemins, int depart);
/* 
LABYRINTHE_AJOUTER_CHEMIN
	Cette procédure ajoute un chemin au labyrinthe qui part de la case départ. 
	Pour générer un chemin, on démarre un nouveau chemin aléatoire à la case départ 
	puis on lui ajoute des pas jusqu’à ce qu’il touche à un chemin du labyrinthe déjà existant. 
	Le paramètre chemins est une pile qui contient tous les chemins du labyrinthe jusqu’à maintenant. 

	Parametre : 	int labyrinthe[][]	--> Tableau contenant le labyrinthe.
			int* chemin[]		--> Pile contenant les cases d'e la solution'un à dessiner.
			int* longueur_chemin	--> Adresse de la variable contenant la longeur de la pile chemin[].
			int depart		--> Case départ du nouveau chemin

	Return : 	Void.
*/
/************************************************************************************************/
#endif
