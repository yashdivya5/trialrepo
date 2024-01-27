#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE* insertfront(NODE *, int);
NODE* insertend(NODE *, int);
NODE* i_afterkey(NODE *, int, int);
NODE* i_beforekey(NODE *, int, int);
NODE* i_pos(NODE *, int, int);

void display(NODE *);

int main()
{
    NODE *start = NULL;
    int num, choice, k;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1. Insert at front\n");
        printf("2. Insert at last\n");
        printf("3. Insert after data\n");
        printf("4. Insert before data\n");
        printf("5. Insert at a position\n");
        printf("6. Display\n");
        printf("7. Stop\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter data to insert\n");
            scanf("%d", &num);
            start = insertfront(start, num);
            break;
        case 2:
            printf(" Enter data to insert\n");
            scanf("%d", &num);
            start = insertend(start, num);
            break;
        case 3:
            printf(" Enter data to insert\n");
            scanf("%d", &num);
            scanf("%d", &k);
            start = i_afterkey(start, num, k);
            break;
        case 4:
            printf(" Enter data to insert\n");
            scanf("%d", &num);
            scanf("%d", &k);
            start = i_beforekey(start, num, k);
            break;
        case 5:
            printf(" Enter data to insert\n");
            scanf("%d", &num);
            scanf("%d", &k);
            start = i_pos(start, num, k);
            break;
        case 6:
            display(start);
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
NODE* insertfront(NODE *start, int n){
  NODE *new_node;
  new_node= (NODE*) malloc(sizeof(struct node));
  new_node->next=start;
  new_node->data=n;
  start=new_node;
  return start;
}
NODE* insertend(NODE *start, int n)
{
  NODE *new_node, *ptr;
  new_node = (NODE *) malloc(sizeof(struct node)); 
  new_node->next=NULL;
  new_node->data=n;
  if(start==NULL){
    start= new_node;
  }
  else {
    ptr=start;
    while(ptr->next!=NULL){
      ptr= ptr->next;
    }
    ptr->next=new_node;
  }
  return start;
}
NODE* i_afterkey(NODE *start, int n, int k){
  NODE *new_node, *ptr;   
  new_node = (NODE *) malloc(sizeof(struct node));
  new_node->data=n;
  if(start==NULL){
    printf("EMpty List.");
  }
  else{
    ptr=start;
    while((ptr->data!=k) && (ptr->next!=NULL)){
      ptr= ptr->next;
    }
    if(ptr==NULL){
      printf("Invalid key");
    }
    else{
      new_node->next=ptr->next;
      ptr->next=new_node;
    }
  }
  return start;
}
NODE* i_beforekey(NODE *start, int n, int k){
  NODE *new_node, *ptr, *temp;   
  new_node = (NODE *) malloc(sizeof(struct node));
  new_node->data=n;
 if(start==NULL){
    printf("EMpty List.");
  }
  else if(start->data==k){
    new_node->next=start;
    start=new_node;
  }
  else{
    start=ptr;
    while((ptr->data!=k) && (ptr->next!=NULL)){
      temp=ptr;
      ptr= ptr->next;
    }
    if(ptr==NULL){
      printf("Invalid key");
    }
    else{
      new_node->next=ptr;
      temp->next=new_node;
    }
  }
  return start;
}
NODE* i_pos(NODE *start, int n, int position)
{
  NODE *new_node, *temp, *ptr;
  int count;
  new_node = (NODE *) malloc(sizeof(struct node));
  new_node->data=n;
  if((start==NULL) && (position==1)){
    new_node->next=NULL;
    start=new_node;
  } 
  else if((start==NULL) && (position>1)){
    printf("Invalid\n");
  }
  else{
    ptr=start;
    count=1;
    while ((ptr!=NULL) && (count!=position))
    {
      temp=ptr;
      ptr = ptr->next;
      count++;
    }
    if(ptr==NULL){
      printf("Invalid position\n");
    }
    else{
      new_node->next=ptr;
      temp->next=new_node;
    }
    
  }
  return start;
}
void display(NODE *start)
{
          NODE *ptr;
          if (start == NULL)
          {         
               printf("List is empty\n"); 
           }
           ptr = start;
           printf("The list data are \n");
           while(ptr != NULL)
          {
            	printf("%d\n", ptr->data);
            	ptr = ptr->next;
          }
}
