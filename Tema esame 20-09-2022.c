#include <stdio.h>
#include <string.h>

int carica(char v[]) {
  int c = 0;
  do {
    printf("Inserisci stringa ");
    scanf("%s", v);
    for (int i = 0; v[i] != '\0'; i++)
      if (v[i] >= '0' && v[i] <= '9')
        c++;
    if (c < 2)
      printf("La stringa deve contenere almeno 2 caratteri");
  } while (c < 2);
  return c;
}

void visualizza(char v[]) {

  printf("Indici:\t\t");
  for (int i = 0; v[i] != '\0'; i++) {
    printf("%d\t", i);
  }
  printf("\n");
  printf("Caratteri: ");
  for (int i = 0; v[i] != '\0'; i++) {
    printf("%c\t", v[i]);
  }
  printf("\n");
}

void contacifre(char v[], int *p1, int *p2) {
  *p1 = -1;
  *p2 = -1;
  int l = strlen(v);
  for (int i = 0; v[i] != '\0'; i++) {
    if (v[i] >= '0' && v[i] <= '9'){
      if (*p1 == -1)
        *p1 = i;
        else
      if (*p2 == -1)
        *p2 = i;
      }
  }
}

int file(char v[], char nomef[]) {
  FILE *fp;
  fp = fopen(nomef, "w");
  int conta = 0;
  for (int i = 0; v[i] != '\0'; i++) {
    if (!(v[i] >= '0' && v[i] <= '9')) 
    {
      if (conta == 0)
      {
        conta++;
        fprintf(fp, "%c", v[i]);
      } else {
        fprintf(fp, "_%c", v[i]);
        conta +=2;
      }
     
      
    }
  }
  fprintf(fp, "\n");
  fclose(fp);
  return conta;
}
  int main(int argc, char *argv[]) {

    if (argc == 2) {
      char v[30];
      int prima,seconda;
      int contac,contat,contaf;
      contac = carica(v);
      printf("Numero cifre: %d \n",contac);
      visualizza(v);
      contacifre(v,&prima, &seconda);
      printf("Prima cifra(Posizione): %d, Seconda cifra: %d \n",prima,seconda);
      contaf=file(v,argv[1]);
      printf("Quantita caratteri copiati: %d \n",contaf);
    }else{
      printf("ERRORE NOME FILE \n");
      }
    

        return 0;
  }
