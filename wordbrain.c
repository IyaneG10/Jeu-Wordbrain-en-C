#include <stdio.h>
#include <string.h>
#include <time.h>   // pour rand
#include <stdlib.h>
#include <stdbool.h>

int chercherTaille(int taille_grille, int tab_taille[])

{
	int i=0, nombre_mots=0;
	int taille=0;
	int reste = taille_grille * taille_grille;
	srand(time(NULL)); // Initialisation de la donnée seed
	while(reste > 2)
	{
		taille = (rand() % ( 6 + 1 - 3)) + 3;
		if(taille <= reste)
		{	
				reste= reste - taille;
				tab_taille[i]=taille;
				i=i+1;
				nombre_mots=nombre_mots + 1;
		}
	}
	i=0;
	if(reste>0)
	{
		
		while((reste+tab_taille[i]) > 7)
		{
			i=i+1;
		}
		tab_taille[i]+=reste;
	}
	return nombre_mots;
}


void  trouverMotHasard(int nombreMotsFichier,int tailleaTrouver, char dictionnaire [15100] [100], char motLigne [100])
{

	int tailleMot=0, numLigne=0;
		do
			{
				numLigne = (rand() % (nombreMotsFichier + 1 - 1)) + 1;
				strncpy(motLigne,dictionnaire[numLigne -1],100);
				motLigne[strlen(motLigne) - 1] = '\0';
				tailleMot=strlen(motLigne);	
			}
			while(tailleMot != tailleaTrouver);
}




void genererGrille(int taille_grille, FILE * fichier_texte, char tabMot[])
{ 
	int compteur=0, i=0, j=0, k=0;
	bool condition=true;
	char grille[10] [10]={{'\0'},{'\0'}};

	     	for(i=0;i<taille_grille;i++)
		{
			if(condition==true)
			{
				for(j=0;j<taille_grille;j++)
				{
					grille[i][j]=tabMot[compteur];
					compteur++;
				}
				condition= false;
			}
			else
			{	
				for(k=taille_grille-1;k>=0;k--)
				{
					grille[i][k]=tabMot[compteur];
					compteur++;
				}
				condition= true;
			}
		}
		for(i=0;i<taille_grille;i++)
			{
				for(j=0;j<taille_grille;j++)
				{
					fprintf(fichier_texte ,"%c",grille [i] [j]);
				}
				fputc('\n',fichier_texte);
				fputc('\n',fichier_texte);	
			}
}


int main()

{
	int nombreMotsFichier=0;
	int i=0;
	int j=0;
	int k=0;
	int tailleaTrouver=0;
	char motLigne [100];
	int tab_taille[100]={0};
	int taille_grille=0;
	int nombre_mots=0;
	char dictionnaire [15100] [100]={{'\0'},{'\0'}};
	char tabMot [150]={'\0'};
	char listeMot [150]={'\0'};

	FILE   *fichier, *fichier_texte;
	fichier_texte= fopen("fichier_texte.txt","a+");// ouverture du fichier texte à affcher
	fichier= fopen("dictionnaire.txt","r"); // ouverture du dictionnaire

	srand(time(NULL)); // Initialisation de la donnée seed


	if(fichier!=NULL && fichier_texte!=NULL) // Verifier que le fichier a bien été ouvert
	{
		// Décompte du nombre de mots dans le dictionnaire
		do
		{
	   		if (fgetc(fichier)== '\n')
			{
	       			nombreMotsFichier++;
			}	
		} while(fgetc(fichier) != EOF);

		rewind(fichier); // pour se remettre au début du fichier aprés balayage

		// pour recopier le fichier dictionnaire dans un tableau
		for (i=0;i<15100;i++)
	   	{
	       		fgets(dictionnaire[i], 100, fichier);
	   	}
	
	
	
		for(i=0;i<400;i++) // NOMBRE DE GRILLES CHAQUE TAILLE
		{
			for(k=3;k<11;k++)
			{
				taille_grille=k;
				for (j=0;j<150;j++)
		   		{
		       			tabMot [j]='\0';
					listeMot [j]='\0';
		   		}
				nombre_mots=chercherTaille(taille_grille,tab_taille);
				for(j=0;j<nombre_mots;j++)
				{
					tailleaTrouver = tab_taille[j];	
					trouverMotHasard(nombreMotsFichier,tailleaTrouver, dictionnaire,motLigne);
					strcat(tabMot,motLigne);
					strcat(listeMot,motLigne);
					strcat(listeMot," ");
				}
				genererGrille(taille_grille,fichier_texte,tabMot);
				fprintf(fichier_texte ,"%d ", nombre_mots);
				for (j=0;j<nombre_mots;j++)
		   		{
		       			fprintf(fichier_texte ,"%d ", tab_taille[j]);
		   		}
				fputc('\n',fichier_texte);
				fprintf(fichier_texte ,"\n%s\n",listeMot);
				fputc('\n',fichier_texte);
				fputc('\n',fichier_texte);
			}
		}
	}

	fclose(fichier_texte); // fermeture du fichier texte
	fclose(fichier); // fermeture du dictionnaire

	return 0;
}
