 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"
 #include "charToHexa.h"
 #include "Registre.h"
 #include "memoire.h"
 #include "fonctions.h"



 int main(int argc, char *argv[]){

  if(argc > 0){
    //compilation


    //exectution
    printf("***************\nEmulateur MIPS\n\n\n\nFichier compiler\ndebut de l'initialisation");
    Registre reg;
    InitReg(&reg);
    printf("registre initialiser\n");
    int *memoire = NULL;
    memoire = InitMem();
    printf("memoire initialiser\n");
    Loadprog(memoire, "Test/Test2.txt");
    printf("memoire de programe charger\n Affichage : ");
    AfficherMemoireProg(memoire);

    while(*(memoire+(*(reg.pc))) != 0 && (*(reg.pc))<100){
      Execute((*(reg.pc)),memoire,&reg);
      AfficherMemoireDonnee(memoire);
      AfficherRegistre(&reg);
      (*(reg.pc))+=4;
    }


  }
  else{printf("j'ai pas reussi a ouvrir les fichier");}
}
