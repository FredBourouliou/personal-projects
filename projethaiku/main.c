#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Inclusion des fichiers d'en-tête
#include "line1_library.h"
#include "line2_library.h"
#include "line3_library.h"

#define MAX_HAIKU_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define CLEAR_SCREEN "\033[2J\033[H"

// Structure pour stocker un haïku
typedef struct {
    const char* line1;
    const char* line2;
    const char* line3;
} Haiku;

// Fonction pour effacer l'écran
void clear_screen() {
    printf(CLEAR_SCREEN);
}

// Fonction pour vérifier si un fichier existe
bool file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

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

// Fonction pour jouer la musique avec gestion d'erreurs
bool play_music() {
    if (!file_exists("musique.mp3")) {
        printf("Erreur : Le fichier musique.mp3 n'a pas été trouvé.\n");
        return false;
    }

    #ifdef __APPLE__
        return system("afplay musique.mp3 &") == 0;
    #elif _WIN32
        return system("start wmplayer musique.mp3") == 0;
    #elif __linux__
        return system("xdg-open musique.mp3 &") == 0;
    #else
        printf("Système d'exploitation non supporté pour la lecture audio.\n");
        return false;
    #endif
}

// Fonction pour arrêter la musique
void stop_music() {
    #ifdef __APPLE__
        system("killall afplay 2>/dev/null");
    #elif _WIN32
        system("taskkill /IM wmplayer.exe /F 2>nul");
    #elif __linux__
        system("killall -q mpv vlc 2>/dev/null");
    #endif
}

// Fonction pour sauvegarder un haïku dans un fichier
bool save_haiku(const Haiku* haiku, const char* filename) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", filename);
        return false;
    }

    fprintf(file, "\n=== Haïku généré le %s ===\n", __DATE__);
    fprintf(file, "%s\n%s\n%s\n", haiku->line1, haiku->line2, haiku->line3);
    fprintf(file, "===========================\n");

    fclose(file);
    return true;
}

// Fonction pour générer un haïku
Haiku generate_haiku() {
    Haiku haiku = {
        .line1 = get_random_line1(),
        .line2 = get_random_line2(),
        .line3 = get_random_line3()
    };
    return haiku;
}

// Fonction pour afficher un haïku avec style
void display_haiku(const Haiku* haiku) {
    printf("\n\033[1;36m╔════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[0m      \033[1;33mHAÏKU\033[0m         \033[1;36m║\033[0m\n");
    printf("\033[1;36m╠════════════════════════╣\033[0m\n");
    printf("\033[1;36m║\033[0m \033[1;37m%-20s\033[0m \033[1;36m║\033[0m\n", haiku->line1);
    printf("\033[1;36m║\033[0m \033[1;37m%-20s\033[0m \033[1;36m║\033[0m\n", haiku->line2);
    printf("\033[1;36m║\033[0m \033[1;37m%-20s\033[0m \033[1;36m║\033[0m\n", haiku->line3);
    printf("\033[1;36m╚════════════════════════╝\033[0m\n\n");
}

// Fonction pour afficher le menu
void display_menu() {
    printf("\033[1;35m=== Menu du Générateur de Haïku ===\033[0m\n");
    printf("1. Générer un nouveau haïku\n");
    printf("2. Générer plusieurs haïkus\n");
    printf("3. Activer/Désactiver la musique\n");
    printf("4. Sauvegarder le dernier haïku\n");
    printf("5. Quitter\n");
    printf("\nVotre choix : ");
}

int main() {
    // Initialisation
    srand(time(NULL));
    bool music_enabled = true;
    int choice;
    Haiku current_haiku;
    bool haiku_generated = false;

    while (1) {
        clear_screen();
        display_menu();
        scanf("%d", &choice);
        getchar(); // Pour consommer le retour à la ligne

        switch (choice) {
            case 1: {
                clear_screen();
                if (music_enabled) {
                    stop_music();
                    play_music();
                }
                current_haiku = generate_haiku();
                display_haiku(&current_haiku);
                haiku_generated = true;
                printf("Appuyez sur Entrée pour continuer...");
                getchar();
                break;
            }
            case 2: {
                clear_screen();
                int count;
                printf("Combien de haïkus voulez-vous générer ? ");
                scanf("%d", &count);
                getchar();
                
                for (int i = 0; i < count; i++) {
                    current_haiku = generate_haiku();
                    display_haiku(&current_haiku);
                    if (i < count - 1) {
                        printf("Appuyez sur Entrée pour le suivant...");
                        getchar();
                        clear_screen();
                    }
                }
                haiku_generated = true;
                printf("Appuyez sur Entrée pour continuer...");
                getchar();
                break;
            }
            case 3: {
                music_enabled = !music_enabled;
                if (!music_enabled) {
                    stop_music();
                    printf("Musique désactivée.\n");
                } else {
                    printf("Musique activée.\n");
                }
                sleep(1);
                break;
            }
            case 4: {
                if (!haiku_generated) {
                    printf("Aucun haïku n'a encore été généré.\n");
                    sleep(2);
                    break;
                }
                char filename[MAX_FILENAME_LENGTH] = "haikus.txt";
                if (save_haiku(&current_haiku, filename)) {
                    printf("Haïku sauvegardé dans %s\n", filename);
                }
                sleep(2);
                break;
            }
            case 5: {
                stop_music();
                printf("Au revoir !\n");
                return 0;
            }
            default: {
                printf("Choix invalide. Veuillez réessayer.\n");
                sleep(1);
                break;
            }
        }
    }

    return 0;
}
