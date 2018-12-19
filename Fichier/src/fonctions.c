#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fonctions.h"

void SSL(int instruct,Registre* reg){

}

void NOP(int instruct,Registre* reg){

}

void ROTR(int instruct,Registre* reg){

}

void SRL(int instruct,Registre* reg){

}

void MFHI(int instruct,Registre* reg){

}

void MHLO(int instruct,Registre* reg){

}

void MULT(int instruct,Registre* reg){

}

void DIV(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = (instruct >> 16)%0x20;

  EcrireRegistre(&regi, 33, (LireRegistre(reg, operande1)/LireRegistre(reg, operande2)));
  EcrireRegistre(&regi, 32, (LireRegistre(reg, operande1)%LireRegistre(reg, operande2)));
}

void ADD(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = (instruct >> 16)%0x20;
  int result = (instruct >> 11)%0x20;

  EcrireRegistre(&regi, result, (LireRegistre(reg, operande1) + LireRegistre(reg, operande2)));
}

void SUB(int instruct,Registre* reg){

}

void AND(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = (instruct >> 16)%0x20;
  int result = (instruct >> 11)%0x20;

  EcrireRegistre(reg, result, (LireRegistre(reg, operande1) && LireRegistre(reg, operande2)));
}

void OR(int instruct,Registre* reg){

}

void XOR(int instruct,Registre* reg){

}

void SLT(int instruct){

}

void jump(int instruct){
  int index_registre; //opérande de l'instruction Jump

//  printf("%x\n", instruct);
  index_registre = instruct%0x04000000; //garde uniquement les 26 premiers bits
  index_registre = index_registre << 2; //décale à gauche pour retrouver l'adresse pointé par l'instruction
//  printf("%x\n", index_registre);

  EcrireRegistre(&regi, 34, index_registre);
}

void BEQ(int instruct){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&regi, operande1) == LireRegistre(&regi, operande2)){
    EcrireRegistre(&regi, 34, (LireRegistre(&regi, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BNE(int instruct){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&regi, operande1) != LireRegistre(&regi, operande2)){
    EcrireRegistre(&regi, 34, (LireRegistre(&regi, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BLEZ(int instruct){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&regi, operande1) <= LireRegistre(&regi, operande2)){
    EcrireRegistre(&regi, 34, (LireRegistre(&regi, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BGTZ(int instruct){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&regi, operande1) > LireRegistre(&regi, operande2)){
    EcrireRegistre(&regi, 34, (LireRegistre(&regi, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void ADDI(int instruct){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = instruct%0x010000;
  int result = (instruct >> 16)%0x20;

  EcrireRegistre(&regi, result, (LireRegistre(&regi, operande1) + operande2));
}

void LUI(int instruct){

}

void LW(int instruct){

}

void SW(int instruct){

}

void lireCodeHexa(){
  //tableau de int contenant la ligne d'instruction
  int instruct;
  int carrac;
  int operateur = 0; //variable récupérant l'opérateur de l'instruction
  //Ouverture du fichier avec les codes hexa


  fichier = fopen("assembleur_hexa.txt","r");

  if(fichier != NULL){
    do{
      fscanf(fichier, "%x", &instruct);
      printf("%x\n", instruct);

      operateur = instruct>>26;
      switch (operateur) {
        case 0x00:
          operateur = instruct%32;
          switch (operateur) {
            case 0x00:
              if(instruct != 0x00) SSL(instruct);
              else NOP(instruct);
              break;

            case 0x02:
              operateur = instruct>>21;
              if(operateur == 1) ROTR(instruct);
              else SRL(instruct);
              break;

            case 0x0C: SYSCALL(instruct);break;

            case 0x10: MFHI(instruct);break;

            case 0x12: MHLO(instruct);break;

            case 0x18: MULT(instruct);break;

            case 0x1A: DIV(instruct);break;

            case 0x20: ADD(instruct);break;

            case 0x22: SUB(instruct);break;

            case 0x24: AND(instruct);break;

            case 0x25: OR(instruct);break;

            case 0x26: XOR(instruct);break;

            case 0x2A: SLT(instruct);break;
          }

        case 0x02: jump(instruct);break;

        case 0x04: BEQ(instruct);break;

        case 0x05: BNE(instruct);break;

        case 0x06: BLEZ(instruct);break;

        case 0x07: BGTZ(instruct);break;

        case 0x08: ADDI(instruct);break;

        case 0x0F: LUI(instruct);break;

        case 0x23: LW(instruct);break;

        case 0x2B: SW(instruct);break;
      }
      carrac = fgetc(fichier);
    }while(carrac != '\n' || fgetc(fichier) != EOF);
    fclose(fichier);

  }
  else{
    printf("impossible d'ouvrir ce fichier\n");
  }
}
