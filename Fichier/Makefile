#Label chemin d'accès
SRC_PATH = src/
BIN_PATH = bin/



Mips : $(BIN_PATH)MIPS.o $(BIN_PATH)Read.o $(BIN_PATH)ecritureFichier.o $(BIN_PATH)Registre.o $(BIN_PATH)charToHexa.o $(BIN_PATH)memoire.o
	gcc -o $@ -Wall $^ -lm
<<<<<<< HEAD
	#clear
	./Mips Test/Test1.txt
=======
	clear
	./Mips Test/Test4.txt
>>>>>>> 8c9dc42bcdf35e16d9e5e74cb185d6974792c06b

$(BIN_PATH)MIPS.o : $(SRC_PATH)MIPS.c

	gcc -Wall -c -o $@ $<

$(BIN_PATH)Read.o : $(SRC_PATH)Read.c $(SRC_PATH)Read.h

	gcc -Wall -c -o $@ $<

$(BIN_PATH)ecritureFichier.o : $(SRC_PATH)ecritureFichier.c $(SRC_PATH)ecritureFichier.h

	gcc -Wall -c -o $@ $<

$(BIN_PATH)Registre.o : $(SRC_PATH)Registre.c $(SRC_PATH)Registre.h

	gcc -Wall -c -o $@ $<

$(BIN_PATH)charToHexa.o : $(SRC_PATH)charToHexa.c $(SRC_PATH)charToHexa.h

	gcc -Wall -c -o $@ $< -lm

$(BIN_PATH)memoire.o : $(SRC_PATH)memoire.c $(SRC_PATH)memoire.h

	gcc -Wall -c -o $@ $<
