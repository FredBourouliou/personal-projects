#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inclusion des fichiers d'en-tête
#include "line1_library.h"
#include "line2_library.h"
#include "line3_library.h"

// Fonction pour sélectionner aléatoirement une ligne de 5 syllabes pour le premier vers
const char* get_random_line1() {
    int index = rand() % SIZE_LINES_5_SYLLABLES_LINE1;
    return LINES_5_SYLLABLES_LINE1[index];
}

// Fonction pour sélectionner aléatoirement une ligne de 7 syllabes pour le deuxième vers
const char* get_random_line2() {
    int index = rand() % SIZE_LINES_7_SYLLABLES_LINE2;
    return LINES_7_SYLLABLES_LINE2[index];
}

// Fonction pour sélectionner aléatoirement une ligne de 5 syllabes pour le troisième vers
const char* get_random_line3() {
    int index = rand() % SIZE_LINES_5_SYLLABLES_LINE3;
    return LINES_5_SYLLABLES_LINE3[index];
}

// Fonction pour jouer la musique
void play_music() {
    #ifdef __APPLE__
        system("afplay musique.mp3 &"); // macOS
    #elif _WIN32
        system("start wmplayer musique.mp3"); // Windows
    #elif __linux__
        system("xdg-open musique.mp3 &"); // Linux
    #endif
}

// Fonction pour générer et afficher un haïku
void generate_haiku() {
    play_music(); // Lance la musique en premier
    printf("%s\n", get_random_line1()); // Premier vers (5 syllabes)
    printf("%s\n", get_random_line2()); // Deuxième vers (7 syllabes)
    printf("%s\n", get_random_line3()); // Troisième vers (5 syllabes)
}

int main() {
    // Initialisation de la génération de nombres aléatoires
    srand(time(NULL));

    printf("Voici votre haïku :\n\n");
    generate_haiku();

    return 0;
}
