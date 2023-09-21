#include <stdio.h>

/*
 *  Auteur(s) :
 *  Date :
 *
 */


void decaln(char lettreLue, int n){
    char lettreSuivante3;

    if ('a'<= lettreLue && lettreLue <= 'z'){
        if (lettreLue + n > 'z'){
            int distance = 'z' - lettreLue;
            lettreSuivante3 = 'a' + (n-1 - distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }

    else if ('A'<= lettreLue && lettreLue <= 'Z'){
        if (lettreLue + n > 'Z'){
            int distance = 'Z' - lettreLue;
            lettreSuivante3 = 'A' + (n-1 - distance);
        }
        else 
            lettreSuivante3 = lettreLue + n;
    }
    else 
        lettreSuivante3 = lettreLue;
    
    printf("%c",lettreSuivante3);

}


void afficher_txt_secret(FILE *f, int n){
    char c;
    fscanf(f,"%c", &c);
    while(!feof(f)){
        decaln(c, n);
        fscanf(f,"%c",&c);
    }
}

int main (int argc, char* argv[])
{   int n;
    printf("entrer n : ");
    scanf("%d", &n);
    FILE* f;

    f = fopen(argv[1],"r");

    if (f == NULL){
        printf("Entrez un nom valde de fichier !! (comme premier argument)\n");
        return 1;
    }
    afficher_txt_secret(f, n);
    fclose(f);
    
    
    return 0;
}
