#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void carica(int m[DIM][DIM], int a, int b) {
  srand(time(NULL));

  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      m[i][j] = rand() % (b - a + 1) + a;
    }
  }
}
void visualizza(int m[DIM][DIM]) {
  int somma;
  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      somma = somma + m[i][j];
      printf("%d\t", m[i][j]);
    }
    printf("\t somma:%d \n", somma);
    somma = 0;
  }
}

void cerca(int m[DIM][DIM], int x, int* r, int* c) {
  *r = -1;
  *c = -1;
  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      if (m[i][j] == x && *r == -1 && *c == -1) {
        *r = i;
        *c = j;
      }
    }
  }
}

int file(int m[DIM][DIM], int r, char nomefile[]) {
  FILE *fp;
  if (r < DIM) {
    fp = fopen(nomefile, "w");
    if(fp==NULL)
      return -1;
    for (int i = 0; i < DIM; i++) {
      fprintf(fp, "%d", m[r][i]);
    }
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int x;
  int r,c,riga,ris;
  char s[DIM];
  
  if(atoi(argv[1])<atoi(argv[2]) && argc==2){
    int m[DIM][DIM];
    carica(m, atoi(argv[1]), atoi(argv[2]));
    visualizza(m);
    printf("Inserire il valore da cercare: ");
    scanf("%d",&x);
    cerca(m, x, &r, &c);
    if(r==-1 && c==-1)
      printf("Valore (%d) e' assente \n",x);
    else
      printf("%d si trova in posizione %d.%d \n",x,r,c);
    printf("Inserisci indice riga: ");
    scanf("%d",&riga);
    printf("Inserisci nome file: ");
    scanf("%s",s);
    ris=file(m,riga,s);
    if(ris==1)
      printf("Copia avvenuta");
    else if (ris==0)
       printf("Indice non compatibile");
    else
      printf("Errore apertura file");
    }else
      if(argc!=2)
        printf("ERRORE inserimento argomenti");
  else
      printf("ERRORE primo argomento maggiore del secondo");
  
}
