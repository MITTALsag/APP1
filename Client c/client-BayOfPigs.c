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


    init_seq(&reponse, 2 * MAXREP);
    init_seq(&message, 2 * MAXMSG);


    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(false);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    // connexion("im2ag-appolab.u-ga.fr", 443); 

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 12113639 MITTAL", reponse.tab);
    envoyer_recevoir("load BayOfPigs", reponse.tab);
    // Notez qu'ici on n'utilise pas la reponse du serveur
    
    afficher_txt_secret(reponse.tab, 21);
    
    envoyer_recevoir("help", reponse.tab); // on envoie message, et on reçoit la réponse du serveur
    //printf(YEL"Message du help : \n"WHT);
    //afficher_txt_secret(reponse.tab, 21);

    envoyer_recevoir("start", reponse.tab);
    reponse.longueur = strlen(reponse.tab);    
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    decrypte(&message, &reponse);
    printf(YEL"Message secret :\n"WHT);
    affiche(&message);
    //printf("%s\n\n", message.tab);

    char* tmp_tab = "Patria o muerte";
    int len = strlen(tmp_tab);
    for (int i = 0 ; i < len ; i++){
        reponse.tab[i] = tmp_tab[i];
    }
    reponse.longueur = len;
    
    encrypte(&reponse, &message);

    message.tab[message.longueur] = '\0';
    message.longueur++;
    printf(YEL"Code sercret :\n"WHT);
    affiche(&message);

    envoyer_recevoir(message.tab, reponse.tab);
    //printf (YEL "Réponse du serveur: ");
    //printf(WHT "%s\n", reponse.tab);

    reponse.longueur = strlen(reponse.tab);   

    decrypte(&message, &reponse);
        

    printf(YEL"Message secret apres le code:\n"WHT);
    affiche(&message);

    envoyer_recevoir(message.tab, reponse.tab);
    printf (YEL "Réponse du serveur: ");
    printf(WHT "%s\n", reponse.tab);

    free(reponse.tab);
    free(message.tab);
    
    printf (YEL"Fin de la connection au serveur\n"WHT);

    return 0;
}
