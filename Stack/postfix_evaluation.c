#include<stdio.h>
#include<string.h>
int main(){
  char expr[200];
  int top=-1;
  printf("Enter expression: \n");
  scanf("%s",expr);
  //printf("%d",strlen(expr));
  int* stack = malloc(4*sizeof(int));
  printf("The evaluated value %d",evaluate(expr,stack));
}
int evaluate(char* expr , int* stack){
  int indx =0,top=-1,res=0; char chr;
  while(expr[indx]!='\0'){
    chr = expr[indx];
    if(isdigit(chr)){
      stack[++top]=chr-'0';
    }
    else{
      
      if(chr == '+')
        res= stack[--top]+stack[top+1];
      else if(chr == '-')
        res= stack[--top]-stack[top+1];
      else if(chr == '*')
        res= stack[--top]*stack[top+1];
      else if(chr == '/')
        res= stack[--top]/stack[top+1];
      else if(chr == '^')
        res= stack[--top]^stack[top+1];
      
      stack[top]=res;
    }
    indx++;
  }
  return stack[top];
}