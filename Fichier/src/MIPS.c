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
    Registre reg;
    InitReg(&reg);
    int *memoire = NULL;
    memoire = InitMem();
    Loadprog(memoire, "Test/Test2.txt");
    AfficherMemoireProg(memoire);
    while(*(memoire+(*(reg.pc))) != 0 && (*(reg.pc))<100){
      Execute((*(reg.pc)),memoire);
      AfficherMemoireDonnee(memoire);
      AfficherRegistre(&reg);
      (*(reg.pc))+=8;
    }


  }
  else{printf("j'ai pas reussi a ouvrir les fichier");}
}
