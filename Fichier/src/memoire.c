#include <stdio.h>
#include <stdlib.h>


int* InitMem(){
  int *mem = NULL;
  mem = malloc(sizeof(int)*2048);
  for(int i = 0; i<2048; i++){
    *(mem+i) = 0;
  }
  return(mem);
}

void AfficherMemoireProg(int* mem){
  int i,j;
  printf("Memoire de Programe : \n");
  for(i = 0;i<1028;i+=8){
    if(i>10){printf("%d | ", i);}
    else{printf("%d  | ", i);}
    for(j = 0; j<8; j++){
    if(j+i<1028){printf("%x ", *(mem+j+i));}
    }
    printf("\n");
  }
  printf("\n\n\n");
}


void AfficherMemoireDonnee(int* mem){
  int i,j;
  printf("Memoire de Donnee : \n");
  for(i = 1028;i<2048;i+=8){
    if(i>10){printf("%d | ", i);}
    else{printf("%d  | ", i);}
    for(j = 0; j<8; j++){
      if(j+i<2048){printf("%x ", *(mem+j+i));}
    }
    printf("\n");
  }
}


void EcrireMemDonne(int* mem, int add, int val){
  if(add > 1028){*(mem+add) = val;}
  else{printf("t'as pas le droit\n");}
}

void Loadprog(int* mem, char* Fichier){
  FILE* Base = NULL;
  Base = fopen(Fichier, "r");
  int i = 0;
  while(fscanf(Base,"%x",mem+i) && i<1028){
    i++;
  }
}
