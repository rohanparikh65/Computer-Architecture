#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void correctorincorrect(int **matrix){

	for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]!=0){
                for(int k=j+1;k<9;k++){
                    if(matrix[i][k]==matrix[i][j]){
                        printf("incorrect\n");
                        return;
                    }
                }
                for(int k=i+1;k<9;k++){
                    if(matrix[k][j]==matrix[i][j]){
                        //printf("%d", matrix[k][j]);
                        printf("incorrect\n");
                        return;
                    }
                }

                int m = (int)(i/3)*3;
                int n = (int)(j/3)*3;
                int k,l;
                for(k=m;k<3+m;++k){
                    for(l=n; l<3+n; ++l){
                        if((i!=k || j!=l) && (matrix[i][j] == matrix[k][l])){
                            printf("incorrect");
                            return;
                        }
                    }
                } 
                
                }
            }
    }
    printf("correct");
}

void solvable(int **matrix){
	for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]!=0){
                for(int k=j+1;k<9;k++){
                    if(matrix[i][k]==matrix[i][j]){
                        printf("unsolvable\n");
                        return;
                    }
                }
                for(int k=i+1;k<9;k++){
                    if(matrix[k][j]==matrix[i][j]){
                        //printf("%d", matrix[k][j]);
                        printf("unsolvable\n");
                        return;
                    }
                }

                int m = (int)(i/3)*3;
                int n = (int)(j/3)*3;
                int k,l;
                for(k=m;k<3+m;++k){
                    for(l=n; l<3+n; ++l){
                        if((i!=k || j!=l) && (matrix[i][j] == matrix[k][l])){
                            printf("unsolvable");
                            return;
                        }
                    }
                } 
                
                }
            }
    }
    printf("solvable");
}

void freematrix(int **matrix){
    int i;
    for(i=0;i<10;i++){
        free(matrix[i]);

    }
    free(matrix);

}



int main (int argc, char** argv) {

	FILE * fp = fopen(argv[1], "r");;
    int **matrix = NULL;
	matrix = (int **)malloc(sizeof(int*) * 10);

	int i;
	for (i=0; i<10; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * 10);
	} 

	char in=0;
	int row=0, column=0, blankspace = 0;
	int eloc=0, eloc2=0;

	while (fscanf(fp, "%c", &in)==1) {

		if (in == '\n') continue;

		if (isdigit(in)) {
			int x = in - '0';
			if (x==0) {
				return 0;
			}
			matrix[row][column] = x;
		}else {
			if (in == ' '){
				matrix[row][column] = 0;
			 blankspace++;
				if  (blankspace==1) {
					eloc = row*10 + column;
				}else if  (blankspace==2) {
					eloc2 = row*10 + column;
				} else {
					return 0;
				}

			} else {
				return 0;
			}
		}

		
		column++;

		
		if (column==9) {
			column=0;
			row++;
		}
	}

	if (blankspace==0){
		correctorincorrect(matrix);
	}


	if (blankspace==1){
		int r = eloc/10;
	    int c = eloc%10;

	    int count[10] = {0};
	    int i;

	   for (i=0; i<9; i++) {
		    count[matrix[r][i]] ++;
		    if (count[matrix[r][i]] >1) {
			  printf("unsolvable");
              freematrix(matrix);
			  return 0;
		}
	}

	for (i=1; i<10; i++) {
		if (count[i]==0) {
			matrix[r][c] = i;
			break;
		}
	}

	solvable(matrix);
    freematrix(matrix);
	return 0;

	}

	if (blankspace==2){
	int r1 = eloc/10;
	int c1 = eloc%10;

	int r2 = eloc2/10;
	int c2 = eloc2 %10;

	int count1[10] = {0};
	int count2[10] = {0};
	int i;

	if (r1 == r2) {

		for (i=0; i<9; i++) {
			count1[matrix[i][c1]] ++;
			count2[matrix[i][c2]] ++;

			if (count2[matrix[i][c1]] >1) {
				printf("unsolvable");
                freematrix(matrix);
				return 0;
			}
			if (count2[matrix[i][c2]]>1) {
				printf("unsolvable");
                freematrix(matrix);
				return 0;
			}

		}

		for (i=1; i<10; i++) {
			if (count1[i]==0) {
				matrix[r1][c1] = i;
			}
			if (count2[i]==0) {
				matrix[r2][c2] = i;
			}
		}

	} else { 
		
		for (i=0; i<9; i++) {
			count1[matrix[r1][i]] ++;
			count2[matrix[r2][i]] ++;

			if (count1[matrix[r1][i]] >1 || count2[matrix[r2][i]]>1) {
				printf("solvable");
                freematrix(matrix);
				return 0;
			}

		}

		for (i=1; i<10; i++) {
			if (count1[i]==0) {
				matrix[r1][c1] = i;
			}
			if (count2[i]==0) {
				matrix[r2][c2] = i;
			}
		}

	}
	solvable(matrix);
    freematrix(matrix);
	return 0;

	}



    freematrix(matrix);
    /*for(i=0;i<10;i++){
        free(matrix[i]);

    }
    free(matrix);*/
}