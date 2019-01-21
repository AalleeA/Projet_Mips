#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registre.h"
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

  EcrireRegistre(&reg, 33, (LireRegistre(reg, operande1)/LireRegistre(reg, operande2)));
  EcrireRegistre(&reg, 32, (LireRegistre(reg, operande1)%LireRegistre(reg, operande2)));
}

void ADD(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = (instruct >> 16)%0x20;
  int result = (instruct >> 11)%0x20;

  EcrireRegistre(&reg, result, (LireRegistre(&reg, operande1) + LireRegistre(&reg, operande2)));
}

void SUB(int instruct,Registre* reg){

}

void AND(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = (instruct >> 16)%0x20;
  int result = (instruct >> 11)%0x20;

  EcrireRegistre(&reg, result, (LireRegistre(&reg, operande1) && LireRegistre(&reg, operande2)));
}

void OR(int instruct,Registre* reg){

}

void XOR(int instruct,Registre* reg){

}

void SLT(int instruct,Registre* reg){

}

void jump(int instruct,Registre* reg){
  int index_registre; //opérande de l'instruction Jump

//  printf("%x\n", instruct);
  index_registre = instruct%0x04000000; //garde uniquement les 26 premiers bits
  index_registre = index_registre << 2; //décale à gauche pour retrouver l'adresse pointé par l'instruction
//  printf("%x\n", index_registre);

  EcrireRegistre(&reg, 34, index_registre);
}

void BEQ(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&reg, operande1) == LireRegistre(&reg, operande2)){
    EcrireRegistre(&reg, 34, (LireRegistre(&reg, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BNE(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&reg, operande1) != LireRegistre(&reg, operande2)){
    EcrireRegistre(&reg, 34, (LireRegistre(&reg, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BLEZ(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&reg, operande1) <= LireRegistre(&reg, operande2)){
    EcrireRegistre(&reg, 34, (LireRegistre(&reg, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void BGTZ(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int offset = instruct%0x010000;
  int operande2 = (instruct >> 16)%0x20;

  if(LireRegistre(&reg, operande1) > LireRegistre(&reg, operande2)){
    EcrireRegistre(&reg, 34, (LireRegistre(&reg, 34)+offset)); //modifie le PC en ajoutant l'offset
  }
}

void ADDI(int instruct,Registre* reg){
  int operande1 = (instruct >> 21)%0x20;
  int operande2 = instruct%0x010000;
  int result = (instruct >> 16)%0x20;

  EcrireRegistre(&reg, result, (LireRegistre(&reg, operande1) + operande2));
}

void LUI(int instruct,Registre* reg){

}

void LW(int instruct,Registre* reg){

}

void SW(int instruct,Registre* reg){

}

void Execute(int i,int* mem, Registre* reg){
  //tableau de int contenant la ligne d'instruction
  int instruct;
  int carrac;
  int operateur = 0; //variable récupérant l'opérateur de l'instruction
  //Ouverture du fichier avec les codes hexa

      instruct = *(mem+i)<<28;
      instruct += *(mem+i+1)<<24;
      instruct += *(mem+i+2)<<20;
      instruct += *(mem+i+3)<<16;
      instruct += *(mem+i+4)<<12;
      instruct += *(mem+i+5)<<8;
      instruct += *(mem+i+6)<<4;
      instruct += *(mem+i+7);
      operateur = instruct>>26;
      switch (operateur) {
        case 0x00:
          operateur = instruct%32;
          switch (operateur) {
            case 0x00:
              if(instruct != 0x00) SSL(instruct,reg);
              else NOP(instruct,reg);
              break;

            case 0x02:
              operateur = instruct>>21;
              if(operateur == 1) ROTR(instruct,reg);
              else SRL(instruct);
              break;

            case 0x0C: SYSCALL(instruct,reg);break;

            case 0x10: MFHI(instruct,reg);break;

            case 0x12: MHLO(instruct,reg);break;

            case 0x18: MULT(instruct,reg);break;

            case 0x1A: DIV(instruct,reg);break;

            case 0x20: ADD(instruct,reg);break;

            case 0x22: SUB(instruct,reg);break;

            case 0x24: AND(instruct,reg);break;

            case 0x25: OR(instruct,reg);break;

            case 0x26: XOR(instruct,reg);break;

            case 0x2A: SLT(instruct,reg);break;
          }

        case 0x02: jump(instruct,reg);break;

        case 0x04: BEQ(instruct,reg);break;

        case 0x05: BNE(instruct,reg);break;

        case 0x06: BLEZ(instruct,reg);break;

        case 0x07: BGTZ(instruct,reg);break;

        case 0x08: ADDI(instruct,reg);break;

        case 0x0F: LUI(instruct,reg);break;

        case 0x23: LW(instruct,reg);break;

        case 0x2B: SW(instruct,reg);break;
      }
}
