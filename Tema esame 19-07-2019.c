#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30
void stampa (char s[]){
  int l;

  l=strlen(s);
  l=l+7;
  for(int i=0; i<l;i++){
    printf("#");
  }
  printf("\n#\t%s\t#\n",s);
  for(int i=0; i<l;i++){
    printf("#");
  }
  printf("\n");
}

int contacifre (char s[]){
  int c=0;
  for(int i=0; i<strlen(s); i++){
    if(s[i]>='0' && s[i]<='9')
      c++;
  }
  return c;
}

void copiacifre (char s1[], char s2[]){
  int c=0;
  for(int i=0; i<strlen(s1); i++){
    if(s1[i]>='0' && s1[i]<='9'){
      s2[c]=s1[i];
      c++;
    }
  }
}

void shift (char s[]){
  int l;
  l=strlen(s);
  l--;
  for(int i=0; i<l; i++){
    s[i]=s[i+1];
  }
  s[l]='_';
}

int main (int argc, char* argv[]){
  FILE *fp;
  int c;
  char s[DIM],sc[DIM];
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("ERRORE NOME FILE");
  }else{
    if(fscanf(fp,"%s",s)==EOF){
      printf("ERRORE File vuoto");
    }else{
      stampa(s);
      c=contacifre(s);
      printf("Le cifre nella stringa sono: %d \n",c);
      copiacifre(s,sc);
      stampa(sc);
      shift(s);
      stampa(s);
    }
  }
}
