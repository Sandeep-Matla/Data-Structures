#include<stdio.h>
struct stack{
  int max;
  int top;
  int arr[20];
};
struct stack push(struct stack stk) {
  int ele;
  if(stk.top == stk.max-1)
    printf("Stack is full");
  else{
    stk.top++;
    printf("Enter element");
    scanf("%d", &ele);
    stk.arr[stk.top]= ele;
    return stk;
  }
}
struct stack pop(struct stack stk){
  if(stk.top == -1)
    printf("Stack is empty");
  else
    printf("%d",stk.arr[stk.top--]);
  return stk;
}
int main(){
  int size,opt;
  struct stack stk;
  stk.top = -1;
  printf("Enter sizeof the stack");
  scanf("%d",&size);
  stk.max = size;
  do{
    printf("1.push , 2.pop, 3.exit\n");
    printf("Enter the option : ");
    scanf("%d",&opt);
    switch(opt){
      case 1: stk=push(stk);
              break;
      case 2: stk =pop(stk); break;
      case 3: printf("Exiting...");
              break;
      default: printf("Invalid option");
     }
  }while(opt!= 3);
  
  return 0;
}