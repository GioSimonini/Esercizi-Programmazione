#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 5
#define R 5
#define C 10



void carica (char m[][C]){

    for (int i=0; i<DIM; i++){
        printf("Inserisci la stringa ad indirizzo %d: ",i);
        scanf("%s",m[i]);
    }
}
//uso una matrice perchè è più comoda dei vettori di putatori
/*Scrivere un programma organizzato nelle seguenti funzioni:
- carica vettore di stringhe da tastiera, una per volta;
- per ogni stringa, converte tutti i caratteri minuscoli in maiuscoli;
- visualizza vettore di stringhe;
- main: dichiara un vettore di stringhe (mutabili) e invoca le altre funzioni. 
*/
void visualizza (char m[][C]){
    
    for(int i=0; i<R; i++){
     if(m[i][0] != '\0')
         printf("%d %s \n",i,m[i]);
    }
}

void cambiacaratteri (char m[][C]){
    int l;
    for(int i=0; i<R; i++){
        if(m[i][0]!='\0')
            l=strlen(m[i]);
            for(int j=0; j<l; j++){
                if(islower(m[i][j]))
                    m[i][j]= toupper(m[i][j]);
            }
        
    }
}

int main(){

char m[R][C];

    carica(m);
    visualizza(m);
    cambiacaratteri(m);
    printf("\n");
    visualizza(m);
    
    return 0;

}
