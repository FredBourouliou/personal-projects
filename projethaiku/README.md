# Générateur de Haïku

Un générateur de haïku en ligne de commande, avec accompagnement musical et affichage coloré.

Auteur : Frédéric Bourouliou

## Description

Ce programme génère des haïkus aléatoires en français, accompagnés d'une musique d'ambiance pour une expérience immersive. Chaque haïku suit le schéma traditionnel de 5-7-5 syllabes et est affiché dans un cadre stylisé avec des couleurs.

## Fonctionnalités

- 🎵 Accompagnement musical
- 🎨 Interface terminal en couleur
- 📝 Génération unique ou multiple de haïkus
- 💾 Sauvegarde des haïkus générés
- 🔊 Activation/Désactivation de la musique
- 🖼️ Affichage dans un cadre ASCII stylisé

## Aperçu Technique

```
┌─────────────────────────────────────────┐
│           Structure du Programme        │
└─────────────────────────────────────────┘
                    │
        ┌──────────┴──────────┐
        │                     │
   ┌────▼─────┐         ┌────▼─────┐
   │Bibliothè-│         │Programme │
   │ques      │         │Principal │
   └────┬─────┘         └────┬─────┘
        │               ┌────▼─────┐
  ┌─────┴──────┐       │Interface │
  │            │       │  Menu    │
┌─▼─┐    ┌─────▼─┐    └────┬─────┘
│L1 │    │  L2   │         │
└─┬─┘    └───┬───┘    ┌────▼─────┐
  │      ┌───▼───┐    │Fonctions │
  │      │  L3   │    └────┬─────┘
  │      └───┬───┘         │
  └──────────┴─────────────┘
```

## Structure du Projet

- `main.c` - Logique principale et interface utilisateur
- `line1_library.h` - Base de données pour la première ligne (5 syllabes)
- `line2_library.h` - Base de données pour la deuxième ligne (7 syllabes)
- `line3_library.h` - Base de données pour la troisième ligne (5 syllabes)
- `musique.mp3` - Fichier de musique d'ambiance
- `haiku_generator` - Exécutable compilé

## Installation

1. Clonez le dépôt
2. Assurez-vous d'avoir un compilateur C installé (gcc recommandé)
3. Compilez le programme :
   ```bash
   gcc main.c -o haiku_generator
   ```

## Utilisation

Lancez le programme :
```bash
./haiku_generator
```

Le menu interactif permet de :
1. Générer un nouveau haïku
2. Générer plusieurs haïkus
3. Activer/désactiver la musique
4. Sauvegarder les haïkus dans un fichier
5. Quitter le programme

## Détails Techniques

- Écrit en C
- Utilise les codes d'échappement ANSI pour les couleurs
- Support audio multi-plateforme (macOS, Windows, Linux)
- Conception modulaire avec bibliothèques séparées
- Gestion des erreurs pour les opérations fichiers et audio

## Prérequis

- Compilateur C (gcc recommandé)
- Terminal avec support des couleurs ANSI
- Capacité de lecture audio
- Espace disque disponible pour la sauvegarde

## Licence

Ce projet est open source et disponible sous la licence MIT.

## Contribution

N'hésitez pas à soumettre des problèmes et des demandes d'amélioration !
