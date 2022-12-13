#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
} treenode;

int num = 0;

int search(treenode **root, int n){
    
    for (treenode *tmp = *root; tmp != NULL; tmp = (n < tmp->value) ? tmp->left : tmp->right)
    {
        if (tmp->value == n){
            printf("present\n");
            return 0;
        }
    }
    printf("absent\n");
    return 0;
}

int insert(treenode **root, int n){

    if(*root == NULL){
        *root = (treenode*)malloc(sizeof(treenode));
        (*root)->value = n;
        (*root)->left = NULL;
        (*root)->right = NULL;
        num++;
        printf("inserted\n");
        return 0;
    }
    else{
        if(num == 0){
            (*root) -> value = n;
            num++;
            printf("inserted\n");
            return 0;
        }
        else if ((*root) -> value > n) return insert(&(*root) -> left, n);
        else if ((*root) -> value < n) return insert(&(*root) -> right, n);
        
        else {
            printf("not inserted\n");
            return 0;
        }
    }
}

int delete(treenode **root, int n){
    if(*root == NULL){
        printf("absent\n");
        return 0;
    }
    
    else if((*root) -> value == n){
        if((*root) -> right != NULL && (*root) -> left != NULL){
            treenode *p = *root;
            treenode *m = (*root) -> left;

            while(m -> right != NULL){
                p = m;
                m = m -> right;
            }

            (*root) -> value = m -> value;
            if(m == p -> right){
                p -> right = NULL;
            }
            else p -> left = NULL;

            free(m);
            m = NULL;
            

        }
        else if((*root) -> right != NULL || (*root) -> left != NULL){
            if((*root) -> right != NULL){
                treenode *temp = (*root) -> right;
                (*root) -> value = temp -> value;
                (*root) -> left = temp -> left;
                (*root) -> right = temp -> right;

                free(temp);
                temp = NULL;
            } 
            else{
                treenode *temp = (*root) -> left;
                (*root) -> value = temp -> value;
                (*root) -> left = temp -> left;
                (*root) -> right = temp -> right;

                free(temp);
                temp = NULL;
            }
            
        }

        else{
            free(*root);
            *root = NULL;
        }
        num = num - 1;
        printf("deleted\n");
        return 1; 
    }
    else{
        if((*root) -> value > n) return delete(&(*root) -> left, n);
        else return delete(&(*root) -> right, n);
    }
}

void printn(treenode **root){
    if(num==0 || *root == NULL) return;
    printf("(");
    printn(&(*root) -> left);
    printf("%d",(*root) -> value);
    printn(&(*root) -> right);
    printf(")");
}

void freenodes(treenode ** root){
    if (*root == NULL) return;
    freenodes(&(*root)->left);
    freenodes(&(*root)->right);
    free(*root);    
}

int main(int argc, char **argv){
    treenode *root = malloc(sizeof(treenode));
	root->left=NULL;
    root->right=NULL;

    char input = '0'; 
    int s = 1;
    while ( s>=0){
        if (input == '0' || input == 'p'){

            int in = scanf("%c", &input);
            if (in == EOF){break;}
            if (input == 'p'){
                printn(&root);
                //printf("(");
                //print(&(root) -> left);
                //printf("%d",(root) -> value);
                //print(&(root) -> right);
                //printf(")");
                //printn(root);
                printf("\n");
            }
        } else {
            int n;
            scanf("%d", &n);

            if (input == 's'){
                search(&root, n);
            }

            if (input == 'i'){
                insert(&root, n);
            }

            if (input == 'd'){
                delete(&root, n);
            }

           

            input = '0';
        }
    }

    freenodes(&root);

    return 0;
}

