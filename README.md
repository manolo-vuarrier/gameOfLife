**Laboratoire : Implémentation du Jeu de la Vie en C**

**Objectif** :
L'objectif de ce laboratoire est de concevoir et de mettre en œuvre une version du Jeu de la Vie de Conway en langage C. Le jeu de la vie est un automate cellulaire où chaque cellule peut être dans un état "vivant" ou "mort", et l'évolution des cellules est déterminée par des règles simples.

**Règles du Jeu de la Vie** :
1. Toute cellule vivante avec moins de 2 voisins vivants meurt (sous-population).
2. Toute cellule vivante avec 2 ou 3 voisins vivants survit.
3. Toute cellule vivante avec plus de 3 voisins vivants meurt (surpopulation).
4. Toute cellule morte avec exactement 3 voisins vivants devient une cellule vivante par reproduction.

**Tâches** :

1. Créez un programme en langage C qui permet à l'utilisateur de spécifier la taille d'une grille (par exemple, 10x10) et d'initialiser l'état initial des cellules (vivant/mort) de manière aléatoire.

2. Implémentez une fonction pour afficher l'état actuel de la grille en utilisant la console. Par exemple, utilisez des caractères 'O' pour représenter les cellules vivantes et des espaces pour les cellules mortes.

3. Implémentez une fonction pour calculer la génération suivante en appliquant les règles du Jeu de la Vie à la grille actuelle.

4. Créez une boucle pour itérer sur plusieurs générations (par exemple, 10 générations) et afficher la grille après chaque génération.

5. Assurez-vous que votre programme gère correctement les bords de la grille (en utilisant par exemple une grille torique).

**Consignes** :

1. Utilisez des tableaux multidimensionnels pour représenter la grille du jeu.

2. Organisez votre code en fonctions pour rendre le code plus modulaire et facile à comprendre.

3. Commentez votre code pour expliquer la logique derrière chaque fonction et section de code.

4. Testez votre programme avec différentes tailles de grilles et observez son évolution au fil des générations.

**Exemple d'affichage en console** :
Supposons que l'utilisateur spécifie une grille de 5x5 avec des cellules initiales aléatoires. Voici à quoi pourrait ressembler un exemple d'affichage en console :

```
Génération 0 :
  O O   O  
  O O   O  
  O O O O 
  O     O  
    O O    
  
Génération 1 :
  O O O O  
  O   O    
  O       O
  O     O  
    O O    
  
Génération 2 :
  O O   O  
  O       O
  O       O
  O     O  
    O O    
  
...
```
***
**Gestion des bords**
La gestion des bords dans le Jeu de la Vie est importante car les cellules aux bords de la grille n'ont pas le même nombre de voisins que celles à l'intérieur de la grille. Voici quelques approches courantes pour gérer les bords du jeu :

1. **Grille torique (ou "grille cyclique")** :
   - Dans cette approche, les bords de la grille sont connectés les uns aux autres de manière cyclique, ce qui signifie que la cellule la plus à droite est voisine de la cellule la plus à gauche et que la cellule en bas est voisine de la cellule en haut.
   - Cette méthode permet de simuler un univers infini sans bords, mais elle peut nécessiter des calculs de modulo pour gérer les indices des cellules.

2. **Bords constants (ou "bords solides")** :
   - Dans cette approche, les cellules aux bords de la grille sont considérées comme mortes (ou vivantes) en permanence, ce qui signifie qu'elles ne changent jamais d'état, peu importe ce qui se passe autour d'elles.
   - Cette méthode simplifie le code, mais elle peut affecter la dynamique du jeu près des bords.

3. **Réflexion (ou "bords réfléchissants")** :
   - Les cellules aux bords de la grille se comportent comme si elles étaient reflétées, c'est-à-dire que les cellules au-delà des bords sont traitées comme des voisins réfléchis des cellules aux bords.
   - Par exemple, si une cellule à un coin de la grille a un voisin en dehors de la grille, ce voisin est traité comme un voisin réfléchi. Cela permet de simuler un effet miroir.

4. **Extension de la grille** :
   - Une autre approche consiste à créer une grille plus grande que celle spécifiée par l'utilisateur, de manière à ce que les bords soient entourés de cellules mortes. Ainsi, les cellules aux bords ont toujours le nombre correct de voisins.
   - Cette méthode peut être inefficace en termes de mémoire si la grille est très grande, mais elle simplifie le traitement des cellules aux bords.

Le choix de la méthode de gestion des bords dépend souvent de la nature du problème que vous souhaitez résoudre et de vos préférences en matière de programmation. Certaines méthodes sont plus simples à implémenter que d'autres, mais elles peuvent influencer le comportement global du jeu. Il est important de choisir celle qui convient le mieux à votre cas d'utilisation spécifique.
