#include "LIBRAIRIES.h"
#include "FONCTIONS_COMMUNES.h"


/***********            Fonction pour déterminer la taille du texte             ************/
void Determination_long_texte(int * LT, char * nom_fichier)
{
  int lettre;
  int L=0;
  FILE * FIC;
  if((FIC = fopen(nom_fichier,"r")) == NULL)
  {
    fprintf(stderr,"\n Erreur: Impossible d'écrire dans le fichier %s \n",nom_fichier);
    exit(EXIT_FAILURE);
  } 
  lettre=fgetc(FIC);
  while(lettre != EOF)
  {
    if ((lettre >= 'A' && lettre <= 'Z') || (lettre >= 'a' && lettre <= 'z')) /* pour ne pas comptabiliser les retour à la ligne */
    {
      L++;
    }
    lettre=fgetc(FIC);
  }
  *LT = L;
  fclose(FIC);
}

/***********            Fonction de Lecture/chargement du texte                ************/

void Lire_et_charger_texte(int * texte, int longueur_texte, char * nom_fichier)
{
  int i, lettre;
  i=0;
  FILE * FIC;


  /* Ouverture du fichier , gerer l'impossibilité d'ouverture du fichier*/
  if( (FIC = fopen(nom_fichier,"r")) == NULL)
  {
    fprintf(stderr,"\n Erreur: Impossible d'écrire dans le fichier %s \n",nom_fichier);
    exit(EXIT_FAILURE);
  } 

  /** Lecture du fichier contenant le texte **/
  lettre=fgetc(FIC);
  while(lettre != EOF)
    {
      if( ( lettre <= 122) && ( lettre >= 97)) 
      {
	  texte[i] = lettre - 97; //ATTENTION à la récupération des valeurs des lettres
	  i++;
      }
      else if( ( lettre <= 90) && ( lettre >= 65)) 
      {
	  texte[i] = lettre - 65;
	  i++;
      }
      else if ((char)lettre != ' ' && (char)lettre != '\n')
      {
	printf("Atention : caractère non pris en charge !\n");
      }
       lettre=fgetc(FIC);
    }

  /* Fermeture du fichier */
  fclose(FIC);
}


/******************* Ecriture du Texte Chiffré ***************************/
void Ecrire_chiffre(int * texte_chiffre, int longueur_texte, char * nom_fichier)
{
  FILE * FIC;
  int i;
 
  /* Ouverture du fichier , gerer l'impossibilité d'ouverture du fichier*/
  if( (FIC = fopen(nom_fichier,"w")) == NULL)
  {
    fprintf(stderr,"\n Erreur: Impossible d'écrire dans le fichier %s \n",nom_fichier);
    exit(EXIT_FAILURE);
  } 

  /** Ecriture du texte chiffré dans le fichier donné en parametre **/
  for(i=0;i<longueur_texte;i++)
    {
      fputc('a'+ (char) texte_chiffre[i], FIC);
    }

  /* Fermeture du fichier */
  fclose(FIC); 
}



/************Fonction pour lire et charger la clé contenue dans le fichier "fichier_cle" ********************/
void Lire_cle(int cle[26], char * fichier_cle)
{

  int lettre;
  FILE * FIC;
  int i;

  /* Ouverture du fichier , gerer l'impossibilité d'ouverture du fichier*/

  if( (FIC = fopen(fichier_cle,"r")) == NULL)
  {
    fprintf(stderr,"\n Erreur: Impossible d'écrire dans le fichier %s \n",fichier_cle);
    exit(EXIT_FAILURE);
  } 

  /** Lecture du fichier contenant la cle en lettres **/
  for(i=0;i<26;i++)
    {
        lettre=fgetc(FIC);
	if( ( lettre <= 122) && ( lettre >= 97)) 
	{
	    cle[i] = lettre - 97;
	}
	else if( ( lettre <= 90) && ( lettre >= 65)) 
	{
	  cle[i] = lettre - 65;
	}
	
    }
  
  fclose(FIC); /* Fermeture du fichier */
}







