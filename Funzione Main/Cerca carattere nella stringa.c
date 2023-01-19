#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main (int argc, char *argv[]){
    if(argc !=3)
    printf("Numero argomenti non corretto\n");
    else if(argv[2][1] != '\0')
    printf("il secondo argomento non è un carattere\n");
    else if(strchr(argv[1], argv[2][0]))
    printf("Carattere trovato\n");
    else printf("Carattere non trovato\n");
    
    
    return;
    
}
