/*
 On suppose que vous avez le package SDL déjà installé sur votre machine, sinon il faudra l'installer. Pour compiler il suffit de taper la commande :
 gcc -o EXEC STEGANALYSE.c `sdl-config --cflags --libs` -Wall
 
 Le code a été largement commenté pour vous permettre de le comprendre plus facilement et plus rapidement.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>


/*Fonction qui sert à charger une image*/
SDL_Surface * load_image( char * filename ) 
{
	SDL_Surface * Image_chargee = NULL; //Surface tampon qui nous servira pour charger l'image
	SDL_Surface * Image_optimisee = NULL; //L'image optimisée qu'on va utiliser

	Image_chargee = SDL_LoadBMP(filename); //Chargement de l'image BMP

	if( Image_chargee != NULL ) //Si le chargement se passe bien
	{ 	 
	    Image_optimisee = SDL_DisplayFormat(Image_chargee); /*Pour convertir l'image chargée vers le format 
	                                                       d'affichage adapté (celui de l'écran actuel)*/
	    SDL_FreeSurface(Image_chargee); //Libération de l'ancienne image chargée
	}
	return Image_optimisee; //On retourne l'image optimisée 
}



/* Pour applliquer une surface sur une autre à partir de la position en haut à gauche (x,y)*/
void appliquer_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination) 
{ 
	SDL_Rect POS; /*Pour définir une zone rectangulaire commençant en haut à gauche*/
	POS.x = x; /*position x de depart en haut à gauche*/
	POS.y = y; /*position y de depart en haut à gauche*/
	SDL_BlitSurface(source, NULL, destination, &POS ); //On applique toute la surface source => destination
}



