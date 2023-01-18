#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int r=0, c=0,x=0;
  int m[4][4];
  
  if (argc != 2) {
    printf("Errore nome file ");
    exit(2);
  }

  fp = fopen(argv[1], "r");
  
  if (fp == NULL) {
    perror("apertura file fallita\n");
    exit(EXIT_FAILURE);
  }
    r=0;
    c=0;
    while (fscanf(fp, "%d", &x) != EOF && r<4 ) {

      m[r][c]=x;
      printf("%d, %d, %d \n",r,c,x);
      if (c == 3){
        r++;
        c=0;
      }
      else 
          c++;
    }
    
for(r=0; r<4; r++){
    for(c=0; c<4; c++){
        printf("%d\t",m[r][c]);
        }
    printf("\n");
    }
}
