# Jeu Wordbrain

```
28 janvier 2018 SECK Malick
```
## OBJECTIFS

Le but du projet est de réaliser un programme permettant de générer des grilles de
mots pouvant être utilisés pour le jeu wordbrain.
Les grilles doivent avoir une taille comprise entre 3x3 et 10x10 et contenir des mots
issus du dictionnaire de mots fournis par linux, donc en anglais.

## I°) Etapes de réalisation du programme

Tout d’abord j’ai commencé par filtrer mon dictionnaire de mots en enlevant par
exemple les mots contenant moins de 3 lettres ou avec des caractères spéciaux,
pouvant causer de problèmes d’affichage par la suite.
Après cela j’ai passé un peu de temps à me renseigner sur les méthodes de
prototypage et d’appel de foncions en dehors du main. J’ai tenu à passer du
temps sur cette étape afin d’éviter d’avoir un programme long et
incompréhensible.
Ainsi, en dehors de la déclaration de variables et l’utilisation de quelques fonctions
basiques, mon programme est divisé en 3 principales fonctions que j’ai moi-même
crée :

```
▪ chercherTaille
```
Qui est une fonction qui génère une suite de nombres correspondant à la taille des
mots à aller chercher dans le dictionnaire. La somme de ces nombres doit être
égale au nombre de lettres nécessaires pour remplir chaque grille.

# WORDBRAIN


```
▪ trouverMotHasard
```
Cette fonction a pour unique objectif d’aller chercher des mots au hasard dans le
dictionnaire et des vérifier leurs tailles conformément aux valeurs qui lui sont
transmises par la fonction précédente.

```
▪ genererGrilles
```
Comme l’indique son nom, cette fonction permet des générer aléatoirement des
grilles de mots en tenant compte des fonctions chercherTaille et trouverMotHasard.
De plus, la fonction génère l’écriture des grilles dans un fichier texte, conformément
au cahier des charges.

## II°) Difficultés et manquements

L’une des difficultés récurrente que j’ai rencontrées se rapporte à la syntaxe du
langage C. J’ai donc eu beaucoup d’erreurs à la compilation à cause d’une
mauvaise déclaration ou d’un type inapproprié de mes variables.
En fin de compte, la programme est fonctionnel et rempli selon moi toutes les
parties du cahier des charges imposé. Cependant, étant donné que je n’arrivai pas
à passer en paramètre à une fonction un tableau de caractère, j’ai décidé de
déclarer mes tableaux à la fois dans la main et dans mon prototype de fonction.
Ainsi, vu que le contenu de la mémoire est le même, j’arrive à simuler un renvoie de
valeur juste grâce à une double déclaration.
Un gros problème que j’ai rencontré est que les grilles qui sont générées sont parfois
identiques. J’ai passé plusieurs heures à essayer de résoudre ce problème, mais
faute de temps j’ai fini par abdiquer.
De plus, je n’ai pas tenu compte du mécanisme du chute étant donné que mes
mots sont tirés au hasard ainsi que leur taille.


## III°) Conclusion sur le projet

En somme, je trouve que ce projet est très intéressant car m’a permis de mettre en
commun mes connaissances minimes en programmation. De plus, cela me permet
pour une fois d’aller chercher moi-même les solutions à mes problèmes sans
forcément avoir tout le temps besoin du professeur à mes côtés.
Je trouve dommage de ne pas avoir suffisamment de temps pour perfectionner
mon programme. Cependant, j’essaierai de l’améliorer en dehors du cadre
pédagogique pour mon propre apprentissage. Car la meilleure façon d’apprendre
à programmer est justement de programmer.