/* Fonction qui permet de recuperer la valeur d'un pixel d'une image, à une position (x,y) donnée. 
   Ce qui permettrait ensuite de recupérer les valeurs des composant RGB du pixel via la fonction SDL_GetRGB.*/
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{/*Attention : x est utilisé pour les colonnes et y pour les lignes comme dans un répère orthonormé mais dont le centre est en haut à gauche de l'image*/
    int bpp = surface->format->BytesPerPixel; /*Pour obtenir l'encodage des pixels de l'image*/
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp)
    {
    case 1:
        return *p;
 
    case 2:
        return *(Uint16 *)p;
 
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2]; //L'octet le plus fort est mis à l'adresse mémoire la plus petite
        else
            return p[0] | p[1] << 8 | p[2] << 16; //L'octet le plus faible est mis à l'adresse mémoire la plus petite
    case 4:
        return *(Uint32 *)p;
 
    default:
        return 0;
    }
}
/*Fonction qui recherche une image cachée dans une autre image*/
void recherche_image_cachee(SDL_Surface * IMAGE_MERE, SDL_Surface * image_cachee)
{
 int x_f, x_m, y_m, larg_img_mere, hau_img_mere;
  int bpp = image_cachee->format->BytesPerPixel; /*Nombre d'octets/pixel de la surface de l'image cachée*/
  Uint32 PIXEL1, PIXEL2; /*PIXEL1 sera utilisé pour l'image mère et PIXEL2 pour l'image cachée*/
  Uint8 * p;                /*pointeur pour balayer et indexer les contenus des pixels de l'image cachée*/
  Uint8 R, G, B;            /*composants R=>rouge, G=>vert et B=> bleu pour le pixel PIXEL1 de l'image mère*/
  larg_img_mere = IMAGE_MERE->w; /*Pour obtenir la largeur de l'image mère*/
  hau_img_mere = IMAGE_MERE->h;  /*Pour obtenir la hauteur de l'image mère*/
  //printf("%d %d\n", larg_img_mere, hau_img_mere);
  y_m=0;
  //printf("%d\n", IMAGE_MERE->pitch);
  while (y_m < hau_img_mere)
  {
    x_m=0; x_f=0;
    while (x_m < larg_img_mere)
    {
      
      PIXEL1 = getpixel(IMAGE_MERE, x_m, y_m); /*récupération du pixel de l'image mère*/
      SDL_GetRGB(PIXEL1, IMAGE_MERE->format, &R, &G, &B); /*Récupération des composants RGB du pixel de l'image mère*/
      
      
      //PIXEL2 = getpixel(image_cachee, x_f, y_m); /*récupération du pixel de l'image fille*/
      
      
      PIXEL2=0;
      p = (Uint8 *)image_cachee->pixels + y_m * image_cachee->pitch + x_f * bpp; /*positionnement du pointeur sur le pixel de l'image fille, afin de pouvoir changer sa valeur*/
      /*
        image_cachee->pixels contient l'adresse du premier composant couleur (ici BLEU) du premier pixel de l'image cachée. 
        Avec ce pointeur on va pouvoir balayer l'image comme une suite d'octets RGB correspondant à chaque pixel.
      */
      
      PIXEL2 = PIXEL2 ^ ((Uint32)(R&15) << 20);
      
      PIXEL2 = PIXEL2 ^ ((Uint32)(G&15) << 12);
      
      PIXEL2 = PIXEL2 ^ ((Uint32)(B&15) << 4);
      /*Fin de la récupération des bits de poids fort de l'image fille*/
      
      x_m++; /*pour aller au pixel suivant de l'image mère*/
      PIXEL1 = getpixel(IMAGE_MERE, x_m, y_m); /*récupération du pixel de l'image mère*/
      SDL_GetRGB(PIXEL1, IMAGE_MERE->format, &R, &G, &B); /*Récupération des composants RGB du pixel de l'image mère*/
     

      /*Début de la récuperation des bits de poids faible initialement cachés de l'image fille pour chaque composant couleur*/
     
      PIXEL2 = PIXEL2 ^ ((Uint32)(R&15) << 16);
      
      PIXEL2 = PIXEL2 ^ ((Uint32)(G&15) << 8);
      
      PIXEL2 = PIXEL2 ^ ((Uint32)(B&15));
      /*Fin de la récupération des bits de poids faible de l'image fille*/
     /*A ce stade la valeur du pixel "PIXEL2" est prête à être injectée dans l'image fille. Il faut donc l'affecter à la surface de l'image cachée*/
     
      switch (bpp) /*Pour stocker les octets dans le bon format*/
      {
	case 1:
	  *p = PIXEL2;
	  break;
	  
	case 2:
	  *(Uint16 *)p = PIXEL2;
	  break;
	  
	case 3:
	  if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
	  {
	    p[0] = (PIXEL2 >> 16) & 255; p[1] = (PIXEL2 >> 8) & 255; p[2] = PIXEL2 & 255;
	  }
	  else
	  {
	    p[0] = PIXEL2 & 255; p[1] = (PIXEL2 >> 8) & 255; p[2] = (PIXEL2 >> 16) & 255;
	  }
          break;
	  
	case 4:
	  *(Uint32 *)p = PIXEL2;
	  break;
      }
     x_m++; x_f++;
    }
    
    y_m++;
  }

}



/*Fonction qui recherche le texte caché dans l'image fille*/
void recherche_texte_cache_dans_image(SDL_Surface * image, char * TEXTE)
{
/*le texte a été caché comme suit : pour un caractère, les 3 bits de poids faible
on été cachés dans les trois bits de poids faible du composant bleu d’un pixel de l’image, puis les
2 bits suivant du caractère dans les 2 bits de poids faible du composant vert, puis les deux bits
suivant dans les 2 bits de poids faible du composant rouge du même pixel de l’image.*/

  int x_m, y_m, larg_img_fille, hau_img_fille;
  Uint32 PIXEL1; /*PIXEL1 sera utilisé pour l'image mère et PIXEL2 pour l'image cachée*/
  Uint8 R, G, B;            /*composants R=>rouge, G=>vert et B=> bleu pour le pixel PIXEL1 de l'image mère*/
  larg_img_fille = image->w; /*Pour obtenir la largeur de l'image fille*/
  hau_img_fille = image->h;  /*Pour obtenir la hauteur de l'image fille*/
  y_m=0;
  char C =0;
	int i =0;
  while (y_m < hau_img_fille)
  {
    x_m=0;
    while (x_m < larg_img_fille)
    {
	C=0;      
      PIXEL1 = getpixel(image, x_m, y_m); /*récupération du pixel de l'image fille*/
      SDL_GetRGB(PIXEL1, image->format, &R, &G, &B); /*Récupération des composants RGB du pixel de l'image fille*/

      C = C|((R&3)<<5);
      C = C|((G&3)<<3);
      C = C|((B&7));
      //printf("Char is : %c \n", C);
      TEXTE[i]=C; 
      i++;
     x_m++;
    }
    y_m++;
  }
}
/*Fonction qui affiche un texte sur la sortie standard*/
void affichage_texte(char * TEXTE)
{
 printf("-----------------------------------------------------------------------------------------------\n");
 printf("%s\n", TEXTE);
 printf("-----------------------------------------------------------------------------------------------\n");
}




