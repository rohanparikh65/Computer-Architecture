#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    char name[32];
    int weight;
    int value;
} item;

int Wt = 0; 
int itms = 0; 
int totalitms = 0;

item *a;
int i = 0;
int j = 0;

int numberofitems(FILE *manifest){

    fscanf(manifest, "%d", &totalitms);
    if (totalitms <= 0){
       // printf("No items\n");
        return 1;
    }
    else return 0;

}

void print_matrix(int **matrix, int rows, int cols){

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%d", matrix[i][j]); 
			if(j + 1 < cols)
				printf(" | ");
		}
		printf("\n");
		for(j = 0; j < cols; j++){
			printf("----");
		}
		printf("\n");
	} 
}

int maximum(int i, int j){

    if (i < j){
        return j;
    }
    else{
        return i;
    }
}


void emptyfrfc(int **table, int rows, int cols){

    while(i < rows || j < cols){
        if(i < rows){
            table[i][0] = 0;
            i++;
        }
        else{
            table[0][j] = 0;
            j++;   
        }
    }

}

void fillm(int **matrix, item *items, int rows, int cols){
    
    emptyfrfc(matrix,rows,cols);

    for (i = 1; i < rows; i++){
        for (j = 1; j < cols; j++){
            int k = j - items[i].weight;
            if (k < 0){
                matrix[i][j] = maximum(matrix[i-1][j], 0);
            } else{
                matrix[i][j] = maximum(matrix[i-1][j], matrix[i-1][k] + items[i].value);
            }
        }
    }
}

item *optimalSol(int **matrix, item *items, int rows, int cols){

    a = malloc((rows) * sizeof(item));
    int k = 0;

    do{
        if (matrix[rows][cols] == matrix[rows-1][cols]){
            rows--;
            continue;
        } else{
            a[k] = items[rows];
            k++;
            cols = cols - items[rows].weight; 
            Wt += items[rows].weight;
            itms++;
            rows--;
        }
    }
    while(rows>0 && cols>0);

    return a;

}

void freeall(int **matrix, int rows, item *items, item *a){
   
    int x = 0;
    while(rows>x){
        free(matrix[x]);
        x++;
    }
    free(matrix);
    free(items);
    free(a);
}

void printsol(item *a){
    int i;
    for(i = itms - 1; i >= 0; --i){
        printf("%s", a[i].name);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    int w = atoi(argv[1]);
    if (argc > 3 || w < 0){
        //printf("error - cannot have less than 3 arguments and also cannot have negative limit\n");
        return 0;
    }
    
    FILE *manifest = fopen(argv[2], "r");
    if (manifest == NULL || numberofitems(manifest) == 1){
        //printf("file cannot be empty and the number of items in file cannot be zero\n");
        return 0;
    }

    int size = totalitms + 1;
    int i;

    item *items = malloc((size) * sizeof(item));
    
    for (i = 1; i < size; i++){
        fscanf(manifest, "%31s %d %d", items[i].name, &items[i].weight, &items[i].value); 
        
    }

    /*for(i = 1; i < size; i++){
        if (items[i].weight < 0 || items[i].value < 0){
            printf("Cannot have negative weight or value\n");
            return 0;
        }
    }*/

    int **matrix;
    int rows = size; // numitems + 1
    int cols = w + 1; // col = weight

    matrix = malloc(sizeof(int*) * rows);
    for (i = 0; i < rows; i++) {
	    matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    fillm(matrix, items, rows, cols);
    //print_matrix(table, rows, cols);

    a = optimalSol(matrix, items, rows-1, cols-1); 

    printsol(a);
    printf("%d ", matrix[rows-1][cols-1]);
    printf("/");
    printf(" %d", Wt);
    printf("\n");

    freeall(matrix, rows, items, a);
    return EXIT_SUCCESS;
}