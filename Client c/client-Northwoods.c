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
    init_seq(&message, MAXMSG);

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(false);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    // connexion("im2ag-appolab.u-ga.fr", 443); 

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12113639 MITTAL", reponse.tab);
    envoyer_recevoir("load Northwoods", reponse.tab);
    // Notez qu'ici on n'utilise pas la reponse du serveur
    
    envoyer_recevoir("start", reponse.tab);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse.tab);

    printf(YEL"Message secret : "WHT);
    printf("hasta la victoria siempre\n");

    envoyer_recevoir("hasta la victoria siempre", reponse.tab);
    reponse.longueur = strlen(reponse.tab);  

    decrypteSeq(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    char code_alea[21] = {'\0'};
    for (int i = 0 ; i < 20; i++){
        code_alea[i] = message.tab[message.longueur - 29 + i];
    }
    //printf("%s\n", code_alea);

    envoyer_recevoir(code_alea, reponse.tab);
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);
    reponse.longueur = strlen(reponse.tab);  

    decrypteSeq(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    char code2[] = "There will be no Nineteen Eighty-Four";
    int code2_len = strlen(code2);
    for (int i = 0 ; i <= code2_len ; i++){
        reponse.tab[i] = code2[i];
    }
    reponse.longueur = code2_len ;
    //affiche(&reponse);

    crypteSeq(&reponse, &message, MAXMSG);
    //affiche(&message);
    message.tab[message.longueur] = '\0';
    envoyer_recevoir(message.tab, reponse.tab);
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);
    decal_vers_gauche(&reponse, 24);
    reponse.longueur = strlen(reponse.tab);

    decrypteSeq(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    free(reponse.tab);
    free(message.tab);

    printf (YEL"Fin de la connection au serveur\n"WHT);


    return 0;
}


