#include <stdio.h>
#include <string.h>


 int carica (char v[]){
     do{
         int l=0;
    
            printf("Inserisci stringa: ");
            scanf("%s",v);
            l=strlen(v);
            if(l %2 !=0)
                 printf("Errore stringa di lunghezza dispari \n");
    }while(l %2 !=0)
    
    return l;
}


void conta (char s[], int l, int* p1,int* p2){
    
    for(int i=0; i<DIM; i++){
        if (s[i]== 'a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u')
            (*p1)++;
        if(s[i]>=0 && s[i]<=9)
            (*p2)++;
        
    }
    
}

int modificastringa (char s[], int h, char c, int d) {
    char x;
    int i,l;
    if(d<=h)
        h++;
        s[h];
        for(i=h; i>d;i--){
            s[i+1]=s[i];
        }
    s[i-1]=c;
        
    
    return h;
}

void scrivefile(char s[], int l, char f[]){
    FILE *fp;
    fp=fopen(f,"w");
    for(int i=0; i<=(l/2); i++){
    
        fprintf(fp,"%c",s[i]);
    }
    fclose(fp);
}

int main(int argc, char* argv[]){
    
    if (argc != 2){
        printf("Errore nome file ");
        exit(2);
    }
    
    char v[30];
    
    carica(v);
    
    
    
}
