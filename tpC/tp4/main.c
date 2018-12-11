#include "fonctions.h"
#include "librairies.h"

int main(int argc, char *argv[]){
	srand(time(NULL));
	
	VEHICULE v1 = INIT_VEHICULE_SANS_POINTEUR();
	AFFICHE_VEHICULE_SANS_POINTEUR(v1);
	
	VPOINT v2 = (VPOINT)malloc(sizeof(VEHICULE));
	INIT_VEHICULE_AVEC_POINTEUR_1(v2);
	AFFICHE_VEHICULE_AVEC_POINTEUR(v2);
	
	VPOINT v3 =INIT_VEHICULE_AVEC_POINTEUR_2();
	AFFICHE_VEHICULE_AVEC_POINTEUR(v3);

	VPOINT mesvehicules= ALLOC_TAB_VEH_DYN(10);
	for(int i=0; i<10; i++){
		INIT_VEHICULE_AVEC_POINTEUR_1(mesvehicules+i);
	}
	for(int i=0; i<10; i++){
		AFFICHE_VEHICULE_AVEC_POINTEUR(mesvehicules+i);
	}
	printf("--------------------------------------------------");
	TRI_A_BULLES(mesvehicules, 10);
	for(int i=0; i<10; i++){
		AFFICHE_VEHICULE_AVEC_POINTEUR(mesvehicules+i);
	}
	LISTE *l1 = CREATION_LISTE();
	INIT_LISTE(l1);
}
