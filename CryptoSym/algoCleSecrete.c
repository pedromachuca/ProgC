#include <stdio.h>

int main(int argc, char *argv[]){

	FILE *FIC_IN, *FIC_OUT;
	char *cle;
	int c;

	if(cle=argv[1]){
		if((FIC_IN=fopen(argv[2], "rb"))!=NULL){
			if((FIC_OUT=fopen(argv[3], "wb"))!=NULL){
				while((c=fgetc(FIC_IN))!=EOF){
					//Reinitialisation de la cle
					if(!*cle){cle=argv[1];}
					//XOR entre le caractere a chiffrer et l'élément de la cle, 
					//et après repositionnement sur le prochain élement de la cle
					c ^= *(cle++);
					//on met le char correspondant dans le fichier de sortie
					fputc(c, FIC_OUT);
				}
			fclose(FIC_OUT);
			}
		fclose(FIC_IN);
		}
	}
	return 0;
}
