#include "LIBRAIRIES.h" 
#include "CHIFFREMENT.h"


/* Fonction de chiffrement par substitution  */
void Chiffrer_substitution(int * cle,  int * texte_clair, int * texte_chiffre, int longueur_texte)
{
	int id;

	for(int i=0; i<longueur_texte; i++){
		id = texte_clair[i]%97;
		texte_chiffre[i]=cle[id];
	}
}

/* Fonction de dechiffrement par substitution  */
void Dechiffrer_substitution(int * cle,  int * texte_chiffre, int * texte_dechiffre, int longueur_texte)
{
	int id;

	for(int i=0; i<longueur_texte; i++){
		id=texte_chiffre[i]%97;
		texte_dechiffre[i]=cle[id];
	}
}
