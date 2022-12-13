#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
    int pos =0;
    while(argv[1][pos] != '\0'){
        if(((int)argv[1][pos] >= 65 && (int)argv[1][pos] <= 90) || ((int)argv[1][pos] >= 97 && (int)argv[1][pos] <= 123)){
             if (((int)argv[1][pos] >= 78 && (int)argv[1][pos] <= 90) || ((int)argv[1][pos] >= 110 && (int)argv[1][pos] <= 123)){
                    argv[1][pos] -= 13;
                    printf("%c", argv[1][pos]);
                }
            else{
                argv[1][pos] += 13;
                printf("%c", argv[1][pos]);
            }
        }
        else{
            printf("%c", argv[1][pos]);

        }
       
        pos++;
    }
}
