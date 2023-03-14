# Tic Tac Toes AI Minimax

Écrit en c++ ce projet utilise une méthode de recherche de l'arbre de jeu appelée algorithme Minimax.
En jouant toute les possibilitée de jeux à chaque tour l'ordinateur est capable de trouver la meilleur solution pour gagner ou pour au moins faire match nul.

## Explication du code

Le code est composé de plusieurs fonctions :

- `init()`

Cette fonction ne sert à rien dans le programme et ne renvoie qu'un zéro.

- `affichage(int grille)`
Cette fonction affiche la grille du jeu en utilisant une variable grille qui est un nombre binaire de 18 bits. Chaque case de la grille est représentée par deux bits qui peuvent avoir les valeurs 00, 01, 10 ou 11. Les deux premiers bits représentent le symbole dans la case, les deux derniers bits sont réservés à une éventuelle utilisation future.

- `verif(int grille)`
Cette fonction vérifie si la grille est encore remplissable en regardant chaque case. Si une case est vide, la fonction renvoie un 0, sinon elle renvoie un 1.

- `valid(int grille, int coup)`
Cette fonction vérifie si le coup est jouable en regardant la case correspondante dans la grille. Si la case est vide, la fonction renvoie un 1, sinon elle renvoie un 0.

- `jeu(int grille, int coup, int joueur)`
Cette fonction modifie la grille en plaçant un pion dans la case correspondante. Elle utilise la variable joueur pour déterminer quel symbole placer dans la case.

- `win(int grille)`
Cette fonction vérifie si un joueur a gagné en regardant toutes les combinaisons possibles de trois cases alignées. Si le joueur X gagne, la fonction renvoie un -1, si le joueur O gagne, la fonction renvoie un 1. Si personne n'a gagné, la fonction renvoie un 0.

- `minmaxAlt(int grille, int tour)`
Cette fonction est l'algorithme Minimax utilisé pour déterminer le meilleur coup à jouer pour l'ordinateur. Elle utilise une variable tour pour déterminer si c'est le tour de l'ordinateur ou du joueur. La fonction utilise une approche récursive pour explorer l'arbre de jeu en utilisant une fonction minmaxDebut().

- `minmaxDebut(int grille)`
Cette fonction utilise l'algorithme Minimax pour déterminer le meilleur coup à jouer pour l'ordinateur en explorant tous les coups possibles et en évaluant leur score à l'aide de la fonction minmaxAlt().

## Conclusion

Ce programme de Tic Tac Toe utilise une méthode de recherche de l'arbre de jeu appelée algorithme Minimax pour déterminer le meilleur coup à jouer pour l'ordinateur. Le programme est écrit en C et utilise plusieurs fonctions pour gérer la grille, les coups et les scores. Le résultat est un jeu de Tic Tac Toe jouable contre l'ordinateur.

## Installation

Pour installer le projet il suffit de cloner le projet et de lancer `tictactoe.exe`

## Utilisation

Pour jouer il suffit de lancer le programme et de suivre les instructions.
