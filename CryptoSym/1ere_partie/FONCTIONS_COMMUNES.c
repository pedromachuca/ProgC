#include "LIBRAIRIES.h"
#include "FONCTIONS_COMMUNES.h"


/***********            Fonction pour déterminer la taille du texte donné en entrée             ************/
void Determination_long_texte(int * LT, char * nom_fichier) /*LT est un pointeur qui contiendra la taille du texte*/
{
	FILE *FIC_IN;
	int c;
	int compteur =0;
	if((FIC_IN =fopen(nom_fichier, "rb"))!=NULL){
		while((c=fgetc(FIC_IN))!=EOF){  
			
			if(c>=65&&c<=122){
				compteur++;			
			}
		}
		*LT=compteur;
	}
	fclose(FIC_IN);
}
/***********            Fonction de Lecture/chargement du texte                ************/
/*********** Attention !!! on ne stocke que les valeurs de l'alphabet comprises entre 0 et 25 inclus ************/

void Lire_et_charger_texte(int * texte, int longueur_texte, char * nom_fichier)
{
	FILE *FIC_IN;
	int c;

	if((FIC_IN =fopen(nom_fichier, "rb"))!=NULL){
		for(int i=0; i<longueur_texte; i++){
			c=fgetc(FIC_IN);
			if(c>=97&&c<=122){
				texte[i]=c;
			}
			else if(c>=65&&c<=90){
				texte[i]=c+32;
			}
		}
	}	
	fclose(FIC_IN);
}


/******************* Ecriture du Texte Chiffré dans le fichier donné en parametre ***************************/
void Ecrire_chiffre(int * texte_chiffre, int longueur_texte, char * nom_fichier)
{
	FILE *FIC_OUT;
	int c;
	FIC_OUT =fopen(nom_fichier, "wb");
	
	for(int i=0; i<longueur_texte; i++){
		c=texte_chiffre[i];	
		fputc(c, FIC_OUT);
	}
	fclose(FIC_OUT);
}



/************Fonction pour lire et charger la clé contenue dans le fichier "fichier_cle" ********************/
void Lire_cle(int cle[26], char * fichier_cle)
{
	FILE *FIC_CLE;
	int c;
	int compteur=0;

	if((FIC_CLE =fopen(fichier_cle, "rb"))!=NULL){
		while((c=fgetc(FIC_CLE))!=EOF&&compteur<27){
			cle[compteur]=c;
			compteur++;
		}
	}
	fclose(FIC_CLE);
}







