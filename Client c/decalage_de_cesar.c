#include "decalage_de_cesar.h"


/*
 *  Auteur(s) : Sagar MITTAL
 *  Date :
 * ce fichier est un peu different du .c de decalage_Cesar dans le dossier parent (celuici prend un tableau pour decrypter alors que l'autre prend un fichier)
 */

#define MAX 1000


void decaln(char lettreLue, int n){
    char lettreSuivante3;

    if ('a'<= lettreLue && lettreLue <= 'z'){
        if (lettreLue + n > 'z'){
            int distance = 'z' - lettreLue;
            lettreSuivante3 = 'a' + (n-1 - distance);
        }
        else if ( lettreLue + n < 'a'){
            int distance = lettreLue - 'a' ;
            lettreSuivante3 = 'z' + (n+1 + distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }

    else if ('A'<= lettreLue && lettreLue <= 'Z'){
        if (lettreLue + n > 'Z'){
            int distance = 'Z' - lettreLue;
            lettreSuivante3 = 'A' + (n-1 - distance);
        }
        else if ( lettreLue + n < 'A'){
            int distance = lettreLue - 'A' ;
            lettreSuivante3 = 'Z' + (n-1 + distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }
    else 
        lettreSuivante3 = lettreLue;
    
    printf("%c",lettreSuivante3);

}


void afficher_txt_secret(char* tab, int n){
    int i = 0;
    while(tab[i] != '\0'){
        decaln(tab[i], n);
        i++;
    }
    printf("\n");
}

char decaln_dans_tab(char lettreLue, int n){
    char lettreSuivante3;

    if ('a'<= lettreLue && lettreLue <= 'z'){
        if (lettreLue + n > 'z'){
            int distance = 'z' - lettreLue;
            lettreSuivante3 = 'a' + (n-1 - distance);
        }
        else if ( lettreLue + n < 'a'){
            int distance = lettreLue - 'a' ;
            lettreSuivante3 = 'z' + (n+1 + distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }

    else if ('A'<= lettreLue && lettreLue <= 'Z'){
        if (lettreLue + n > 'Z'){
            int distance = 'Z' - lettreLue;
            lettreSuivante3 = 'A' + (n-1 - distance);
        }
        else if ( lettreLue + n < 'A'){
            int distance = lettreLue - 'A' ;
            lettreSuivante3 = 'Z' + (n-1 + distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }
    else 
        lettreSuivante3 = lettreLue;
    
    return lettreSuivante3;

}

void mettre_dans_tab_txt_secret(char* tab, int n, char* ou){
    int i = 0;
    //char retour[20];
    while(tab[i] != '\0'){
        char c = decaln_dans_tab(tab[i], n);

        sprintf(&ou[i], "%c", c);
        i++;

    }
}

