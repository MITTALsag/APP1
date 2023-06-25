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
    envoyer_recevoir("load crypteSeq", reponse.tab);
    // Notez qu'ici on n'utilise pas la reponse du serveur
    
    reponse.longueur = strlen(reponse.tab);  
        
    decrypte(&message, &reponse);
    //message.tab[message.longueur] = '\0';

    printf(YEL"Message secret :\n"WHT);
    //printf("%s\n", message.tab);
    affiche(&message);

    envoyer_recevoir("start", reponse.tab);
    reponse.longueur = strlen(reponse.tab);  

    decrypte(&message, &reponse);


    printf(YEL"Message secret :\n"WHT);
    affiche(&message);

    sequence Output;
    init_seq(&Output, MAXMSG);


    crypteSeq(&message, &Output, MAXMSG);
    //printf(YEL"Message apres le crypatge de cryptSeq :\n"WHT);
    //printf("%s\n", Output.tab);

    envoyer_recevoir(Output.tab, reponse.tab);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);
    decal_vers_gauche(&reponse, 83);
    reponse.longueur = strlen(reponse.tab);

    decrypteSeq(&reponse, &message, MAXMSG);

    printf(YEL"Message apres le decrypatge de decrypteSeq :\n"WHT);
    //printf("%s\n", message.tab);
    affiche(&message);
    
    envoyer_recevoir(message.tab, reponse.tab);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse.tab);
    

    free(reponse.tab);
    free(message.tab);
    free(Output.tab);

    printf (YEL"Fin de la connection au serveur\n"WHT);


    return 0;
}


