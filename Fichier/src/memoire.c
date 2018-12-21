#include <stdio.h>
#include <stdlib.h>


int* InitMem(){
  int* mem = NULL;
  mem = malloc(sizeof(int)*200);
  for(int i = 0; i<200; i++){
    *(mem+i) = 0;
  }
  printf("%d  ", (mem));
  printf("%d  ", *mem);
  return(mem);
}

void AfficherMemoireProg(int* mem){
  int i,j;
  printf("Memoire de Programe : lol%d\n", *mem);
  for(i = 0;i<100;i+=8){
    printf("%d | ", i);
    for(j = 0; j<8; j++){
      printf("%x ", *(mem+j+i));
    }
    printf("\n");
  }
}
