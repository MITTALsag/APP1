#include "encrypte_decrypte.h"




void init_seq(sequence* seq, int LMAX){
    seq->tab = (char *)malloc(LMAX * sizeof(char));
}

//affiche la seqence complete (pas possible de faire juste printf("%s\n", seq) car cela ne prend pas en compte la longueure de la seqence)
void affiche(sequence* seq){
    for (int i = 0 ; i < seq->longueur ; i++){
        printf("%c", seq->tab[i]);
    }
    printf("\n");
}


//decal vers la droite les element de la seqence et les met n place plus loins
void decal_vers_droite(sequence* seq, int n){

    for (int i = seq->longueur-1 ; i >= 0 ; i--){
        seq->tab[i+n] = seq->tab[i];
    }
    seq->longueur += n;
}

//decal vers la gauche les element de la seqence et les met n place moins loins
void decal_vers_gauche(sequence* seq, int n){
    for (int i = 0 ; i < seq->longueur ; i++){
        seq->tab[i] = seq->tab[n+i];
    }
    seq->longueur -= n;
}

//fonction qui renvoie l'indice d'un element a chercher et -1 sinon
int recherche_et_indice (sequence* seq, char c){
    for(int i = 0 ; i < seq->longueur ; i++){
        if (seq->tab[i] == c)
            return i;
    }
    return -1;
}

void echange_seq(sequence* seq, int i, int j){
    char tmp = seq->tab[i];
    seq->tab[i] = seq->tab[j];
    seq->tab[j] = tmp;
}


void encrypte(sequence* txt, sequence* enc){
    enc->longueur=0;
    while (txt->longueur !=0){
        //initialisation de x et c comme dans l'enonce
        char c = txt->tab[0];
        int x = c % 8;

    /*
        printf("TXT :");
        affiche(txt);
        printf("ENC : ");
        affiche(enc);
        printf("C : %c\n\n", c);
    */
    
        //on met le premier element de txt a la fin de enc (1ere etape)
        enc->tab[enc->longueur] = c;
        enc->longueur++;
        if (x > txt->longueur-1){ //si x est plus grand que le nb d'element dans la sequance txt on decal que de 1
            decal_vers_gauche(txt, 1);
        }
        else {      //sinon on met les x premier element de txt a la fin de txt
            int i = 1;
            for (int j = 0 ; j < x ; j++){
                txt->tab[txt->longueur] = txt->tab[i];
                txt->longueur++;
                i++;
            }
            decal_vers_gauche(txt, x+1); //on decal de x+1 (le +1 est pour eliminer le caractere lu dans c)
        }
    }
}



void decrypte(sequence* txt, sequence* enc){
    txt->longueur=0;
    //int i = 1; //Pour voir le nb de tours de boucle
    while (enc->longueur != 0){
        //initialisation de x et c comme dans l'enonce
        char c = enc->tab[enc->longueur-1];
        int x = c % 8;
    /*
        printf("%d---TXT :", txt->longueur);
        affiche(txt);
        printf("%d----ENC : ", enc->longueur);
        affiche(enc);
        printf("C : %c\n\n", c);
    */
        if (txt->longueur > 0){
            if (txt->longueur <= x){
                decal_vers_droite(txt, 1);
            }
            else{
                decal_vers_droite(txt, x+1);
                for (int i = 1 ; i < x+1 ; i++){
                    txt->tab[i] = txt->tab[txt->longueur - (x+1) + i];
                }
                txt->longueur -=x;
            }
            txt->tab[0] = c;
            enc->longueur--;
        }
        else{
            txt->tab[0] = c;
            txt->longueur++;
            enc->longueur--;   
        }
    }

}


