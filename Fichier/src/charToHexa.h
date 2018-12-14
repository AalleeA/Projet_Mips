#ifndef charToHexa_H_
#define charToHexa_H_

#define NBINSTRUCTIONJ 2
#define NBINSTRUCTIONI 8
#define NBINSTRUCTIONR

void charToHexa( InstructionBrut instruction[]);//Fonction de redirection
void convertionInstructionTypeJ (char* instruction, char* operande1);
void convertionInstructionTypeI (char* instruction, char* operande1, char* operande2, char* operande3);
void convertionInstructionTypeR (char* instruction, char* operande1, char* operande2, char* operande3);

void convBinToHexa(char* reponse, char* sortie, int i);
int convAphaToDec(char* chaine, int i, int taille);
int calculTaille(char* chaine);

/*
* stockage des instructions de typeJ,
* tableau de tableau
* 2n  colonne, operande,
* 2n + 1 colonne, valeur en hexa
*/


#endif
