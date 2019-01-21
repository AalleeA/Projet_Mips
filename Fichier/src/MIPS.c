#include <stdio.h>
#include <stdlib.h>
#include "Read.h"
#include "charToHexa.h"
#include "Registre.h"
#include "memoire.h"



int main(int argc, char *argv[]){

 if(argc > 0){
   //compilation


   //exectution
   int i = 0;
   Registre reg;
   InitReg(&reg);
   int *memoire = NULL;
   memoire = InitMem();
   Loadprog(memoire, "Test/Test2.txt");
   while(*(memoire+i) != 0 && i<100){
     Execute(i,memoire,reg);
     i+=8;
   }


 }
 else{printf("j'ai pas reussi a ouvrir les fichier");}
}