void crypteSeq(sequence* Input, sequence* Output, int LMAX){
    sequence deja_rencontrer;
    init_seq(&deja_rencontrer, LMAX);

    deja_rencontrer.longueur = 0;
    Output->longueur = 0;
    int i = 0;
    while (Output->longueur != Input->longueur){
        char c = Input->tab[i];

        //pour test voir le procesus pas a pas 
        //printf("Char: %c\n", c);


        int indice = recherche_et_indice(&deja_rencontrer, c);

        if (indice != -1){
            if (indice == 0){ //arrengement de c en prenant le caractère juste devant dansla seqence et si c'est 0 on prend le dernier
                c = deja_rencontrer.tab[deja_rencontrer.longueur - 1];      
            }
            else{
                c = deja_rencontrer.tab[indice - 1];
            }
            //placement de c a la fin de la sequence
            deja_rencontrer.tab[deja_rencontrer.longueur] = deja_rencontrer.tab[indice];
            deja_rencontrer.longueur++;
            for (int j = indice ; j < deja_rencontrer.longueur  ; j++){
                deja_rencontrer.tab[j] = deja_rencontrer.tab[j + 1];
            }
            deja_rencontrer.longueur--;
        }
        else{
            deja_rencontrer.tab[deja_rencontrer.longueur] = c;
            deja_rencontrer.longueur++;
        }
        Output->tab[i] = c;
        Output->longueur++;
        i++; 

        //pour test voir le procesus pas a pas 
        /*
        printf("Seq: ");
        affiche(&deja_rencontrer);
        printf("Output: ");
        affiche(Output);
        */
    }
    free(deja_rencontrer.tab);
}

void decrypteSeq(sequence* Input, sequence* Output, int LMAX){
    sequence deja_rencontrer;
    init_seq(&deja_rencontrer, LMAX);

    deja_rencontrer.longueur = 0;
    Output->longueur = 0;
    int i = 0;
    while (Output->longueur != Input->longueur){
        char c = Input->tab[i];

        //pour test voir le procesus pas a pas 
        //printf("Char: %c\n", c);


        int indice = recherche_et_indice(&deja_rencontrer, c);

        if (indice != -1){
            if (indice == 0){ //arrengement de c en prenant le caractère juste devant dansla seqence et si c'est 0 on prend le dernier
                c = deja_rencontrer.tab[deja_rencontrer.longueur - 1];
                //placement de c au debut de la sequence
                decal_vers_droite(&deja_rencontrer, 1);
                deja_rencontrer.tab[0] = deja_rencontrer.tab[deja_rencontrer.longueur -1];
                deja_rencontrer.longueur--;
            }
            else{
                c = deja_rencontrer.tab[indice - 1];
                //placement de c au debut de la sequence
                decal_vers_droite(&deja_rencontrer, 1);

                deja_rencontrer.tab[0] = deja_rencontrer.tab[indice];

                for (int j = indice ; j < deja_rencontrer.longueur ; j++){
                    deja_rencontrer.tab[j] = deja_rencontrer.tab[j + 1];
                }
                deja_rencontrer.longueur--;
            }
        }
        else{
            decal_vers_droite(&deja_rencontrer, 1);
            deja_rencontrer.tab[0] = c;
        }
        Output->tab[i] = c;
        Output->longueur++;
        i++;

        //pour test voir le procesus pas a pas      
        /*
        printf("Seq: ");
        affiche(&deja_rencontrer);
        printf("Output: ");
        affiche(Output);
        printf("*---------------------------*\n");
        */
    }
    free(deja_rencontrer.tab);
}


