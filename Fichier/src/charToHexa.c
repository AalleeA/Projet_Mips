#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Read.h"
#include "charToHexa.h"
#include "ecritureFichier.h"
#include "variableConvertion.h"

  /*
  * On reçoit un tableau de type InstructionBrut
  * Si l'element Instruc de l'InstructionBrut est == NULL alors fin du tableau
  */
int main(int argc, char const *argv[]) {
  InstructionBrut operation = {"ADDI", "$12","$0","4530"};
  InstructionBrut operation1[] = {operation, NULL};
  charToHexa(&operation1);
  return 0;
}
void charToHexa( InstructionBrut instruction[]){//Fonction de redirection
  char* result;
  int i = 0;
  while(instruction[i].Instruc != NULL){//arret lorsque plus d'instructions

    char resultatHexa [9] = {0};//8 caractere d'instruction, + 1 pour la sentinelle
    char resultatBinaire[33] = {0};

    //Cas instruction System, pas de parametre
    if(instruction[i].Operande1 == NULL){



    }else{
      //séparation instruction type J, I, r
      if(instruction[i].Operande2 == NULL){//dans le cas d'une instruction de type J

        convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);

      }else{
        if((instruction[i].Operande3 == NULL)||(instruction[i].Operande3[0] != "$")){//dans le cas d'une instruction de type I

          convertionInstructionTypeI(instruction[i].Instruc, instruction[i].Operande1, instruction[i].Operande2, instruction[i].Operande3);

        }/*
        else{//dans le cas d'une instruction de type R

          resultat = convertionInstructionTypeR(instruction.Insctruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

        }*/
      }
    }
    i++;
  }
  return result;
}

void convertionInstructionTypeJ (char* instruction, char* operande){

  int i = 0;
  int j = 0;
  int match = 1;
  int val=0;
  char sortie[33] = {0};
  char reponse[9] = {0};

  //recherche de l'instruction
  for(i = 0; i < NBINSTRUCTIONJ * 2; i += 2){//on fait défiler le tableau d'instruction

    if( strlen(instruction) == strlen(instructionJ[i])){//si l'instruction testée a la meme taille que celle dans le tableau
    j = 0;
    match = 1;
      while ((j < strlen(instruction)) && (match == 1)) {//verifie que l'instruction soit la meme, caractere par caractere
        if( instruction[j] != instructionJ[i][j]){//teste le caractere i
          match = 0;
        }
        j++;
      }
    if(match == 1){ val = i; }
    }

  }

  for(i=0; i<6; i++){
    sortie[i] = instructionJ[val+1][i];
  }

  //convertion decimale operande
  int tailleOperande = calculTaille(operande);
  int valeurOperande = convAphaToDec(operande, 1, tailleOperande);

  //convertion binaire operande
  char opBin[26] = {0};
  for(i = 25; i >= 0; i--){

    if(valeurOperande >= (pow(2, i))){
      sortie[25 + 6 - i] = '1';
      valeurOperande -= pow(2,i);
    }else{
      sortie[25 + 6 - i] = '0';
    }
  }

   convBinToHexa(reponse, sortie, 0);

  //envoi de la chaine de caractere en hexa
  //ecrireFichier(reponse);
  printf("%s\n", reponse );

}

//on rentre bien dedans
/* char* convertionInstructionTypeI (char* instruction, char* operande1, char* operande2, char* operande3){

  /*
  *Dans l'ordre
  * - Récupérer l'opérande correpondante
  * - envoi sur la fct correpondante
  */
  int i;
  if(*operande1 == '$'){
    operande1++;
  }
  int valop1 = 0;
  for(i = 0; i <= strlen(operande1)-1; i++){
    valop1 += (*(operande1+i) - '0') * pow(10, strlen(operande1) - i - 1 );
  }
  printf("taille = %d\n",strlen(operande1) );
  printf("operande1 = %d\n", valop1);
  if(*operande2 == '$'){
    operande2++;
  }
  int valop2 = 0;
  for(i = 0; i <= strlen(operande2)-1; i++){
    valop2 += (*(operande2+i) - '0') * pow(10, strlen(operande2) - i - 1 );
  }
  printf("operande2 = %d\n", valop2);
  int valop3 = 0;
  if(operande3 != NULL){
    if(*operande3 == '$'){
      operande3++;
    }
    for(i = 0; i <= strlen(operande3)-1; i++){
      valop3 += (*(operande3+i) - '0') * pow(10, strlen(operande3) - i  - 1);
    }
    printf("operande3 = %d\n", valop3);
  }

  //recherche de l'instruction
  int j, val = 0;
  for(i = 0; i < NBINSTRUCTIONI * 2; i += 2){

    if(!strcmp(instruction,instructionI[i])){//strcmp renvoi 0 si ==
      val = i;
    }

  }
  printf("instruction I : %s = %s\n", instruction, instructionI[val + 1] );
  //Calcul valeur operande
  int valeurInstruct = 0;
  for(i = 0; i < 6; i++){

    valeurInstruct += (instructionI[val+1][i] - 48) * pow(2, 5 - i );
  }

  printf("Valeur = %x\n", valeurInstruct);
  //OKAY

  //Redecoupage
  int rep;
  switch (valeurInstruct) {
    case 0x08://ADDI
      rep = (valeurInstruct<<26) + (valop1<<21) + (valop2<<16) + (valop3);
      break;
  }

  printf("%x\n", rep);


}
/*
void convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/

//Ca marche
//on fournit la chaine de reponse (8 caractere hexa), la chaine de 32 bits ainsi que la position actuelle où on se trouve dan sla lecture de celle-ci (i)
void convBinToHexa(char* reponse, char* sortie, int i){

  if(i < 8){

    int j =0;
    char tabTest[5] = {sortie[4*i], sortie[(4*i) + 1], sortie[(4*i) + 2], sortie[(4*i) + 3]};
    char** pointeur = NULL;
    while(pointeur == NULL){//on suppose le bloc de caractere traite juste

      if(strcmp(binaireToHexa[2*j], tabTest) == 0){//meme chaine

        pointeur = &binaireToHexa[(2*j)+1];//pointe vers l'entree du tableau correspondant à la traduction

      }

      j++;

    }

    reponse[i] = *pointeur;

    convBinToHexa(reponse, sortie, i+1);

  }
}

//Ca marche
int convAphaToDec(char* chaine, int i, int taille){

  if (i == taille){
    return(chaine[0] - 48);
  }else{
    return((chaine[taille - i] - 48) + (10 * convAphaToDec(chaine, i+1, taille)));
  }

}

//Ca marche
int calculTaille(char* chaine){//mettre des chaines de tailles fixes!!!

  int i = 0;
  while(chaine[i] != '\0'){

    i++;

  }

  return(i);

}
