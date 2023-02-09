#include <stdio.h>
#include <string.h>
#define DIM 30

int carica(char m[][DIM], char nomefile[]) {
  FILE *fp;
  int esito, j, contav, l;
  char v[DIM];
  fp = fopen(nomefile, "r");
  if (fp == NULL)
    esito = -1;
  else {
    j = 0;

    while (fscanf(fp, "%s", v) != EOF && j < DIM) {
      l = (int)strlen(v);
      contav = 0;
      for (int i = 0; i < l; i++)
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' ||
            v[i] == 'u')
          contav++;
      if (contav >= 3) {
        strcpy(m[j], v);
        j++;
      }
    }
    fclose(fp);
    esito = j;
  }
  return esito;
}

void visualizza(char v[][DIM], int q) {
  int i, len;
  printf("\nINDICI:\t\t");
  for (i = 0; i < q; i++)
    printf("%d\t\t", i);
  printf("\nSTRINGHE:\t");
  for (i = 0; i < q; i++) {
    printf("%s\t", v[i]);
  }
  printf("\n\n");
}

void conta(char m[][DIM], int dim, char c, int *d1, int *d2) {
  *d1 = -1;
  *d2 = -1;
  int l;
  for (int i = 0; i < dim; i++) {
    l = strlen(m[i]) - 1;
    if (m[i][l] == c) {
      if (*d1 == -1)
        *d1 = i;
      else
        *d2 = i;
    }
  }
}
int cancella(char m[][DIM], int dim) {

  for (int i = 0; i < dim - 1; i++)
    strcpy(m[i], m[i + 1]);
  m[dim][0] = '\0';

  return dim - 1;
}

int main(int argc, char *argv[]) {
  char m[DIM][DIM], c;
  int ris, prima, ultima, dim2;
  if (argc != 2)
    printf("ERRORE SCRITTURA FILE");
  else {
    ris = carica(m, argv[1]);
    if (ris == -1) {
      printf("ERRORE il file non esiste");
      return ris;
    }
    visualizza(m, ris);
    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    conta(m, ris, c, &prima, &ultima);
    printf("\n La prima parola del vettore che finisce con %c e' in posizione "
           "%d, l'ultima in posizione %d",
           c, prima, ultima);

    dim2 = cancella(m, ris);
    visualizza(m, dim2);
    return 1;
  }
}
