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
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    envoyer_recevoir("load projetX", reponse);
    printf (YEL "Réponse du serveur:\n");
    printf(WHT "%s\n", reponse);
        
    //lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir("help", reponse); // on envoie message, et on reçoit la réponse du serveur
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse);

    printf(YEL"Message du help :\n"WHT);
    afficher_txt_secret(reponse, 21);

    envoyer_recevoir("start", reponse);
    printf (YEL "Réponse du serveur:\n");
    printf(WHT "%s\nveni vidi vici\n", reponse);

    envoyer_recevoir("veni vidi vici", reponse);
    printf (YEL "Réponse du serveur:\n");
    printf(WHT "%s\n", reponse);
    
    printf (YEL "Fin de la connection au serveur\n");
    return 0;
}
