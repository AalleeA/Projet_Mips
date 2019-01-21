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

char* charToHexa( InstructionBrut instruction[]){//Fonction de redirection
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

        result = convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);

      }else{
        if((instruction[i].Operande3 == NULL)||(instruction[i].Operande3[0] != "$")){//dans le cas d'une instruction de type I

          result = convertionInstructionTypeI(instruction[i].Instruc, instruction[i].Operande1, instruction[i].Operande2, instruction[i].Operande3);

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

char* convertionInstructionTypeJ (char* instruction, char* operande){

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
  return reponse;
}

//on rentre bien dedans
void convertionInstructionTypeI (char* instruction, char* operande1, char* operande2, char* operande3){

  /*
  *Dans l'ordre
  * - Récupérer l'opérande correpondante
  * - Reconnaitre le type I qu'on a, classique/ rt = 0 / rs = 0 / avec base (en utilisant une variable lors de la recherche dans le tableau)
  * - modifier les operandes si besoin
  * - Convertir en hexa comme avant
  */

  //recherche de l'instruction
  int i, j, val = 0;
  for(i = 0; i < NBINSTRUCTIONI * 2; i += 2){

    int  match = 1;
    while ((instruction[j] != '\0') && (match == 1)) {//verifie que l'instruction soit la meme, caractere par caractere
      if( instruction[j] != instructionI[i][j]){//teste le caractere i
        match = 0;
        printf("pas la bonne instruction,\n instruction de base : %s,\n instruction pas valide : %s\n", instruction, instructionI[i] );
      }
      j++;
    }
  if(match == 1){ val = i; }
  printf("val = %d\n", val);

  }

  printf("instruction I : %s = %s\n", instruction, instructionI[val + 1] );

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
