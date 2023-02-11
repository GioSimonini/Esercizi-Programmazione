#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 30

void carica(char v[][C], int r) {
  char s[C];
  int l, c;
  do {
    c = 0;
    l = 0;
    printf("Inserisci prima stringa: ");
    scanf("%s", s);
    l = strlen(s)-1; //perché partiamo da 0 non da 1 nel vettore
    printf("\n%d\n",l);
    if (s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U')
      c++;
    if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
      c++;
    if (c != 2)
      printf("ERRORE, inserire 1 garattere maiuscolo e vocale all' inzio e una "
             "vocale minuscola alla fine \n");
  } while (c != 2);
  strcpy(v[0], s);
  for (int i = 1; i < r; i++) {
    strcpy(v[i], v[i - 1]);
    v[i][l]++;
  }
}

void visualizza(char v[][C], int r) {
  printf("\nIndici\t");
  for (int i = 0; i < r; i++)
    printf("%d\t", i);
  printf("\nStringhe\t");
  for (int i = 0; i < r; i++)
    printf("%s\t", v[i]);
  printf("\n");
}

void conta(char v[][C], int r, int *p1, int *p2) {
  *p1 = 0;
  *p2 = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; v[i][j] != '\0'; j++) {
      if (v[i][j] == 'A' || v[i][j] == 'E' || v[i][j] == 'I' ||
          v[i][j] == 'O' || v[i][j] == 'U')
        *p1 = *p1 + 1;
      if (v[i][j] == 'a' || v[i][j] == 'e' || v[i][j] == 'i' ||
          v[i][j] == 'o' || v[i][j] == 'u')
        *p2 = *p2 + 1;
    }
  }
}

int copiafile(char v[][C], int r, char nomefile[]) {
  FILE *fp;
  int l, c = 0;
  fp = fopen(nomefile, "w");
  l = strlen(v[0])-1;  //perché partiamo da 0 non da 1 nel vettore
  for (int i = 0; i < r; i++) {
    if (v[i][l] == 'a' || v[i][l] == 'e' || v[i][l] == 'i' || v[i][l] == 'o' ||
        v[i][l] == 'u') {
      fprintf(fp, "%s", v[i]);
      c++;
    }
  }
  fclose(fp);
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("ERRORE argomenti");
  } else if (atoi(argv[1]) < 1) {
    printf("ERRORE numero stringhe inserito minore di 1");
  } else {
    int R, contac, vmaiusc, vminusc;
    R = atoi(argv[1]);
    char m[R][C];
    carica(m, R);
    visualizza(m, R);
    conta(m, R, &vmaiusc, &vminusc);
    printf("Il numero di vocali maiuscole: %d, numero vocali minuscole: %d\n",
           vmaiusc, vminusc);
    contac = copiafile(m, R, argv[2]);
    printf("Il numero di elementi copiati: %d\n", contac);
  }
}
