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
<<<<<<< HEAD
int main(int argc, char const *argv[]) {
  InstructionBrut operation = {"ADDI", "$12","$0","4530"};
  InstructionBrut operation1[] = {operation, NULL};
  charToHexa(&operation1);
  return 0;
}
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
void charToHexa( InstructionBrut instruction[]){//Fonction de redirection
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

        }
        else{//dans le cas d'une instruction de type R

          convertionInstructionTypeR(instruction[i].Instruc, instruction[i].Operande1, instruction[i].Operande2, instruction[i].Operande3);

        }
      }
    }
    i++;
  }
  //return result;
}

void convertionInstructionTypeJ (char* instruction, char* operande){

  int valop1 = 0;
  for(int i = 0; i <= strlen(operande)-1; i++){
    valop1 += (*(operande+i) - '0') * pow(10, strlen(operande) - i - 1 );
  }
  //recherche de l'instruction
  int j, val = 0;
  for(int i = 0; i < NBINSTRUCTIONJ * 2; i += 2){

    if(!strcmp(instruction,instructionJ[i])){//strcmp renvoi 0 si ==
      val = i;
    }
  }

  //Calcul valeur operande
  int valeurInstruct = 0;
  for(int i = 0; i < 6; i++){

    valeurInstruct += (instructionI[val+1][i] - 48) * pow(2, 5 - i );
  }

<<<<<<< HEAD
  int rep;
  switch (valeurInstruct) {
    case 0x02://J
      rep = (valeurInstruct<<26) + valop1;
      break;
    case 0x03://JAL
      rep = (valeurInstruct<<26) + valop1;
      break;
  }

=======
  int rep = 0;

  rep = (valeurInstruct<<26) + valop1;


  printf("%x\n",rep);
  ecrireFichier(rep);
>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
}

//on rentre bien dedans
void convertionInstructionTypeI (char* instruction, char* operande1, char* operande2, char* operande3){

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
<<<<<<< HEAD
  printf("taille = %d\n",strlen(operande1) );
  printf("operande1 = %d\n", valop1);
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
  if(*operande2 == '$'){
    operande2++;
  }
  int valop2 = 0;
  for(i = 0; i <= strlen(operande2)-1; i++){
    valop2 += (*(operande2+i) - '0') * pow(10, strlen(operande2) - i - 1 );
  }
<<<<<<< HEAD
  printf("operande2 = %d\n", valop2);
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
  int valop3 = 0;
  if(operande3 != NULL){
    if(*operande3 == '$'){
      operande3++;
    }
    for(i = 0; i <= strlen(operande3)-1; i++){
      valop3 += (*(operande3+i) - '0') * pow(10, strlen(operande3) - i  - 1);
    }
<<<<<<< HEAD
    printf("operande3 = %d\n", valop3);
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
  }

  //recherche de l'instruction
  int j, val = 0;
  for(i = 0; i < NBINSTRUCTIONI * 2; i += 2){

    if(!strcmp(instruction,instructionI[i])){//strcmp renvoi 0 si ==
      val = i;
    }

  }
<<<<<<< HEAD
  printf("instruction I : %s = %s\n", instruction, instructionI[val + 1] );
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
  //Calcul valeur operande
  int valeurInstruct = 0;
  for(i = 0; i < 6; i++){

    valeurInstruct += (instructionI[val+1][i] - 48) * pow(2, 5 - i );
  }

<<<<<<< HEAD
  printf("Valeur = %x\n", valeurInstruct);
=======

>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164
  //OKAY

  //Redecoupage
  int rep;
<<<<<<< HEAD
  switch (valeurInstruct) {
    case 0x08://ADDI
      rep = (valeurInstruct<<26) + (valop1<<21) + (valop2<<16) + (valop3);
      break;
  }

  printf("%x\n", rep);
=======
  char sortie[33] = {0};
  rep = (valeurInstruct<<26) + (valop1<<16) + (valop2<<21) + (valop3);
  ecrireFichier(rep);



>>>>>>> c41fc7739f089bf12d9455c4c33e50270a0c7164


}

void convertionInstructionTypeR (char* instruction, char* operande1, char* operande2, char* operande3){

  int i;
  if(*operande1 == '$'){
    operande1++;
  }
  int valop1 = 0;
  for(i = 0; i <= strlen(operande1)-1; i++){
    valop1 += (*(operande1+i) - '0') * pow(10, strlen(operande1) - i - 1 );
  }
  if(*operande2 == '$'){
    operande2++;
  }
  int valop2 = 0;
  for(i = 0; i <= strlen(operande2)-1; i++){
    valop2 += (*(operande2+i) - '0') * pow(10, strlen(operande2) - i - 1 );
  }
  int valop3 = 0;
  if(*operande3 == '$'){
    operande3++;
  }
  for(i = 0; i <= strlen(operande3)-1; i++){
    valop3 += (*(operande3+i) - '0') * pow(10, strlen(operande3) - i  - 1);
  }

  int j, val = 0;
  for(i = 0; i < NBINSTRUCTIONR * 2; i += 2){

    if(!strcmp(instruction,instructionR[i])){//strcmp renvoi 0 si ==
      val = i;
    }
  }
  //Redecoupage
  int valeurInstruct = 0;
  for(i = 0; i < 6; i++){
    valeurInstruct += (instructionI[val+1][i] - 48) * pow(2, 5 - i );
  }

  int rep;
  switch (valeurInstruct) {
    case 0x20://ADD
      rep = (valeurInstruct<<26) + (valop1<<21) + (valop2<<16) + (valop3);
      break;
  }

  printf("%x\n", rep);

}

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
