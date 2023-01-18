#include<stdio.h>
#include<stdlib.h>


int main(int argc,char* argv[])
{
FILE *fp;
int x,y;
if(argc !=2 ){
        printf("Errore nome file ");
        exit(2);
        }

        
        
        fp=fopen(argv[1], "r");
        if(fp==NULL)
        {
        perror("apertura file fallita\n");
        exit(EXIT_FAILURE);
        }
        
        fscanf(fp,"%d", &x);
        fscanf(fp,"%d", &y);
        
        printf("x: %d\t y: %d \n",x,y);
        
}
