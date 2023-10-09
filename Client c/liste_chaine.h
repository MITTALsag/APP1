#ifndef __LISTE_CHAINE_H__
#define __LISTE_CHAINE_H__


typedef struct cellule {
    struct cellule* suivant;
    char val;
    struct cellule* precedent;
}cell;

typedef struct l{
    cell* deb;
    cell* fin;
    int taille;
}liste;

void init_liste(liste* seq);
cell* nouvelleCellule (char c);
void detruireCellule (cell* cel);
void inverser_liste(liste* seq);
void decrypte_chaine(liste* txt, liste* enc);
void conversion (char *texte, liste* seq);
void afficher_liste(liste* seq);
void re_conversion_100(liste* seq, char* txt);

#endif
