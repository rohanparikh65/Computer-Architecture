#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//int global_counter = 0;
//int global_free = 0;

struct node {
  int value;
  struct node *next;
};
int l;

struct node* insertnode(struct node *front, int num) {
  
  if(front==NULL){
    front=malloc(sizeof(struct node));
    front->value=num;
    l++;

    return front;
}


if(num<front->value){
    struct node *inp=malloc(sizeof(struct node));
    inp->value=num;
    inp->next=front;
    front=inp;
    l++;
    return front;

}

struct node *temp=front;


while(temp!=NULL){

if(temp->value==num){
return front;
}

if(temp->next!=NULL){
    if(temp->next->value>num && temp->value<num){
        struct node *temp2=malloc(sizeof(struct node));
        temp2->value=num;
        temp2->next=temp->next;
        temp->next=temp2;
            l++;
            
}
}
}
return front;
}

struct node* delete(struct node *front, int n) {
  if (front -> value == n) {
    return front -> next;
  }
  struct node *t1;
  struct node *p;
  for (t1 = front; t1 -> value != n; t1 = t1 -> next) {
    p = t1;
  }
  p -> next = t1 -> next;
  //nodefree(p);
  free(p->next);

  return front;

}

void nodefree(struct node * start) {

	struct node *ptr = start;

	while (ptr!=NULL) {
    start = ptr;
		ptr = ptr->next;
		free(start);
	  //global_free++;
	}
}

int main (int argc, char **argv){

    struct node *front = NULL;
    
   
    
    char c = '\0';
    int i;
    //int count = 2;

    while(scanf("%c %d",&c,&i) ){
        if(c == 'i' || c == 'd'){
            if(c == 'i'){
                front = insertnode(front, i);
            }
            if(c == 'd'){
                front = delete(front, i);

            }
            
            printf("%d", l);
            printf(" : ");

            struct node *p1 = front;
            while(p1!=NULL){
                int num = p1 -> value;
                printf("%d", num);
                printf(" ");

                p1 = p1 -> next;
            }
            printf("\n");
        }
        }
  nodefree(front);

  return EXIT_SUCCESS;
}
