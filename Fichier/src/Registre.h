#include <stdio.h>
#include <stdlib.h>

typedef struct Registre Registre;
struct Registre {
  int* mem;
  int* zero;
  int* at;
  int* v;
  int* a;
  int* t1;
  int* s;
  int* t2;
  int* k;
  int* gp;
  int* sp;
  int* fp;
  int* ra;
  int* lo;
  int* hi;
  int* pc;
};

void InitReg(Registre*);

int LireRegistre(Registre*,int);
void EcrireRegistre(Registre*, int, int);
