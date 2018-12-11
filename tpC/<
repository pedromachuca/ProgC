#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Exercice 1.1 passage par valeur/adresse:
//Fonction ENTIER_ADR sui trçoit un entier par adresse puis
//modifier cet entier dans la fonction. Afficher l'entier avant
//l'appel de la fonction pendant l'appel de fonction (après la modif)
//puis après la fonction
void ENTIER_ADR(int *A){
	*A=*A +2;
	//Affichage de l'entier après modification
	printf("\n%d\n", *A);	
}
//Exercice 1.2 Ecrire une fonction AFFICHE_TAB_N, qui affiche N cases d'un tableau.
//Elle prend en paramètred'entrée la taillle et le tableau.
void AFFICHE_TAB_N(int taille, int tab[taille]){
	int i;
	printf("Affiche tableau de n :\n");
	for(i=3; i<taille; i++){
		printf("Tab[%d]=%d\n", i, tab[i]);
	}

}
//Exercice 2 :Allocation dynamique et mémoire
//Ecrire une fonction ALLOC_TAB_DYN, qui déclare et alloue dynamiquement
//de la mémoire à un tableau avant de le retourner. Le nbre de cases allouer est donné en 
//paramètre.
int *ALLOC_TAB_DYN(int N){
	int *tab;
	tab = malloc(N*sizeof(int));
	return tab;
}
void INIT_ALEA_TAB(int N, int *TAB){

	int low_num = 5;
	int hi_num = 94;
	int randomInt;
    srand(time(NULL));

	for(int i=0; i<N; i++){
    	randomInt = (rand() % (hi_num - low_num)) + low_num;
		TAB[i]=randomInt;
	}
	//test du remplissage
	printf("Test de remplissage aléatoire :\n");
	for(int i=0; i<N; i++){
		printf("%d\n",TAB[i]);
	}
}
void AFFICHE_TAB_DYN_N(int N, int *TAB){
		
	printf("\nAffichage tableau sans []: \n");
	for(int i=0; i<N; i++){
		printf("%d\n", *(TAB+i));
	}
}
int **ALLOC_MAT_DYN(int nb_l, int nb_c){
	int **mat;
	mat = malloc(nb_l*sizeof(int*));
	for(int i=0; i<nb_l;i++){
		mat[i]=malloc(nb_c*sizeof(int));
	}
	return mat;
}
void INIT_ALEA_MAT(int nb_l,int nb_c, int **MAT){
	int low_num = 1;
	int hi_num = 19;
	int randomInt;
    srand(time(NULL));
	for(int i=0; i<nb_l; i++){
		for(int j=0; j<nb_c; j++){
    		randomInt = (rand() % (hi_num - low_num)) + low_num;
			*(*(MAT+i)+j)=randomInt;
		}
	}
}
void LIB_MAT(int nb_l, int**MAT){
	for(int i=0; i<nb_l; i++){
			free(MAT[i]);
			MAT[i]=NULL;
	}
	free(MAT);
	MAT=NULL;
}
void AFFICHE_MAT(int nb_l, int nb_c, int **MAT){
	printf("Affichage matrice :\n");
	for(int i=0; i<nb_l; i++){
		for(int j=0; j<nb_c; j++){
			if(*(*(MAT+i)+j)>9){
				printf("%d ", *(*(MAT+i)+j));
			}
			else{
				printf("%d ", *(*(MAT+i)+j));
			}
		}
	printf("\n");
	}
}
//Exercice 3:Traitement de fichier
void AFFICHE_MAT_DANS_FIC(int nb_l, int nb_c, int **MAT, FILE *FIC){
	int retour=0;
	for(int i=0; i<nb_l; i++){
		for(int j=0; j<nb_c; j++){
			retour = fprintf(FIC, "%d\n", *(*(MAT+i)+j));
		}
	}
}
void INIT_MAT_VIA_FIC(int nb_l, int nb_c, int **MAT, FILE *FIC){
	int retour=0;
	int res;
	for(int i=0; i<nb_l; i++){
		for(int j=0; j<nb_c; j++){
			//fscanf(FIC, "%d ", &MAT[i][j]);
			//fscanf(FIC, "%d ", &(*(*(MAT+i)+j)));
			fscanf(FIC, "%d ", *(MAT+i)+j);

		}
	}
}
int NB_LIGNES_FIC(FILE *FIC){
	char c=' ';
	int nb_lignes=0;
	while ((c = fgetc(FIC)) != EOF){
		if (c == '\n'){
			++nb_lignes;
		}
	}
	return nb_lignes;
}
int RECHERCHE_MOTIF(FILE *FIC, char *MOTIF){
	char c=' ';
	int nb_lignes=0;
	int lengthMotif = strlen(MOTIF);
	int count=0;
	int countOccurence =0;

	printf("motif :%d\n", lengthMotif);
	c =fgetc(FIC);
	while (c!= EOF){
		if (c == '\n'){
			++nb_lignes;
		}
		else if(c==MOTIF[0]){
			for(int i =1; i<lengthMotif; i++){
					c=fgetc(FIC);
					if(c==MOTIF[i]){
						count++;
					}
			}
			if(count==lengthMotif-1){
				countOccurence++;
				printf("Ligne : %d, Occurrence: %d \n", nb_lignes, countOccurence);
			}
			count = 0;
		}
		c =fgetc(FIC);
	}
	return countOccurence;
}
int main (int argc, char *argv[]){
	int *adr;
	int x =14;
	adr = &x;
	//affichage de la valeur avant l'appel
	printf("Affichage de l'entier : \n%d", *adr);
	//Fonction reçoit l'entier par adresse
	ENTIER_ADR(&x);
	//Affichage après appel de la fonction
	printf("%d\n", *adr);

	//Exercice 1.2
	int tab[10]={1,2,3,4,5,6,7,8};
	AFFICHE_TAB_N(10, tab);
	
	//Exercice 2.1
	int *tab1 =ALLOC_TAB_DYN(12);
	//Excercice 2.2
	INIT_ALEA_TAB(12 ,tab1);	
	//Exercice 2.3
	AFFICHE_TAB_DYN_N(12, tab1);
	//Exercice 2.4
	int **mat = ALLOC_MAT_DYN(5, 10);
	//Exercice 2.5
	INIT_ALEA_MAT(5,10,mat);
	//Exercice 2.6
	//LIB_MAT(5, mat);
	//Exercice 2.7
	AFFICHE_MAT(5,10, mat);
	//LIB_MAT(5, mat);
	//Exercice 3.1
	
	FILE *FIC;
	FILE *FIC1;
	FIC = fopen("matrice.txt", "w+");
	FIC1 = fopen("lorem.txt", "r+");

	if(FIC==NULL){
		printf("Le fichier n'existe pas !\n");
	}
	else{
		printf("Le fichier a été correctement ouvert!\n");	
		AFFICHE_MAT_DANS_FIC(5,10,mat, FIC);
	}

	LIB_MAT(5, mat);
	//Exercice 3.2
	int **mat1 = ALLOC_MAT_DYN(5, 10);
	fseek(FIC, 0, SEEK_SET);
	INIT_MAT_VIA_FIC(5,10,mat1,FIC);
	AFFICHE_MAT(5,10, mat1);
	//Exercice 3.3
	fseek(FIC, 0, SEEK_SET);
	int nb_ligne = NB_LIGNES_FIC(FIC);
	printf("Le nombre de ligne est : %d\n", nb_ligne);
	fclose(FIC);
	
	char MOTIF[6] = {'l','o','r','e','m','\0'};
	if(FIC==NULL){
		printf("Le fichier n'existe pas !\n");
	}
	else{
		printf("Le fichier a  été correctement ouvert!\n");	
		int nb_motif = RECHERCHE_MOTIF(FIC1, MOTIF);
		printf("Nombre de motif : %d", nb_motif);
	}
	fclose(FIC1);
}
