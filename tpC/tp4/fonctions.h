typedef struct voiture{
         char marque[20];
         int puissance;
         int vitesse_max;
		 struct voiture * NXT;
}VEHICULE;
typedef VEHICULE *VPOINT;

typedef struct liste{
		int taille;
		VEHICULE *debut;
		VEHICULE *fin;
}LISTE;


VEHICULE INIT_VEHICULE_SANS_POINTEUR();
void AFFICHE_VEHICULE_SANS_POINTEUR(VEHICULE V);
void INIT_VEHICULE_AVEC_POINTEUR_1(VEHICULE *V);
void AFFICHE_VEHICULE_AVEC_POINTEUR(VEHICULE *V);
VEHICULE * INIT_VEHICULE_AVEC_POINTEUR_2();
VEHICULE * ALLOC_TAB_VEH_DYN(int N);
void TRI_A_BULLES(VEHICULE *mesvehicules, int N);
LISTE *CREATION_LISTE();
void INIT_LISTE(LISTE* L);

