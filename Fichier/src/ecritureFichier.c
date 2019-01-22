#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecritureFichier.h"
//#include "fonctions.h"


void ecrireFichier(int instruct){
  //ouverture du fichier
  FILE * fichier;


  fichier = fopen("assembleur_hexa.txt", "a+");

  if(fichier != NULL){ //Vérification que le fichier est bien ouvert
    //printf("%d\n", strlen(instruct));
    fprintf(fichier,"%x ",(instruct>>24));
    fprintf(fichier,"%x ",(instruct>>16)%0x100);
    fprintf(fichier,"%x ",(instruct>>8)%0x100);
    fprintf(fichier,"%x ",(instruct)%0x100);
    fprintf(fichier, "\n");


    fclose(fichier); //ferme le fichier
  }
  else{
    printf("Erreur lors de l'ouverture du fichier\n");
  }
}


int lireFichier(){
  FILE * fichier;

  int octet;

  fichier = fopen("assembleur_hexa.txt", "r");

  if(fichier != NULL){
    octet = fgetc(fichier);

    while(octet != EOF){

    }
  }
  else{
    printf("Erreur lors de l'ouverture du fichier\n");
  }
}
