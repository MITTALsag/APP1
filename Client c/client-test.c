#include "client.h"
#include "decalage_de_cesar.h"
#include "encrypte_decrypte.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


int main(){
    sequence txt;
    sequence enc;
    init_seq(&txt, 100);
    init_seq(&enc, 100);
    char c[] = "abcd";
    strcat(txt.tab, c);

    decrypte_OneMillion(&enc, &txt);
    affiche(&enc);

    return 0;

}