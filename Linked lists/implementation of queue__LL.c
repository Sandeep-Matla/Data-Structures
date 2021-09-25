#include<stdio.h>
typedef struct{
  int ele;
  struct node * next;
}node;

int main(){
  node* head;
  int opt,ele;
  head=NULL;
  
  do{
    printf("1.push() 2.pop() 3.read()\n");
    printf("Enter option:\n");
    scanf("%d",&opt);
    switch(opt){
      case 1: printf("Enter the element: ");
              scanf("%d",&ele);
              push(&head,ele);
              break;
      case 2: printf("%d\n",pop(&head)); break;
      case 3: readList(head); break;
      case -1: break;
      default: printf("Invalid input\n");
    }
  }while(opt!=-1);

  return 0;
}

void push(node** temp,int ele){
  if((*temp)==NULL){
    (*temp)=(node*)malloc(sizeof(node));
    (*temp)->ele=ele;
    (*temp)->next=NULL;
  }
  else{
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->ele=ele;
    new_node->next=NULL;
    node* current=(*temp);
    while(current->next != NULL){
      current=current->next;
    }
    current->next=new_node;
  }
  
}
int pop(node** head){
  int ele;
  if((*head)==NULL){
    printf("Queue is Empty\n");
    return;
  }
  else{
    ele= (*head)->ele;
    (*head)=(*head)->next;
    return ele;
  }
}
void readList(node* current){
  if(current == NULL){
    printf("[]\n");
  }
  else{
  printf("[");
  while(current->next!=NULL){
    printf("%d ,",current->ele);
    current=current->next;
  }
  printf("%d",current->ele);
  printf("]\n");
  }
}