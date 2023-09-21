#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

void min_vers_MAJ(char* min, char* maj){
    unsigned long i;
    for(i = 0 ; i<strlen(min) ; i++){
        if (min[i] >= 'a' && min[i] <= 'z') {maj[i] = min[i] + ('A' - 'a');}
        else {maj[i] = min[i];}
    }
    maj[i]= '\0';
}


int main() {
    char reponse[MAXREP]; // pour stocker la réponse du serveur
    char message[MAXMSG]; // pour stocker le message à envoyer au serveur

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

    envoyer_recevoir("load tutorielFORT", reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);
        
    //lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir("depart", reponse); // on envoie message, et on reçoit la réponse du serveur
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    //lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir("OK", reponse); // on envoie message, et on reçoit la réponse du serveur
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    //lire_clavier(message);   // message tapé au clavier
    envoyer_recevoir("OUI", reponse); // on envoie message, et on reçoit la réponse du serveur
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    // Notez qu'ici on n'utilise pas la reponse du serveur
    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse); // on envoie message, et on reçoit la réponse du serveur
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);
    
    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    min_vers_MAJ(reponse, message);
    printf("%s\n", message);
    envoyer_recevoir(message, reponse);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse);

    printf (YEL "Fin de la connection au serveur\n");
    return 0;
}
