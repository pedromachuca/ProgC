#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ADD(double a, double b){
	return a+b;
}
double SOU(double a, double b){
	return a-b;
}
double MUL(double a, double b){
	return a*b;
}
double DIV(double a, double b){
	return a/b;
}
double PUI(double a, double b){
	return pow(a, b);
}
double MOD(double a, double b){
		int c =(int)a;
		int d =(int)b;
	return c%d;
}


int main(){
	//la fonction system permet d'exécuter des commandes systemes
	system("clear");
	double a,b;
	char c =' ';
	int d = 0;
	char e='\n';
	system("cat /home/pierre/Documents/tpC/ascii.txt");
	while(d==0){		
		//ce printf permet d'afficher le curseur sur la position 
		// 2, 2 cad en haut a gauche 
		printf("\033[%d;%dH", 2, 2);
		scanf("%lf %c %lf", &a, &c, &b);
		printf("\033[%d;%dH",3 , 3);
		switch (c){
			case '+':
				printf("%lf + %lf = %lf", a,b ,ADD(a,b));
				printf("\033[%d;%dH", 2, 2);
				break;
			case '-':
				printf("%lf - %lf = %lf\n", a,b ,SOU(a,b));
				printf("\033[%d;%dH", 2, 2);
				printf("                           ");
				break;
			case 'x':
				printf("%lf x %lf = %lf\n", a,b ,MUL(a,b));
				printf("\033[%d;%dH", 2, 2);
				printf("                           ");
				break;
			case '/':
				printf("%lf / %lf = %lf\n", a,b ,DIV(a,b));
				printf("\033[%d;%dH", 2, 2);
				printf("                           ");
				break;
			case '^':
				printf("%lf ^ %lf = %lf\n", a,b ,PUI(a,b));
				printf("\033[%d;%dH", 2, 2);
				printf("                           ");
				break;
			case '%':
				printf("%lf %% %lf = %d\n", a,b ,MOD(a,b));
				printf("\033[%d;%dH", 2, 2);
				printf("                           ");
				break;
			default:
				break;
		}
		/*ce scanf sert a lire l'entrée du précedent scanf, le entrer va être lu
		ici puis le char lu donc on vide le buffer du scanf et on lui demande de le 
		reremplir avec un char*/
		scanf("\n%c", &e);
		if(e=='q'){
			d=1;
			printf("\033[%d;%dH", 17, 1);
			printf("Bye Bye !!\n");
			break;
		}
		else{
			printf("\033[%d;%dH", 2, 2);
			system("cat /home/pierre/Documents/tpC/ascii.txt");
		}
		
	}	
	return 0;
}
