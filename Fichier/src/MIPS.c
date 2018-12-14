 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"
 #include "charToHexa.h"
 #include "Registre.h"




 int main(int argc, char *argv[]){
  if(argc > 0){
    InstructionBrut* premier;
    int i = 0;
    do{
      premier = Decode (argv[1]);
      charToHexa(premier);
      i++;
    }while (((*(premier+i)).Instruc != NULL));
    free(premier);

    printf("\n\n\n\n\n\n\n");

    Registre regi;
    Init(&regi);
    EcrireRegistre(&regi, 3, 4);
    AfficherRegistre(&regi);

  }
  else{printf("j'ai pas reussi a ouvrir les fichier");}
}
