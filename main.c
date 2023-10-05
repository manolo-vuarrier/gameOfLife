#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

#define ROWS 50  // Nombre de lignes de la grille
#define COLS 50  // Nombre de colonnes de la grille

// Fonction pour initialiser un planeur dans la grille
void initialiserGlider(int grille[ROWS][COLS], int x, int y) {
    // Coordonnées des cellules vivantes pour le planeur
    int glider[5][2] = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}
    };

    // Initialiser la grille avec des cellules mortes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grille[i][j] = 0;
        }
    }

    // Placer les cellules vivantes du planeur dans la grille
    for (int i = 0; i < 5; i++) {
        int cellX = glider[i][0] + x;
        int cellY = glider[i][1] + y;

        // Assurez-vous que les cellules sont à l'intérieur de la grille
        if (cellX >= 0 && cellX < ROWS && cellY >= 0 && cellY < COLS) {
            grille[cellX][cellY] = 1;
        }
    }
}


// Fonction pour initialiser la grille avec des cellules aléatoires vivantes ou mortes
void initialiserGrille(int grille[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grille[i][j] = rand() % 2;  // 0 pour morte, 1 pour vivante
        }
    }
}

// Fonction pour afficher la grille en console
void afficherGrille(int grille[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grille[i][j] == 1) {
                printf("O");  // Cellule vivante
            } else {
                printf(" ");  // Cellule morte
            }
        }
        printf("\n");
    }
}

// Fonction pour calculer la génération suivante du jeu
void calculerGenerationSuivante(int grille[ROWS][COLS]) {
    int nouvelleGrille[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int voisinsVivants = 0;

            // Parcourir les cellules voisines
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;  // Ignorer la cellule actuelle

                    int voisinX = i + x;
                    int voisinY = j + y;

                    // Gérer les bords avec une grille torique
                    voisinX = (voisinX + ROWS) % ROWS;
                    voisinY = (voisinY + COLS) % COLS;

                    voisinsVivants += grille[voisinX][voisinY];
                }
            }

            // Appliquer les règles du jeu
            if (grille[i][j] == 1) {
                if (voisinsVivants < 2 || voisinsVivants > 3) {
                    nouvelleGrille[i][j] = 0;  // Mort
                } else {
                    nouvelleGrille[i][j] = 1;  // Survit
                }
            } else {
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j] = 1;  // Naissance
                } else {
                    nouvelleGrille[i][j] = 0;  // Reste morte
                }
            }
        }
    }

    // Copier la nouvelle génération dans la grille actuelle
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grille[i][j] = nouvelleGrille[i][j];
        }
    }
}


int main() {
    int grille[ROWS][COLS];

    // Initialiser la grille avec des cellules aléatoires
    initialiserGlider(grille,5,5);
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         grille[i][j] = 0;
    //     }
    // }
    // grille[3][3] = 1;
    // grille[3][4] = 1;
    // grille[3][5] = 1;

    // Afficher la grille initiale
    printf("Génération 0 :\n");
    afficherGrille(grille);

    // Calculer et afficher les générations suivantes
    for (int generation = 1; generation <= 1000; generation++) {
        calculerGenerationSuivante(grille);
        printf("\nGénération %d :\n", generation);
        getchar();
        afficherGrille(grille);
    }

    return 0;
}
