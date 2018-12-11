#include "librairies.h"
#include "fonctions.h"

//Exercice Partie A:
VEHICULE INIT_VEHICULE_SANS_POINTEUR(){
	VEHICULE v1;
	int randomInt = (rand() % (5 - 1)) + 1;
	switch(randomInt){
		case 1:
			strcpy(v1.marque, "tata");
			break;
		case 2:
			strcpy(v1.marque, "toyota");
			break;
		case 3:
			strcpy(v1.marque, "lada");
			break;
		case 4:
			strcpy(v1.marque, "peugot");
			break;
		case 5:
			strcpy(v1.marque, "bmw");
			break;
		default:
			break;
	}
	int randomInt2 = (rand() % (700 - 100)) + 100;
	v1.puissance = randomInt2;
	int randomInt3 = (rand() % (400 - 180)) + 180;
	v1.vitesse_max= randomInt3;

	return v1;
}


void AFFICHE_VEHICULE_SANS_POINTEUR(VEHICULE V){
	printf("Marque : %s \nPuissance : %d CH\nVitesse_Max :%d km\\h\n\n", V.marque,V.puissance,V.vitesse_max);
}
//Exercice : Partie B

void INIT_VEHICULE_AVEC_POINTEUR_1(VEHICULE *V){
	int randomInt = (rand() % (5 - 1)) + 1;
	switch(randomInt){
		case 1:
			strcpy((*V).marque, "tata");
			break;
		case 2:
			strcpy((*V).marque, "toyota");
			break;
		case 3:
			strcpy((*V).marque, "lada");
			break;
		case 4:
			strcpy((*V).marque, "peugot");
			break;
		case 5:
			strcpy((*V).marque, "bmw");
			break;
		default:
			break;
	}	
	int randomInt2 = (rand() % (700 - 100)) + 100;
	(*V).puissance = randomInt2;
	int randomInt3 = (rand() % (400 - 180)) + 180;
	(*V).vitesse_max= randomInt3;
}
VEHICULE * INIT_VEHICULE_AVEC_POINTEUR_2(){
	VPOINT V =(VPOINT)malloc(sizeof(VEHICULE));
	int randomInt = (rand() % (5 - 1)) + 1;
	switch(randomInt){
		case 1:
			strcpy((*V).marque, "tata");
			break;
		case 2:
			strcpy((*V).marque, "toyota");
			break;
		case 3:
			strcpy((*V).marque, "lada");
			break;
		case 4:
			strcpy((*V).marque, "peugot");
			break;
		case 5:
			strcpy((*V).marque, "bmw");
			break;
		default:
			break;
	}	
	int randomInt2 = (rand() % (700 - 100)) + 100;
	(*V).puissance = randomInt2;
	int randomInt3 = (rand() % (400 - 180)) + 180;
	(*V).vitesse_max= randomInt3;
	return V;
}
void AFFICHE_VEHICULE_AVEC_POINTEUR(VEHICULE *V){
	printf("Marque : %s \nPuissance : %d CH\nVitesse_Max :%d km\\h\n\n", (*V).marque,(*V).puissance,(*V).vitesse_max);
}
//Partie C : Tri a bulle
VEHICULE *ALLOC_TAB_VEH_DYN(int N){
	VPOINT V =(VPOINT)malloc(N*sizeof(VEHICULE));
	return V;
}
void TRI_A_BULLES(VEHICULE *mesvehicules, int N){
	VPOINT temp=ALLOC_TAB_VEH_DYN(1);
	int estTriee=0;
	do{
		estTriee=1;
		for(int i=0; i<10; i++){
			if(mesvehicules[i].puissance >mesvehicules[i+1].puissance){
				temp[i] = mesvehicules[i];
				mesvehicules[i] = mesvehicules[i+1];
				mesvehicules[i+1] = temp[i];
				estTriee=0;
			}
		}
	}while(estTriee==0);
		//printf("vehicule 1 :%d, 2:%d\n ",mesvehicules[0].puissance, mesvehicules[1].puissance);
		printf("vehicule 1 :%d, 2:%d\n ",mesvehicules->puissance,(mesvehicules+1)->puissance);
}
//Partie D : Liste chainée de véhicule
LISTE * CREATION_LISTE(){
	LISTE *l1=(LISTE*)malloc(sizeof(LISTE));
	return l1;
}
void INIT_LISTE(LISTE *L){
	L->taille=0;
	L->debut=NULL;
	L->fin=NULL;
}



