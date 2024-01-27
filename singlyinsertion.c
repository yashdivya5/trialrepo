#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
void linkedlisttraversal(struct Node* ptr)
{
  while(ptr!=NULL){
    printf("Element :%d\n",ptr->data);
    ptr = ptr->next;
  }
}
struct Node* insertatfront(struct Node* head, int data){
  struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
  ptr->next=head;
  ptr->data=data;
  head=ptr;
  return head; 
}
struct Node* insertatindex(struct Node* head, int data, int index){
  struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
  struct Node* p= head;
  int i=0;
  while(i!=index-1){
    p = p->next;
    i++;
  }
  ptr->data=data;
  ptr->next=p->next;
  p->next=ptr;
  return head;
}
int main(){
  struct Node* head;
  struct Node* second;
  struct Node* third;
  struct Node* fourth;
  head = (struct Node*) malloc(sizeof(struct Node));
  second=(struct Node*) malloc(sizeof(struct Node));
  third=(struct Node*) malloc(sizeof(struct Node));
  fourth=(struct Node*) malloc(sizeof(struct Node));
  head->data=7;
  head->next=second;
  second->data=11;
  second->next=third;
  third->data=13;
  third->next=fourth;
  fourth->data=17;
  fourth->next=NULL;
  linkedlisttraversal(head);
  //head= insertatfront(head,45);
  //linkedlisttraversal(head);
  head=insertatindex(head,90,1);
  linkedlisttraversal(head);
}