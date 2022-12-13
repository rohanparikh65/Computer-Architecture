#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc == 1){
        return EXIT_SUCCESS;
    }

    int i=0;
    int j=0;
    char *temp;
    //char temporary[100];

    for(i=1;i<argc-1;++i)
   {
     for(j=i+1;j<argc;++j)
     {
       if(strcmp(argv[i],argv[j])>0)
       {
         temp = argv[i];
         argv[i] = argv[j];
         argv[j] = temporary;
       }
     }
   }

   for(i=1;i<argc;++i){
     printf("%s\n", argv[i]);
     //puts(argv[i]);
   }
   
   //printf("%s\n", argv[i]);

   return 0;
}
