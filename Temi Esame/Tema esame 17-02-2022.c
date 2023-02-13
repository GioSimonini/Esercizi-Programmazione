// Giovanni Simonini 20051834

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
int carica(char v[]){
  int l=0,c;
 do
 { 
  printf("Inserisci una stringa: ");
  scanf("%s",v);
  c=0;
  l=strlen(v);
  if(l % 2 !=0)
  {
    printf("\nInserire un numero pari di caratteri\n");
    c++;
  }
}while(c!=0);
  return l;
}

void conta (char v[],int dim,int* p1,int* p2){
  *p1=0;
  *p2=0;
  for(int i=0; i<dim; i++){
    if(v[i]== 'a' || v[i]=='e'|| v[i]=='i' || v[i]=='o' || v[i]=='u')
      *p1=*p1+1;
    if(v[i]>='0' && v[i]<='9')
      *p2=*p2+1;
  }
}

int aggiungi(char s[], int h, char c, int d){
  if(d<=h){
    h++;
    for(int i=h;i>d;i--)
      s[i]=s[i-1];
    s[d]=c;
  }else{
    printf("ERRORE indice");
    return h;
  }
  return h;
}
void scrive (char v[],int dim, char nomefile[]){
  FILE *fp;
  fp=fopen(nomefile,"w");
  dim=dim/2;
  for(int i=0; i<dim; i++){
    fprintf(fp,"%c",v[i]);
  }
  fclose(fp);
}
int main(int argc, char* argv[]){
  char v[DIM];
  int l,cv,cc,d;
  char c;
  if(argc != 2){
    printf("ERRORE inserimento argomenti\n");
  }else{
    l=carica(v);
    printf("\n%s\n",v);
    printf("Lunghezza: %d\n",l);
    conta(v,l,&cv,&cc); 
    printf("Le vocali minuscole presenti nel vettore: %d\n",cv);
    printf("I caratteri presenti nel vettore: %d\n",cc);

    printf("Inserire un carattere:\t");
    scanf("\n%c",&c);
    printf("Inserire un indice:\t");
    scanf("%d",&d);
    
    l=aggiungi(v,l,c,d);
    printf("\n%s\n",v);
    printf("Lunghezza: %d",l);
    scrive(v,l,argv[1]);
  }

  
}
