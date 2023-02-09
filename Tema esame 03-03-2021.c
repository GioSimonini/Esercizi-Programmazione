#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 30
#define C 20

int carica(char s[][C], FILE *fp) {
  char val[C];
  int j = 0;
  while (fscanf(fp, "%s", val) != EOF) {
    int l;
    l = strlen(val);
    if (l >= 4 && val[0] == 'a' || val[0] == 'e' || val[0] == 'i' ||
        val[0] == 'o' || val[0] == 'u' || val[0] == 'A' || val[0] == 'E' ||
        val[0] == 'I' || val[0] == 'O' || val[0] == 'U') {
      strcpy(s[j], val);
      j++;
    }
  }

  return j;
}

void visualizza(char s[][C], int d) {
  for (int i = 0; i < d; i++) {
    printf("%d) %s\t-\t", i, s[i]);
  }
  printf("\n");
}

int cerca(char v[][C], int d, char s[]) {
  int c = -1;
  for (int i = 0; i < d; i++) {
    if (strcmp(s, v[i]) == 0)
      c = i;
  }
  return c;
}

void aggiungi(char v[][C], int q, char s[]) {
  for (int i = q + 1; i > 3; i--) {
    strcpy(v[i + 1], v[i]);
  }
  strcpy(v[4], s);
  q++;
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("ERRORE file");
    } else {
      char v[R][C];
      int d,r;
      char parola[C];
      d=carica(v, fp);
      fclose(fp);
      visualizza(v,d);
      printf("Inserisci la parola da cercare:\t");
      scanf("%s",parola);
      r=cerca(v,d,parola);
      if(r==-1)
        printf("\n %s non trovata\n",parola);
      else
      printf("\n %s si trova in posizione %d\n",parola,r);

      printf("Inserisci la parola da aggiungere:\t");
      scanf("%s",parola);
      printf("\n");
      aggiungi(v,d,parola);
      d++;
      visualizza(v,d);
    }

  } else {
    printf("ERRORE argomenti");
  }
}
