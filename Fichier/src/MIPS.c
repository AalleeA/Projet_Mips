 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"
 #include "charToHexa.h"
 #include "Registre.h"
 #include "memoire.h"
 #include "fonctions.h"

int Mode = 0;


int main(int argc, char *argv[]){

    printf("***************\nEmulateur MIPS\ndebut de l'initialisation\n");

    Registre reg;
    InitReg(&reg);
    printf("registre initialiser\n");
    int *memoire = NULL;
    memoire = InitMem();
    printf("memoire initialiser\n");


    if(argv[1] == "-it"){
      char* instruct;
      while(instruct != "exit"){
        printf("\n\nEntrée une instruction\n");
        scanf("%[^\n]",&instruct);
        AfficherMemoireProg(memoire);
        Execute((*(reg.pc)),memoire,&reg);
        AfficherMemoireDonnee(memoire);
        AfficherRegistre(&reg);
        *(memoire) = 0;
      }
    }
    else{
      printf("compilation : ");
      charToHexa(Decode(argv[1]));
      printf("fichier compiler");
      Loadprog(memoire, "assembleur_hexa.txt");
      printf("memoire de programe charger\n Affichage : ");
      AfficherMemoireProg(memoire);

      while(*(memoire+(*(reg.pc))) != 0 && (*(reg.pc))<100){
        Execute((*(reg.pc)),memoire,&reg);
        AfficherMemoireDonnee(memoire);
        AfficherRegistre(&reg);
        (*(reg.pc))+=4;
      }
    }

}
