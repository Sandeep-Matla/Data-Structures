#include<stdio.h>
#include<string.h>
int main(){
  char expr[200];
  int top=-1;
  printf("Enter expression: \n");
  scanf("%s",expr);
  //printf("%d",strlen(expr));
  char* stack = malloc(10*sizeof(char));
  postfix(expr,stack);
}
void postfix(char infix[],char *stack){
  int indx=0,top=-1;
  char chr;
  while(infix[indx] != '\0'){
    chr = infix[indx];
    indx++;
    if(chr == '('){
      stack[++top]=chr;
    }
    else if(chr == ')'){
      while(stack[top] != '(')
        printf("%c",stack[top--]);
      // removing "("
      top--;
    }
    else if(chr == '^'){
      // higher precidence.
      stack[++top]=chr;
    }
    else if(chr == '*' || chr == '/'){
      if(stack[top] == '/' || stack[top]== '*' || stack[top]== '^' ){
        while(top!=-1 && stack[top]!='(')
          printf("%c",stack[top--]);
        stack[++top]=chr;
      }
      else stack[++top]=chr;
    }
    else if(chr == '+' || chr == '-'){
      if(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top]== '^'){
        while(top!=-1 && stack[top]!='(')
          printf("%c",stack[top--]);
        stack[++top]=chr;
      }
      else stack[++top]=chr;
    }
    else printf("%c",chr);
  }
  while(top!=-1)
    printf("%c",stack[top--]);
}
