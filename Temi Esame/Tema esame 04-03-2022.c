#include <stdio.h>
#define DIM 30

int carica(int v[], char nomef[], int x) {
  int val, esito, i;
  FILE *fp;
  fp = fopen(nomef, "r");
  if (fp == NULL)
    esito = 0;
  else {
    i = 0;
    while (fscanf(fp, "%d", &val) != EOF && i < DIM - 1)
      if (val > 0 && val % x == 0) {
        v[i] = val;
        i++;
      }
    v[i] = -1;
    fclose(fp);
    esito = 1;
  }
  return esito;
}

void stampa(int v[]) {

  if (v[0] != -1) {
    for (int i = 0; v[i] != -1; i++)
      printf("%d\t", i);
    printf("\n");
    for (int i = 0; v[i] != -1; i++)
      printf("%d\t", v[i]);
  } else {
    printf("Vettore vuoto");
  }
  printf("\n");
}

void valoripari(int v[], int *d1, int *d2) {
  *d1 = -1;
  *d2 = -1;

  for (int i = 0; v[i] != -1; i++) {
    if (v[i] % 2 == 0) {
      if (*(d1) == -1)
        *d1 = i;
      else
        *d2 = i;
    }
  }
}

void meta(int v1[], int v2[]) {
  int j = 0;
  for (int i = 0; v1[i] != -1; i++) {
    j++;
  }
  j = j / 2;

  for (int i = 0; i < j; i++) {
    v2[i] = v1[i];
  }
  v2[j + 1] = -1;
}

int main(int argc, char *argv[]) {

  int v[DIM];
  int copia[DIM];

  int primo, ultimo, a, caricac;

  if (argc != 2)
    printf("ERRORE FILE");
  else {
    printf("inserire valore intero ");
    scanf("%d", &a);
    caricac = carica(v, argv[1], a);
    if (caricac == 1) {
      stampa(v);

      valoripari(v, &primo, &ultimo);

      if (primo == -1 && ultimo == -1)
        printf("Non esistono valori pari nel vettore \n");
      else if (ultimo ==-1)
        printf("Esiste 1 solo valore pari nel vettore e si trova in posizione: "
               "%d \n",
               primo);
      else
        printf("Primo valore pari: %d, Ultimo valore pari: %d \n", primo,
               ultimo);

      meta(v, copia);
      stampa(copia);
    } else {
      printf("il file non esiste");
    }
  }
}
