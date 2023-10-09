#include "liste_chaine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_liste(liste* seq){
    seq->deb = NULL;
    seq->fin = NULL;
    seq->taille = 0;
}

cell* nouvelleCellule (char c)
{
    cell* nouvelle_cellule = (cell*)(malloc (sizeof(cell)));
    if (!nouvelle_cellule){
        fprintf(stderr, "Errueur : probleme allocation cellule dnas nouvelleCellule.\n");
        exit(EXIT_FAILURE);
    }
    nouvelle_cellule->val = c;
    nouvelle_cellule->suivant = NULL;
    nouvelle_cellule->precedent = NULL;
    return nouvelle_cellule;
}

void detruireCellule (cell* cel)
{
    free(cel);
}

void inverser_liste(liste* seq){
    cell* tmp;
    tmp = seq->deb;
    while (tmp != NULL){
        cell* tmp_bis = tmp->suivant;
        tmp->suivant = tmp->precedent;
        tmp->precedent = tmp_bis;
        tmp = tmp->precedent;
    }
    tmp = seq->fin;
    seq->fin = seq->deb;
    seq->deb = tmp;
}

void decrypte_chaine(liste* txt, liste* enc){
    init_liste(txt);
    while (enc->taille!=0){
        char c = enc->fin->val;
        int x = c % 8;

        if (txt->taille > 0){
            if (txt->taille > x){
                for (int i = 0 ; i < x ; i++){
                    cell* cel_tmp = txt->fin;
                    txt->fin = txt->fin->precedent;
                    txt->fin->suivant = NULL;
                    cel_tmp->precedent = NULL;
                    cel_tmp->suivant = txt->deb;
                    txt->deb = cel_tmp;
                    txt->deb->suivant->precedent = txt->deb;
                }
            }
            enc->fin->suivant = txt->deb;
            txt->deb = enc->fin;
            if (enc->fin->precedent) {
                enc->fin->precedent->suivant = NULL;
            }
            enc->fin = enc->fin->precedent;
            txt->deb->precedent = NULL;
            txt->deb->suivant->precedent = txt->deb;
            enc->taille--;
            txt->taille++;
        }
        else {
            txt->deb = enc->fin;
            txt->fin = enc->fin;
            enc->fin->precedent->suivant = NULL;
            enc->fin = enc->fin->precedent;
            txt->taille++;
            enc->taille--;
            txt->deb->precedent = NULL;
        }
    }
}     


void conversion (char *texte, liste* seq){
    cell* cel = nouvelleCellule(texte[0]);
    seq->deb = cel;
    int len = strlen(texte);
    for (int i = 1 ; i < len ; i++){
        cell* nouv_cel = nouvelleCellule(texte[i]);
        nouv_cel->precedent = cel;
        cel->suivant = nouv_cel;
        cel = nouv_cel;
    }
    seq->fin = cel;
    seq->taille = len;
}


void afficher_liste(liste* seq){
    cell* cel = seq->deb;
    while(cel){ //jusqu'a le fin de la liste
        printf("%c", cel->val);
        cel = cel->suivant;
    }
}


void re_conversion_100(liste* seq, char* txt){
    cell* cel = seq->deb;
    for (int i = 0 ; i < 100 ; i++){
        txt[i] = cel->val;
        cel = cel->suivant;
    }
}