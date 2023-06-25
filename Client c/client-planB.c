#include "client.h"
#include "decalage_de_cesar.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP




int main() {
    char reponse[MAXREP]; // pour stocker la réponse du serveur
    //char message[MAXMSG]; // pour stocker le message à envoyer au serveur

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(false);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12113639 MITTAL", reponse);
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse);

    envoyer_recevoir("load planB", reponse);
    //printf (YEL "Réponse du serveur:\n");
    //printf(WHT "%s\n", reponse);
        
    //lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir("help", reponse); // on envoie message, et on reçoit la réponse du serveur
    printf (YEL "Réponse du serveur: ");
    printf(RED "%s\n", reponse);



    printf(YEL"Message du help :\n"WHT);
    int i = reponse[0] - 'C'; //equation : 'C' + i = reponse[0]
    printf(RED"Le decalage est de %d lettre\n"WHT, i);
    afficher_txt_secret(reponse, -i);

//Pour essayer tout les decalage
/*
    for (int i = 0 ; i < 27 ; i++){
        afficher_txt_secret(reponse, i);
        printf(GRN"*-----------------------------*\n\n\n"WHT);
    }
*/

    envoyer_recevoir("start", reponse);
    printf (YEL "Réponse du serveur:\n");
    printf(WHT "%s\n", reponse);

    char code_avant[20] = "hasta la revolucion";
    char code_apres[20];
    mettre_dans_tab_txt_secret(code_avant, -i, code_apres);
    printf("%s\n", code_apres);


    envoyer_recevoir(code_apres, reponse);
    //printf (YEL "Réponse du serveur:\n");
    //printf(WHT "%s\n", reponse);

    printf(YEL"Message apres le code :\n"WHT);
    afficher_txt_secret(reponse, -i);

    printf (YEL "Fin de la connection au serveur\n");
    return 0;
}
