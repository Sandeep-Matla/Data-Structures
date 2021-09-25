//:status: completed
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
  int ele;
  struct node *next;
}node;
void append(node *);
void readList(node *);
bool isEmpty(node *);
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
      case 1: if(isEmpty(head))
                head = insertFirst(head);
              else append(head);
              break;
      case 2: readList(head); break;
      case 3: pop(&head); break;
      case 4: if((res=insert(head))!=NULL)
                head = res; 
              break;
      case 5: if((res=remove_ind(head))!=NULL)
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
              head = res; break;
      case -1: break;
      default: printf("Enter Invalid opt \n");
    }
  }while(opt!=-1);
 // printf("%d\n",head->ele);
  //readList(head);
}
bool isEmpty(node * start){
  return (start == NULL);

}
node* insertFirst(node* start){
  int ele;
  printf("Enter the element : ");
  scanf("%d",&ele);
  node * new_node=(node*) malloc(sizeof(node));
  new_node ->ele = ele;
  new_node ->next = NULL;
  return new_node;
}
// append - update for empty list insertFirst
void append(node* pos){
  int ele;
  printf("Enter the element : ");
  scanf("%d",&ele);
  node * new_node=(node*) malloc(sizeof(node));
  new_node ->ele = ele;
  new_node ->next = NULL;
  while(pos->next !=NULL){
    pos = pos->next;
  }
  pos->next = new_node;
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
    for(int i=0;i<ind-1;i++){
      current= current->next;
    }
    node * before = current;
    current= current->next;
    // setting nwxt of before to tbe new node
    before -> next = new_node;
    // setting next of new node to consecutive node.
    new_node->next=current;
    return NULL;
  }
}
void pop(node ** head){
  /*while((current->next)->next !=NULL){
    current = current->next;
  }
  current->next = NULL;*/
  node* current=*head;
  node* prev_curr=current;
  if(current == NULL)
    printf("List is Empty\n");
  else{
    while((current->next) !=NULL){
      prev_curr = current;
      current = current->next;
    }
    printf("Deleting %d from the list \n",current->ele);
    if(prev_curr==current){
      // head sholud be NULL
      *head=NULL;
    }
    else
      prev_curr->next = NULL;
  }
} 
node* remove_ind(node * current){
  int ind;
  printf("Enter index\n");
  scanf("%d",&ind);
  if(ind>=len(current))
    printf("No ele found at that index\n");
  else if(current == NULL)
    printf("List is Empty...\n");
  else if(ind == 0){
    current = current->next;
    //_setting head to 2nd ele
    return current;
  }
  else{
    for(int i=0;i<ind-1;i++){
      current= current->next;
    }
    node * temp = current;
    current=current->next;
    //skipping the add of.indexed one.
    temp->next = current->next; 
    return NULL;
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
}
node* removeEle(node* current,int srch){
  node* prev_node;
  int flag=0;
  if(current == NULL)
    printf("List is Empty .. So cant remove .\n");
  // If matches at first, head should be updated..
  if( current->ele == srch){
    flag=1;
    current = current->next;
    //returning current as head...
    printf("Successfully removed \n");
    return current;
  }
  else{
    while(current != NULL){
        if(current->ele == srch){
          flag=1;
          break;
        }
        prev_node = current;
        current= current->next;
    }
    if(flag){
      prev_node->next=current->next;
      printf("Successfully removed \n");
    }
    else printf("Ele not found\n");
    return NULL;
  }
}
node* search(node* current, int srch){
  if(current == NULL){
    printf("**List is empty..**\n Hence ele not found\n");
    return NULL;
  }
  else{
    
    int flag=0;
    //;Binary search....
    /* int len= length(node*);
    int mid,start,end;
    start = 0;
    while(current->next==NULL){
      mid = (start+end)/2;
      if(current->ele== srch)
        printf("element found");
      else if(ele <= ) */
      
    //  Linear search
    while(current != NULL){
      if(current->ele == srch){
        flag = 1;
        return current;
      }
      current=current->next;
    }
    if(flag==0){
      return NULL;}
  }
}
int len(node* list){
  int len=0;
  while(list!=NULL){
    list=list->next;
    len++;
  }
  return len;
}