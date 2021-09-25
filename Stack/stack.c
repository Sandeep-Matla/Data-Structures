#include<stdio.h>
#include<stdlib.h>
int push(int* stk ,int top,int size){
  int a;
  
  if(size > top+1){
    printf("Enter elemnt : ");
    scanf("%d",&a);
    top++;
    stk[top] = a;
  }
  else{
    printf("stack is full\n");
  }
  return top;
}
int pop(int* stk ,int top){
  if(top ==-1)
    printf("stck is empty\n");
  else{
    printf("%d",stk[top--]);
  }
  return top;
}
int main(){
  int top = -1,opt;
  int* stack;
  int size;
  printf("Enter size : ");
  scanf("%d",&size);
  stack =(int*) malloc(size* sizeof(int));
  do{
    
    printf("1.push 2.pop 3.exit\nEntre operation:");
    scanf("%d",&opt);
    switch(opt){
      case 1: top = push(stack,top,size); break;
      case 2: top = pop(stack, top); break;
      default: printf("Invalid Option");
      };
    }
    while(opt!=3);
      
  return 0;
}