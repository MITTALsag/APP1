#include "client.h"
#include "decalage_de_cesar.h"
#include "encrypte_decrypte.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP


//faire help..
int main() {
    sequence reponse; // pour stocker la réponse du serveur
    sequence message; // pour stocker le message à envoyer au serveur

    init_seq(&reponse, MAXREP);
    init_seq(&message, 1000000);

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(false);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    // connexion("im2ag-appolab.u-ga.fr", 443); 

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12113639 MITTAL", reponse.tab);
    envoyer_recevoir("load OneMillion", reponse.tab);
    // Notez qu'ici on n'utilise pas la reponse du serveur
    
    reponse.longueur = strlen(reponse.tab);
    decrypte(&message, &reponse);
    printf (YEL "Réponse du serveur: "WHT);
    affiche(&message);

    char* tab_aide = (char*)malloc(100 * sizeof(char));
    envoyer_recevoir("help", tab_aide);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", tab_aide);
    printf(MAG"%lu\n",strlen(tab_aide));

 
    char* clef = (char*)malloc(100 * sizeof(char));
    envoyer_recevoir("start", clef);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", clef);
    printf(MAG"%lu\n", strlen(clef));

    sequence texte;
    init_seq(&texte, 2000000);

    for (int i = 0 ; i < 9999 ; i++){
        strcat(texte.tab, tab_aide);
        texte.longueur +=100;
        //printf("%s\n", txt.tab);
    }
    strcat(texte.tab, clef);
    texte.longueur +=100;
    free(clef);
    free(tab_aide);


    printf("%d\n%c", texte.longueur, texte.tab[1000000-1]);
    //txt.tab[txt.longueur] = '\0';
    //txt.longueur++;

    decrypte(&message, &texte);
    printf("%d\n", message.longueur);
    message.tab[100] = '\0';
    affiche(&message);


    envoyer_recevoir(message.tab, reponse.tab);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse.tab);

    free(reponse.tab);
    free(message.tab);
    free(texte.tab);


    printf (YEL"Fin de la connection au serveur\n"WHT);



    return 0;
}