int main (int argc, char * argv[])
{
  int LARGEUR_ECRAN, HAUTEUR_ECRAN, CODAGE, PAUSE;
  LARGEUR_ECRAN=1300; HAUTEUR_ECRAN=650;
  CODAGE = 24; //8x3=24 bits / pixel couleur
  char * TEXTE;
  SDL_Surface * ecran = NULL;        //déclaration d'une surface d'écran de base (sur laquelle on va travailler)
  SDL_Surface * IMAGE = NULL;        //déclaration d'une surface (pour l'image qui cache)
  SDL_Surface * image_cachee = NULL; //Déclaration d'une autre surface (pour l'image cachée)
  

  SDL_Event event; //Pour gérer les evénements type clic de souris
  
 
  ecran = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, CODAGE, SDL_SWSURFACE); //Initialisation du mode video
  SDL_WM_SetCaption( "Steganalyse Image BMP", NULL ); //Mise en place de la barre caption nommée "Steganalyse Image BMP"
  
  IMAGE = load_image( "tiger_stegano.bmp" ); //Chargement de l'image mère contenant les informations cachées
  
  appliquer_surface(0, 0, IMAGE, ecran); //On applique l'image mère sur l'écran de base au coin haut gauche (0,0)
  
  SDL_Flip( ecran ); //pour mettre à jour l'écran et faire apparaitre la nouvelle surface appliquée juste avant
  
  
  PAUSE=1;
  while (PAUSE) 
  {
     SDL_WaitEvent(&event); //attend qu'un événement se produise
     switch(event.type) 
     {
      case SDL_MOUSEBUTTONUP: // en cas de Clic de la souris
         if(event.button.button==SDL_BUTTON_LEFT) 
	 {PAUSE=0;/*Pour ensuite sortir de la boucle et conituer le programme*/}
     } 
  }
  
  image_cachee = SDL_CreateRGBSurface(0, 400, 555, 24, 0, 0, 0, 0); //Création d'une surface RGB 150x250 (24 bits/pixel)
  
  recherche_image_cachee(IMAGE, image_cachee); //on cherche l'image cachée dans l'image mère
  
  printf("L'image cachée est la suivante :\n");
  appliquer_surface(850, 0, image_cachee, ecran); //On applique l'image sur l'écran à la position (y=0 et x=350)
  SDL_Flip(ecran); //pour mettre à jour l'écran et faire apparaitre la nouvelle surface appliquée précédemment
  
  PAUSE=1;
  while (PAUSE) /*Pour faire une pause sur l'écran et observer */
  {
     SDL_WaitEvent(&event); //attend qu'un événement se produise
     switch(event.type) 
     {
      case SDL_MOUSEBUTTONUP: // en cas de Clic de la souris
         if(event.button.button==SDL_BUTTON_LEFT) //Si on clique sur le bouton gauche de la souris 
	 {PAUSE=0;}
     } 
  }
  
  /*Recherche puis affichage du texte caché dans une image*/
  TEXTE = malloc(sizeof(char)*222000);
  recherche_texte_cache_dans_image(image_cachee, TEXTE);
  printf("Le texte caché est le suivant :\n");
  affichage_texte(TEXTE);


  SDL_FreeSurface(IMAGE);
  SDL_FreeSurface(image_cachee);
  SDL_FreeSurface(ecran);
  free(TEXTE);
  SDL_Quit();
  
  return EXIT_SUCCESS;
}











































