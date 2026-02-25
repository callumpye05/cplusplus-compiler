# Compilateur AlgoToCpp 

Ce projet est un compilateur fonctionnel capable de traduire un langage algorithmique personnalisé (proche du pseudo-code français) en code C++ standard et exécutable. 

Il a été conçu pour automatiser la transition entre la conception algorithmique et la mise en œuvre technique, tout en garantissant la sécurité mémoire et la cohérence des types.

---

## Architecture Technique

Le compilateur utilise une chaîne de traitement standard de l'industrie :

1.  **Analyse Lexicale (Flex) :** Découpe le code source en jetons(tokens).
2.  **Analyse Syntaxique (Bison) :** Construit un Arbre de Syntaxe Abstraite(AST) à partir d'une grammaire formelle.
3.  **Analyse Sémantique :** Inférence de types et vérification des portées(scopes) des variables.
4.  **Génération de Code :** Traduction de l'AST en code C++ structuré.



---

## Fonctionnalités Principales

* **Gestion des Types :** Support des entiers, réels, chaînes de caractères et tableaux multidimensionnels.
* **Inférence de Type Intelligente :** Le compilateur choisit automatiquement les méthodes C++ appropriées (ex: `.size()` pour les vecteurs vs `.length()` pour les strings).
* **Structures de Contrôle :** Support complet des boucles `TANT QUE`, `POUR`, `POUR TOUT` et des conditions `SI / SINONSI / SINON`.
* **Fonctions & Procédures :** Gestion des paramètres, des variables locales et des valeurs de retour.
* **Sécurité des Tableaux :** Implémentation de "Bounds Checking" (vérification des bornes) via des expressions Lambda C++ pour éviter les erreurs de segmentation.

---

## Compatibilité

| Système | État | Notes |
| :--- | :--- | :--- |
| **Linux** |  Compatible | Environnement de développement natif. |
| **macOS** |  Compatible | Testé avec Clang (requiert C++11 et Bison/Flex via Homebrew). |
| **Windows** | Partiel | Fonctionne parfaitement via **WSL** (Ubuntu) ou **MSYS2**. |

---

## Installation et Utilisation

### Prérequis
* G++ (support C++11 minimum)
* Flex
* Bison

### Compilation du projet et utilisation d'un code
```bash
make clean && make

./algo mon_fichier.algo output.cpp

g++ output.cpp -o mon_programme
./mon_programme



