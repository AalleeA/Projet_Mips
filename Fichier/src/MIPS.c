 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"
 #include "charToHexa.h"
 #include "Registre.h"




 int main(int argc, char *argv[]){

  if(argc > 0){
    int* memoire;
    memoire = InitMem();
    printf("\n\n%d  ",memoire);
    printf("%d",*memoire);
    //AfficherMemoireProg(memoire);

  }
  else{printf("j'ai pas reussi a ouvrir les fichier");}
}
