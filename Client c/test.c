#include "encrypte_decrypte.h"
#include <string.h>


int main(){
    sequence reponse; // pour stocker la réponse du serveur
    sequence message; // pour stocker le message à envoyer au serveur

    init_seq(&reponse, 1000);
    init_seq(&message, 1000);

    //ne pas oublier le strcpy !!!! 
    //A DEMANDER PQ SI ON = CA MARCHE  PAS
    // POUR VERIF ENLEVER LE COMMENTAIRE DE L'AFFICHAGE DANS LA FONCTION ENCRYPTE
    strcpy(message.tab, "Petit message court."); 
    message.longueur = strlen(message.tab);

    encrypte(&message, &reponse);
}