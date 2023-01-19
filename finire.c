#include <stdio.h>
int carica_matrice(int dim, int m[dim][dim], char nome_file[]) {
  FILE *fp;
  int i, j, val, esito;
  fp = fopen(nome_file, "r");
  if (fp == NULL)
    esito = 0;
  else {
    i = 0;
    j = 0;
    while (fscanf(fp, "%d", &val) != EOF && i < dim){
      if (val > 0 && val % 2 == 0) {
        m[i][j] = val;
        j++;
        if (j == dim) {
          j = 0;
          i++;
        }
      }
    }
    fclose(fp);
    if (i == dim)
      esito = 1;
    else
      esito = 0;
  }
  return esito;
}
void visualizza_matrice(int dim, int m[dim][dim]) {
  int i, j;
  printf("\n\t\t");
  for (j = 0; j < dim; j++)
    printf("%d\t", j);
  printf("\n\t\t");
  for (j = 0; j < dim; j++)
    printf("-\t");
  printf("\n");
  for (i = 0; i < dim; i++) {
    printf("%d\t|\t", i);
    for (j = 0; j < dim; j++)
      printf("%d\t", m[i][j]);
    printf("\n");
  }
  printf("\n");
}


void min_e_max(int dim,int m[dim][dim],int r, int* p1,int* p2){
    *p1=-1;
    *p2=-1;
    if(r>=dim){
        for(int i=0; i<dim; i++){
            *(p1)=m[r][0];
                if(m[r][i]<*(p1))
                    *(p1)=m[r][i];
                if(m[r][i]>*(p2))
                    *(p2)=m[r][i];
    }
    
    
    
}

}



int main(int argc, char* argv[]){
    int d, e, riga, min, max;
    if (argc != 2)
        printf("\nERRORE: il programma deve ricevere un solo parametro in "
         "ingresso.\n\n");
        else {
        printf("\nInserire la dimensione della matrice: ");
        scanf("%d", &d);
    int mat[d][d];
        e = carica_matrice(d, mat, argv[1]);
    if (!e)
        printf("\nERRORE: il file non esiste o i valori non bastano.\n\n");
    else {
        visualizza_matrice(d, mat);
        }
    
    printf("Inserire riga:" );
    scanf("%d",&riga);
    min_e_max(d,mat,riga,&min,&max);
    
    printf("min: %d , max: %d ",min,max);
    } 
   return 1; 
}
