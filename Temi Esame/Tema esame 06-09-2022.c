// Simonini Giovanni
#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 4
int carica(int m[R][C], char nomefile[]) {
  FILE *fp;

  fp = fopen(nomefile, "r");
  int esito;
  if (fp == NULL)
    esito = 0;
  else {
    int z = 0;
    while (fscanf(fp, "%d", &m[z][0]) != EOF && z < R)
      z++;
    for (int i = 0; i < R; i++)
      for (int j = 1; j < C; j++)
        m[i][j] = m[i][j - 1] + 1;
    esito = 1;
  }
  fclose(fp);
  return esito;
}

void visualizza(int m[R][C]) {

  printf("\n\t\t");
  for (int i = 0; i < C; i++) {
    printf("%d\t", i);
  }
  printf("\n");
  printf("\t\t");
  for (int i = 0; i < C; i++) {
    printf("*\t");
  }
  printf("\n");
  for (int i = 0; i < R; i++) {
    printf("%d\t*\t", i);
    for (int j = 0; j < C; j++) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void ricerca(int m[R][C], int x, int *i, int *j) {
  *i = -1;
  *j = -1;

  for (int a = 0; a < R; a++) {
    for (int b = 0; b < C; b++) {
      if (m[a][b] == x && *i == -1 && *j == -1) {
        *i = a;
        *j = b;
      }
    }
  }
}

int prodotto(int m[R][C], int x) {
  int prod = -1;
  if (x > R) {
    return prod;
  } else {
    prod = 1;
    for (int i = 0; i < C; i++) {
      prod = prod * m[x][i];
    }
    return prod;
  }
}

int main(int argc, char *argv[]) {
  int m[R][C];
  int esito = 0, c, x, y, rx, prd;

  if (argc != 2)
    printf("ERRORE argomenti");
  else {
    esito = carica(m, argv[1]);
    if (esito == 1) {
      visualizza(m);
      printf("Inserisci valore da cercare: ");
      scanf("%d", &c);
      ricerca(m, c, &x, &y);

      if (x == -1 && y == -1)
        printf("\n%d non e' presente nella matrice\n", c);
      else
        printf("\n%d si trova in posizione %d, %d \n", c, x, y);

      printf("Inserisci indice riga da sommare: ");
      scanf("%d", &rx);
      prd = prodotto(m, rx);

      if (prd == -1)
        printf("Indice non compatibile\n");
      else
        printf("Il prodotto dei valori in riga %d: %d", rx, prd);

    } else
      printf("ERRORE caricamento file");
  }
  return 1;
}
