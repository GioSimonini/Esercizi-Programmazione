#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Scrivere un programma organizzato nelle seguenti funzioni utilizzando l'aritmetica dei puntatori:
- carica vettore di stringhe da tastiera, una per volta;
- visualizza vettore di stringhe;
- ricerca una parola nel vettore, individuando gli indici della prima e ultima occorrenza (-1,-1 se assente);
- main: dichiara un vettore di stringhe (mutabili), chiede all'utente una parola, invoca le altre funzioni e visualizza i risultati della ricerca.
*/
#define R 5
#define C 10


void carica (char (*v)[C]){
  for(int i=0; i<R; i++){
    printf("Inserisci stringa: ");
    scanf("%s",*(v+i));
  }
}


void visualizza (char (*v)[C]){
  for(int i=0; i<R; i++){
    if(*(*(v+i)+0) !='\0')
    printf("\t%s",*(v+i));
  }
}

void cerca (char (*v)[C], int* p, int* u, char parola[]){
  *p=-1;
  *u=-1;
  
  for(int i=0;i<R;i++){
    if(*(*(v+i)+0) != '\0'){
    if(strcmp(*(v+i),parola)==0){
      if(*p==-1)
        *p=i;
      else
        *u=i;
      }    
    }
  } 
  
}


int main() {
  char v[R][C];
  char p[C];
  int prima,ultima;
  carica(v);
  visualizza(v);
  printf("\n Inserisci parola da cercare: ");
  scanf("%s",p);
  cerca(v,&prima,&ultima,p);
  if(prima!= -1 && ultima != -1){
    if(prima!= -1 && ultima == -1)
        printf("La parola (%s) si trova 1 volta in posizione %d \n ",p,prima);
    else
       printf("La parola (%s) ha come prima occorrenza la posizione %d e come ultima %d \n ",p,prima,ultima);
    }else
        printf("La parola (%s) assente \n",p);
}
