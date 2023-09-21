#ifndef __ENCRYPTE_DECRYPTE_H__
#define __ENCRYPTE_DECRYPTE_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct sequence {
    char* tab;
    int longueur;
}sequence;

void init_seq(sequence* seq, int LMAX);

void affiche(sequence* seq);



void decal_vers_droite(sequence* seq, int n);
void decal_vers_gauche(sequence* seq, int n);

void echange_seq(sequence* seq, int i, int j);

void encrypte(sequence* txt, sequence* enc);
void decrypte(sequence* txt, sequence* enc);

void crypteSeq(sequence* Input, sequence* Output, int LMAX);
void decrypteSeq(sequence* Input, sequence* Output, int LMAX);

void cryptAssoc(sequence* Input, sequence* Output, int LMAX);
void decryptAssoc(sequence* Input, sequence* Output, int LMAX);

void decrypte_OneMillion(sequence* txt, sequence* enc); //uniquement pour OneMillion pour faire juste 100 tours de boucle

#endif