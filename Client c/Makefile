CC=clang
CFLAGS=-g -Wall -Wextra -Werror

EXEC=client-introduction client-tutoriel client-interactif client-TUTORIEL2 client-crypteMove client-BayOfPigs client-crypteSeq client-projetX client-planB client-test client-Northwoods client-OneMillion client-LostCause

all: $(EXEC)

client-test : client-test.o client.o decalage_de_cesar.o encrypte_decrypte.o

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-introduction: client-introduction.o client.o

client-TUTORIEL2: client-TUTORIEL2.o client.o

client-projetX : client-projetX.o client.o decalage_de_cesar.o

client-planB : client-planB.o client.o decalage_de_cesar.o

client-OneMillion : client-OneMillion.o client.o decalage_de_cesar.o encrypte_decrypte.o

client-crypteMove : client-crypteMove.o client.o encrypte_decrypte.o

client-BayOfPigs : client-BayOfPigs.o client.o decalage_de_cesar.o encrypte_decrypte.o

client-crypteSeq : client-crypteSeq.o client.o encrypte_decrypte.o

client-Northwoods : client-Northwoods.o client.o encrypte_decrypte.o

client-LostCause : client-LostCause.o client.o encrypte_decrypte.o

client.o: client.c client.h

decalage_de_cesar.o: decalage_de_cesar.c decalage_de_cesar.h

encrypte_decrypte.o : encrypte_decrypte.c encrypte_decrypte.h 


clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
