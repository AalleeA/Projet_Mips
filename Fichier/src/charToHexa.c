#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Read.h"
#include "charToHexa.h"
#include "ecritureFichier.h"

char instructionJ [NBINSTRUCTIONJ * 2][7] = {
    {"J"}, {"000010"},
    {"JAL"}, {"000011"}
  };

  char binaireToHexa[33][5] = {
    {"0000"},{"0"},
    {"0001"},{"1"},
    {"0010"},{"2"},
    {"0011"},{"3"},
    {"0100"},{"4"},
    {"0101"},{"5"},
    {"0110"},{"6"},
    {"0111"},{"7"},
    {"1000"},{"8"},
    {"1001"},{"9"},
    {"1010"},{"A"},
    {"1011"},{"B"},
    {"1100"},{"C"},
    {"1101"},{"D"},
    {"1110"},{"E"},
    {"1111"},{"F"},
  };


  /*
  * On reçoit un tableau de type InstructionBrut
  * Si l'element Instruc de l'InstructionBrut est == NULL alors fin du tableau
  */

void charToHexa( InstructionBrut instruction[]){//Fonction de redirection

  int i = 0;
  while(instruction[i].Instruc != NULL){//arret lorsque plus d'instructions

    char resultatHexa [9] = {0};//8 caractere d'instruction, + 1 pour la sentinelle
    char resultatBinaire[33] = {0};

    //Cas instruction System, pas de parametre
    if(instruction[i].Operande1 == NULL){



    }

    //séparation instruction type J, I, r
    if(instruction[i].Operande2 == NULL){//dans le cas d'une instruction de type J

      convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);

    }
    /*if(instruction.Operande3 == NULL){//dans le cas d'une instruction de type I

      resultat = convertionInstructionTypeI(instruction.Instruc, instruction.Operande1, instruction.Operande2);

    }
    else{//dans le cas d'une instruction de type R

      resultat = convertionInstructionTypeR(instruction.Insctruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

    }*/
    i++;
  }
}

void convertionInstructionTypeJ (char* instruction, char* operande){

  int i = 0;
  int j = 0;
  int match = 1;
  int val=0;
  char sortie[33] = {0};
  printf("sortie init = %s\n", sortie);
  char reponse[9] = {0};

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

  printf("L'instruction %s correspond à la valeur: %s\n", instruction, instructionJ[(val+1)]);

  for(i=0; i<6; i++){
    sortie[i] = instructionJ[val+1][i];
  }
  printf("sortie tmp = %s\n", sortie );

  //convertion decimale operande
  int tailleOperande = calculTaille(operande);
  printf("taille = %d\n", tailleOperande);
  printf("op = %s\n", operande);
  int valeurOperande = convAphaToDec(operande, 1, tailleOperande);
  printf("val= %d\n", valeurOperande);

  //convertion binaire operande
  char opBin[26] = {0};
  for(i = 25; i >= 0; i--){

    if(valeurOperande >= (pow(2, i))){
      sortie[25 + 6 - i] = '1';
      valeurOperande -= pow(2,i);
      printf("ecris\n" );
    }else{
      sortie[25 + 6 - i] = '0';
    }
    printf("i = %d, valeurOperande = %d, sortie = %s\n", i, valeurOperande, sortie );

  }
  //racollage


  //convertion hexa---Fonctionnelle----OKAY->
  for(i=0; i<8; i ++){

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

  }
  // ---->OKAY

  //envoi de la chaine de caractere en hexa
  //ecrireFichier(reponse);
  printf("%s\n", reponse );

}
/*
char* convertionInstructionTypeI (char instruction, char operande1, char operande2){



}

char* convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/

//Ca marche
int convAphaToDec(char* chaine, int i, int taille){

  printf("dans la fct conv, chaine = %s, i = %d, taille = %d\n", chaine, i, taille);

  printf("val i = %d\n", chaine[taille - i] - 48);

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
