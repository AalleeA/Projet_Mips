#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SSL(int instruct,Registre*);

void NOP(int instruct,Registre*);

void ROTR(int instruct,Registre*);

void SRL(int instruct,Registre*);

void SYSCALL(int instruct,Registre*);

void MHFI(int instruct,Registre*);

void MHLO(int instruct,Registre*);

void MULT(int instruct,Registre*);

void DIV(int instruct,Registre*);

void ADD(int instruct,Registre*);

void SUB(int instruct,Registre*);

void AND(int instruct,Registre*);

void OR(int instruct,Registre*);

void XOR(int instruct,Registre*);

void jump(int instruct,Registre*);

void BEQ(int instruct,Registre*);

void BNE(int instruct,Registre*);

void BLEZ(int instruct,Registre*);

void BGTZ(int instruct,Registre*);

void ADDI(int instruct,Registre*);

void LUI(int instruct,Registre*);

void LW(int instruct,Registre*);

void SW(int instruct,Registre*);

void lireCodeHexa();
