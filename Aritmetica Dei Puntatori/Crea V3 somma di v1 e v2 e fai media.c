#include <stdio.h>
#include <stdlib.h>
#define N 5
void caricavettori(int* v1,int* v2){

  for (int i=0; i<N; i++){
    printf("Inserisci il valore in posizione %d [V1] ",i);
    scanf("%d",&v1[i]);
  }
  printf("\n");
  for (int i=0; i<N; i++){
    printf("Inserisci il valore in posizione %d [V2] ",i);
    scanf("%d",&v2[i]);
  }
  }
void vettoresomma(int* v1,int* v2,int* vs){

  for(int i=0;i<N;i++){
      *(vs+i)=*(v1+i)+*(v2+i);
    }
}

float mediavettore(int* vs){
    int somma=0;
    float media;
   for(int i=0;i<N;i++){
    somma=somma+vs[i]; 
    }

  media=(float)somma/N;

  return media;
}

void stampa (int* v){
  for(int i=0;i<N;i++){
    printf("%d: %d \t",i,*(v+i));
  }
  printf("\n");
}

int main() {
  int v1[N],v2[N],vs[N];
  float media;
  
  caricavettori(v1,v2);
  stampa(v1);
  stampa(v2);
  vettoresomma(v1,v2,vs);
  stampa(vs);
  media=mediavettore(vs);
  printf("media del vettore somma: %f ",media);
}
  
