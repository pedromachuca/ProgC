#include <stdio.h>
#include <stdlib.h>

int LENGTH(char *str){
	int i =0;
	while(str[i] !='\0'){
		i++;
	}
	return i;
}
int DIGITS(char *str){
	int i = 0;
	int count = 0;
	char c = ' ';
	while(str[i] !='\0'){
		c = str[i];	
		if(c >='0'&& c<='9'){
			count++;
		}
		i++;
	}
	return count;
}
int CARACTERES(char *str){
	int i = 0;
	int count = 0;
	int count1 = 0;
	char c = ' ';
	while(str[i] !='\0'){
		c = str[i];	
		if(c >='a'&& c<='z'){
			count++;
		}
		else if(c >='A'&& c<='Z'){
			count++;
		}
		i++;
	}

	return count;
}
void REVERSE(char *str){
		char c;
		int j, k, l;
		l = LENGTH(str);
		j = 0;
		k = l-1;

		while(j<k){
			c = str[j];
			str[j]=str[k];
			str[k]=c;

			j++;
			k--;
		}
		printf("La chaine inverse est : %s\n", str);
}
int FIND(char *str, char c){
	int i = 0;

	while(str[i] !='\0'){
		if(str[i]==c){
			return i;
		}
	i++;	
	}
	return -1;
}
int main(int arc, char *argv[]){
	int a,b,c,d;
	char e ='a';
	b = LENGTH(argv[1]);
	printf("La longueur de la chaine est : %d\n", b); 
	
	c= DIGITS(argv[1]);
	printf("Le nombre de digit dans la chaine est : %d\n", c); 
	
	a = CARACTERES(argv[1]);
	printf("Le nombre de char maj on min dans la chaine est : %d\n",a);
	
	d = b-a-c;
	printf("Le nombre de caractère autre est : %d\n", d); 
	printf("La premiere occurence du char est : %d\n", FIND(argv[1], e));

	REVERSE(argv[1]);

}
