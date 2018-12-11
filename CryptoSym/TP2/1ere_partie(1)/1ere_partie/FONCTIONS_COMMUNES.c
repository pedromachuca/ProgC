#include "LIBRAIRIES.h"
#include "FONCTIONS_COMMUNES.h"


/***********            Fonction pour déterminer la longueur du texte             ************/
/* ATTENTION : 
 * le texte doit comporter uniquement les lettres de l'alphabet symbolisés par 0, ..., 25. 
 * Il ne faut pas aussi comptabiliser les retours à la ligne */

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
/*********** Attention !!! on ne stocke que les valeurs de l'alphabet comprises entre 0 et 25 inclus ************/

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


/******************* Affichage du Texte Chiffré dans le fichier donné en paramètre ***************************/
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
