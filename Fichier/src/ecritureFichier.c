#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecritureFichier.h"
//#include "fonctions.h"


void ecrireFichier(char* instruct){
  //ouverture du fichier
  FILE * fichier;


  fichier = fopen("assembleur_hexa.txt", "a+");

  if(fichier != NULL){ //Vérification que le fichier est bien ouvert
    printf("%d\n", strlen(instruct));
    for(int i = 0; i<strlen(instruct); i++){
      fprintf(fichier, "%c", instruct[i]);
    }
    fprintf(fichier, "\n");


    fclose(fichier); //ferme le fichier
  }
  else{
    printf("Erreur lors de l'ouverture du fichier\n");
  }
}
