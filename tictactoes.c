#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<unistd.h>

const int combinaisonX[] = {0b010000000100000001,0b000001000100010000,0b010101000000000000,
	0b000000010101000000,0b000000000000010101,0b010000010000010000,0b000100000100000100,0b000001000001000001};
const int combinaisonO[] = {0b100000001000000010,0b000010001000100000,0b101010000000000000,
	0b000000101010000000,0b000000000000101010,0b100000100000100000,0b001000001000001000,0b000010000010000010};
const int scoreO = 1;
const int scoreX = -1;
const int ORDI = 1;
const int HUMAIN = 2;
int compteurMinmax = 0;

int init() {
	return 0;
	}

// affiche la grille
void affichage(int grille) {
	int and;
	for (int i=0 ; i<9 ; i++) {
		and = grille & 3;
		if (and == 0) {
			printf("_ ");
		}
		else if (and == 1) {
			printf("X ");
		}
		else if (and == 2) {
			printf("O ");
		}
		else if (and == 3) {
			printf("E ");
		}
		if ((i == 2) || (i == 5) || (i == 8)) {
			printf("\n");
		}
		grille = grille>>2;
	}
	printf("\n");
}

// verifie si la grille est encore remplissable
int verif(int grille) {
	for (int i=0 ; i<9 ; i++) {
		if ((grille & 3) == 0) {
			return 0;// on peut encore jouer
		}
		grille = grille>>2;
	}
	return 1;// on ne peut plus jouer la grille est remplie
}

// verifie si le coup est jouable
int valid(int grille,int coup) {
	grille = grille>>(coup+coup);
	if ((grille & 3) == 0) {
		return 1;// la case n'a pas été joue
	}
	return 0;// la case à deja été joue
}

// modifie la gille en plaçant un pion
int jeu(int grille,int coup,int joueur) {
	int pion;
	if (joueur == HUMAIN) {
		pion = 1;
	}
	else {
		pion = 2;
	}
	grille = ((grille) | (pion<<(coup+coup)));
	return grille;
}

// regarde si dans la grille il y a un gagnant
int win(int grille) {
	for (int i=0 ; i<8 ; i++) {
		if ((combinaisonX[i] & grille) == combinaisonX[i]) {
			return scoreX;// renvoi -1
			}
		else if ((combinaisonO[i] & grille) == combinaisonO[i]) {
			return scoreO;// renvoi 1,
			}
	}
	return 0;
}

// renvoie un score
int minmaxAlt(int grille,int tour) {
	compteurMinmax ++;
	int minmax = 0;
	if (verif(grille) == 1) {
		minmax = win(grille);
		return minmax;
	}
	int resultat = win(grille);
	if ((resultat == scoreX) || (resultat == scoreO)) {
		return resultat;
	}
	// tour de l'ordi, max
	if (tour == ORDI) {
		minmax = -10000;
		for (int i = 0 ; i<9 ; i++) {
			if (valid(grille,i)==1) {
				int grilleCopie = jeu(grille,i,tour);
				int scoreTemp = minmaxAlt(grilleCopie,HUMAIN);
				if (minmax <= scoreTemp) minmax = scoreTemp;
			}
		}
		return minmax;
	}
	// tour du joueur, min
	else {
		minmax = 10000;
		for (int i = 0 ; i<9 ; i++) {
			if (valid(grille,i)==1) {
				int grilleCopie = jeu(grille,i,tour);
				int scoreTemp = minmaxAlt(grilleCopie,ORDI);
				if (minmax >= scoreTemp) minmax = scoreTemp;
			}
		}
		return minmax;
	}
}

// renvoie un coup
int minmaxDebut(int grille) {
	int maxScore = -10000;
	int meilleurCoup;
	int valeur;
	int grilleCopie;
	for (int coup=0 ; coup<9 ; coup++) {
		grilleCopie = jeu(grille,coup,1);
		valeur = minmaxAlt(grilleCopie,HUMAIN);
		if (valeur > maxScore) {
			maxScore = valeur;
			meilleurCoup  = coup;
		}
	}
	return meilleurCoup;
}

// l'ordi joue la premiere case vide
int debile(int grille) {
	int j1;
	for (int i = 0 ; i<9 ; i++) {
		if (valid(grille,i)==1) {
			j1 = i;
			break;
			}
	}
	return j1;
}

int ordi(int grille) {
	// int j1 = debile(grille);
	int coup;
	coup = minmaxDebut(grille);
	affichage(grille);
	grille = jeu(grille,coup,1);
	printf("voici le minmax : %d\n",compteurMinmax);// on affiche le compteur de minmax aha <<-- voici le minmax
	return grille;
}

int main () {
	int grille;
	grille = init();
	while (1) {
		affichage(grille);
		int j2;
		int joueur = HUMAIN;
		printf("entrez votre case entre 0 et 8: ");
		scanf("%d", &j2);
		while (valid(grille,j2) == 0) {
			printf("la case est deja joue \nentrez une autre case entre 0 et 8: ");
			scanf("%d", &j2);
		}
		grille = jeu(grille,j2,joueur);
		joueur = ORDI;
		if (win(grille) == scoreX) {
			printf("le joueur a gagne\n");
			affichage(grille);
			return 0;
		}
		if ((verif(grille)==1) && (win(grille)==0)) {
			printf("egalite");
			affichage(grille);
			return 0;
		}
		grille = ordi(grille);
		if (win(grille) == scoreO) {
			printf("l'IA a gagne\n");
			affichage(grille);
			return 0;
		}
		if ((verif(grille)==1) && (win(grille)==0)) {
			printf("egalite");
			affichage(grille);
			return 0;
		}
	}
   return 0;
}
