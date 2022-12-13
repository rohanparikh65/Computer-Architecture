#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    FILE *file;
    file = fopen(argv[1], "r");
    /*if(file == NULL){
       printf("No file");
       return 0;
    }*/

    int **x, **y, **z;
    int n;
    int i, j, k;

    fscanf(file, "%d", &n); 

    x = (int **)malloc(n * sizeof(int *));
    y = (int **)malloc(n * sizeof(int *));
    z = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++){
        x[i] = (int *)malloc(n * sizeof(int));
        y[i] = (int *)malloc(n * sizeof(int));
        z[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            fscanf(file, "%d", &x[i][j]);
            y[i][j] = x[i][j];
            //printf("%d", y[i][j]);
        }

    }

    int m,p;

    fscanf(file, "%d", &p);
    
    for (m = 0; m < p-1; m++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                z[i][j] = 0;
                for (k = 0; k < n; k++){
                    z[i][j] += x[i][k] * y[k][j];
                    //printf("%d", z[i][j]);
                }
            }
        }

        for(i=0;i<n; i++){
            for(j=0;j<n; j++){
                y[i][j] = z[i][j];
                //printf("%d", y[i][j]);
            }
        }
    }

    for(i=0;i<n; i++){
        for(j=0;j<n; j++){
            printf("%d", z[i][j]);
            if (i < n && j<n-1){
                printf(" ");
            }
        }
        printf("\n");

    }

    for(i=0;i<n;i++){
        free(x[i]);
        free(y[i]);
        free(z[i]);
    }

    free(x);
    free(y);
    free(z);

    fclose(file);

    return 0;
}



