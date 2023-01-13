#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main (int argc, char *argv[]){
    int l;
    for(int i=1; i<argc; i++)
        l +=strlen(argv[i]);
    
    char s[l+1];
    if(argc ==1)
        printf("Argomenti mancanti \n");
    else{
        for(int i=1; i<argc; i++)
            strcat(s,argv[i]);//strcat incatena le stringhe togliendo il \0
        printf("%s\n",s);
    }
    
    
    return;
    
}
