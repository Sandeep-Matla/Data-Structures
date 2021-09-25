/// Status : Not completed.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
  struct node *prev;
  int ele;
  struct node *next;
}node;
void append(node **,int ele);
void readList(node *);
bool isEmpty(node*);
node* insertFirst(node*);
void pop(node **);
node* remove_ind(node*);
node* insert(node *);
node* removeEle(node*,int);
node* search(node*, int);
int len(node*);
void main(){
  node * head;
  node* res;
  head = NULL;
  int opt,srch;
  int ind, ele;
  printf("1.append 2.read 3.pop 4.insert 5.remove 6.search 7.removeElement, -1.exit\n");
  do{
    printf("Enter opt : ");
    scanf("%d",&opt);
    switch(opt){
      case 1: printf("Enter element:");
              scanf("%d",&ele);
              append(&head,ele);
              break;
      case 2: readList(head); break;
      case 3: pop(&head); break;
      case 4: if((res=insert(head))!=NULL)
                head = res; 
              break;
      /*case 5: if((res=remove_ind(head))!=NULL)
                head = res; 
              break;
      case 6:printf("Enter ele to search :");
             scanf("%d",&srch);
             if((res = search(head,srch))!= NULL)
                printf("Element found\n");
             else printf("Element NOT found\n");
             break;
      case 7:printf("Enter ele to remove : ");
             scanf("%d",&ele);
             if((res=removeEle(head,ele))!=NULL)
              head = res; break;*/
      case -1: break;
      default: printf("Enter Invalid opt \n");
    }
  }while(opt!=-1);
 // printf("%d\n",head->ele);
  //readList(head);
}
bool isEmpty(node* head){
  if(head==NULL)
    return true;
  else
    return false;
}
void append(node ** temp,int ele){
  node* new_node=(node*)malloc(sizeof(node));
  new_node->ele=ele;
  new_node->next=NULL;
  if(isEmpty(*temp)){
    new_node->prev=NULL;
    (*temp)=new_node;
  }
  else{
    node* current=*temp;
    while(current->next!=NULL){
      current=current->next;
    }
    new_node->prev=current;
    current->next=new_node;
    
  }
}
node* insert(node * current){
  int ele, ind;
  printf("Enter value and index\n");
  scanf("%d%d",&ele,&ind);
  node * new_node=(node*) malloc(sizeof(node));
  new_node ->ele = ele;
  if(ind>len(current)){
    printf("Inserting at that index isn't possible\n");
  }
  else if(ind ==0){ 
    new_node->next = current;
    //setting newnode as head;
    return new_node;
  }
  else{
    for(int i=0;i<ind;i++){
      current= current->next;
    }
    node * before = current->prev;
    // setting nwxt of before to tbe new node
    before -> next = new_node;
    new_node->prev= before;
    // setting next of new node to consecutive node.
    new_node->next=current;
    current->prev=new_node;
    return NULL;
  }
}
void pop(node ** head){
  /*while((current->next)->next !=NULL){
    current = current->next;
  }
  current->next = NULL;*/
  node* current=*head;
  node* prev_curr;
  if(current == NULL)
    printf("List is Empty\n");
  else{
    while((current->next) !=NULL){
      current = current->next;
    }
    printf("Deleting %d from the list \n",current->ele);
    if(current->prev==NULL){
      // head sholud be NULL
      *head=NULL;
    }
    else{
      prev_curr=current->prev;
      prev_curr->next = NULL;
    }
  }
} 
void readList(node* start){
  if(start == NULL)
    printf("List is Empty\n");
  else{
    node * current = start;
    printf("\n[");
    while(current->next!=NULL){
      printf("%d , ",current->ele);
      current = current->next;
    }
    printf("%d",current->ele);
    printf("]\n\n");
  }
}int len(node* head){
  int count=0;
  while(head !=NULL){
    head=head->next;
    count++;
  }
  return count;
}