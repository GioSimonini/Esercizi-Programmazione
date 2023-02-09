#include <stdio.h>
#include <stdlib.h>
#define DIM 30
void carica (int v[], FILE *fp){
  int x,i;
  i=0;
  while(fscanf(fp,"%d",&x) != EOF){
    if(x>=0 && x%2==1){
      v[i]=x;
      i++;
    }
  }
  v[i]=-1;
}

void visualizza(int v[]){
  printf("Indici\tValori\t\t\n");
    for(int i=0; v[i] != -1; i++){
        printf("%d\t\t%d\t\n",i,v[i]);
      }
}


int cerca (int v[],int x){
  int esito=-1;
  for(int i=0;v[i]!=-1;i++){
      if(x==v[i] && esito==-1)
        esito=i;
  }
  return esito;
}


void inserisci (int v[], int x){
  int contavalori=0;
  
  for(int i=0; v[i]!=-1; i++){
    contavalori++;
  }
  for(int i=contavalori+1; i>0; i--)
      v[i]=v[i-1];
  v[0]=x;
}

int main ( int argc, char* argv[]){
  if(argc==2){
    int v[DIM];
    FILE *fp;
    int x,esito,n;
    fp=fopen(argv[1],"r");
    if(fp!=NULL){
      carica(v, fp);
      fclose(fp);
      visualizza(v);
      
      printf("Inserisci valore da cercare: ");
      scanf("%d",&x);
      esito=cerca(v, x);
      if(esito==-1)
        printf("\n%d non e' presente nel vettore \n",x);
      else
        printf("%d si trova in posizione %d \n",x,esito);
      printf("Inserisci il valore da aggiungere al vettore: ");
      scanf("%d",&n);
      inserisci(v, n);
      visualizza(v);
    }else{
    printf("ERRORE file non trovato");
    return -1;
    } 
  }else{
    printf("ERRORE argomenti");
    return -1;
    }
  return 1;
  
}