void cryptAssoc(sequence* Input, sequence* Output, int LMAX){
    sequence deja_rencontrer;
    init_seq(&deja_rencontrer, LMAX);
    sequence assoc;
    init_seq(&assoc, LMAX);
    deja_rencontrer.longueur = 0;    
    assoc.longueur = 0;
    Output->longueur = 0;

    int i = 0;
    while (Output->longueur != Input->longueur){
        char c = Input->tab[i];

        //pour test voir le procesus pas a pas 
        //printf("Char: %c\n", c);


        int indice = recherche_et_indice(&deja_rencontrer, c);

        if (indice != -1){
            if (indice == 0){ //arrengement de c en prenant le caractère juste devant dansla seqence et si c'est 0 on prend le dernier
                echange_seq(&assoc, indice, assoc.longueur - 1);
                c = assoc.tab[0];      
            }
            else{
                echange_seq(&assoc, indice, indice - 1);
                c = assoc.tab[indice];
            }
            //placement de c a la fin de la sequence
            deja_rencontrer.tab[deja_rencontrer.longueur] = deja_rencontrer.tab[indice];
            deja_rencontrer.longueur++;
            //placement de l'association de c a la fin
            assoc.tab[assoc.longueur] = assoc.tab[indice];
            assoc.longueur++;

            for (int j = indice ; j < deja_rencontrer.longueur  ; j++){
                deja_rencontrer.tab[j] = deja_rencontrer.tab[j + 1];
            }
            deja_rencontrer.longueur--;

            for (int j = indice ; j < assoc.longueur  ; j++){
                assoc.tab[j] = assoc.tab[j + 1];
            }
            assoc.longueur--;

        }
        else{
            deja_rencontrer.tab[deja_rencontrer.longueur] = c;
            deja_rencontrer.longueur++;
            assoc.tab[assoc.longueur] = c;
            assoc.longueur++;
        }
        Output->tab[i] = c;
        Output->longueur++;
        i++;

        //pour test voir le procesus pas a pas 
        /*
        printf("Seq: ");
        affiche(&deja_rencontrer);
        printf("Output: ");
        affiche(Output);
        */
    }
    free(assoc.tab);
    free(deja_rencontrer.tab);
}

void decryptAssoc(sequence* Input, sequence* Output, int LMAX){
    sequence deja_rencontrer;
    init_seq(&deja_rencontrer, LMAX);
    sequence assoc;
    init_seq(&assoc, LMAX);
    deja_rencontrer.longueur = 0;    
    assoc.longueur = 0;
    Output->longueur = 0;

    int i = 0;
    while (Output->longueur != Input->longueur){
        char c = Input->tab[i];

        //pour test voir le procesus pas a pas 
        //printf("Char: %c\n", c);


        int indice = recherche_et_indice(&deja_rencontrer, c);

        if (indice != -1){
            if (indice == 0){ //arrengement de c en prenant le caractère juste devant dans la seqence et si c'est 0 on prend le dernier
                echange_seq(&assoc, indice, assoc.longueur - 1);
                c = assoc.tab[indice];
            }
            else{
                echange_seq(&assoc, indice, indice - 1);
                c = assoc.tab[indice];
                //placement de c au debut de la sequence deja_rencontrer
                decal_vers_droite(&deja_rencontrer, 1);
                deja_rencontrer.tab[0] = deja_rencontrer.tab[indice+1];

                for (int j = indice + 1 ; j < deja_rencontrer.longueur ; j++){
                    deja_rencontrer.tab[j] = deja_rencontrer.tab[j + 1];
                }
                deja_rencontrer.longueur--;

                //placement de c au debut de la sequence assoc
                decal_vers_droite(&assoc, 1);
                assoc.tab[0] = assoc.tab[indice+1];

                for (int j = indice + 1 ; j < assoc.longueur ; j++){
                    assoc.tab[j] = assoc.tab[j + 1];
                }
                assoc.longueur--;
            }
        }
        else{
            if (deja_rencontrer.longueur == 0){
                deja_rencontrer.tab[0] = c;
                deja_rencontrer.longueur++;
                assoc.tab[0] = c;
                assoc.longueur++;
            }
            else{
                decal_vers_droite(&deja_rencontrer, 1);
                deja_rencontrer.tab[0] = c;
                decal_vers_droite(&assoc, 1);
                assoc.tab[0] = c;
            }
        }
        Output->tab[i] = c;
        Output->longueur++;
        i++;

        //pour test voir le procesus pas a pas      
        /*
        printf("Seq: ");
        affiche(&deja_rencontrer);
        printf("Output: ");
        affiche(Output);
        printf("*---------------------------*\n");
        */
    }
    free(deja_rencontrer.tab); 
    free(assoc.tab);
}

