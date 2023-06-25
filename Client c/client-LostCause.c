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
    envoyer_recevoir("load LostCause", reponse.tab);
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);    
    decrypteSeq(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    envoyer_recevoir("help", reponse.tab); // on envoie message, et on reçoit la réponse du serveur
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);
    decrypteSeq(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    envoyer_recevoir("start", reponse.tab); // on envoie message, et on reçoit la réponse du serveur
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);
    decryptAssoc(&reponse, &message, MAXMSG);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    envoyer_recevoir("tout va bien", reponse.tab);
    reponse.longueur = strlen(reponse.tab);
    affiche(&reponse);

    free(reponse.tab);
    free(message.tab);
    printf (YEL"Fin de la connection au serveur\n"WHT);


    return 0;
}


