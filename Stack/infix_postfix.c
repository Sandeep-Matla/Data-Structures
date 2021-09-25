// Completed...

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct {
	int top;
	char* a;
}Stack;

Stack stack(int);
Stack push(Stack , char );
Stack pop(Stack );
char top (Stack );

int Prior(char c){
	int prior;
	if(c == '*' || c == '/' || c == '%')
		prior = -1;
	else if(c == '+' || c == '-')
		prior = -2;
	else if ( c == '(' || c == ')')
		prior = -3;
	else 
		prior = 1;
	return prior;
}

char* empty(Stack* stk){
	int n= stk->top;
	char removed[n+1];
	while(stk->top != -1){
		removed[(n- stk->top)] = top(*stk);
		stk->top --;
	}
	printf("%s",removed );
	return removed;

}

char* Infix_To_Post(char * inf){

	int n = strlen(inf);
	
	Stack stk = stack(n);
	
	char c;
	int brac_flag = 0;
	for(int i=0; i<n; i++){
		c = inf[i];
		// printf("%c ", c);
		// printf("%d\n", Prior(c));
		//printf("%d\n",stk.top );

		if(Prior(c) == 1) // if operand
			printf("%c",c);
		else{                   // if operator
			if(stk.top == -1)
				stk = push(stk,c);
			else if(c != ')'){
				if(c == '('){
					stk = push(stk,c);
					brac_flag = 1;
				}
				else if(Prior(c) > Prior(top(stk)))
					stk = push(stk,c);
				else if(!brac_flag){
					empty(&stk);
					stk = push(stk,c);
				}
				else{
					while(top(stk) != '('){
						printf("%c", top(stk));
						stk = pop(stk);
					}
					stk = push(stk,c);
				}
			}
			else{
				while(top(stk) != '('){
					printf("%c", top(stk));
					stk = pop(stk);
				}
				stk = pop(stk); // removing '('
				brac_flag = 0;
			}
				
		}
	}
	// empty ths stack 
	empty(&stk);

}
void main(){
	char infix[100] ;
	printf("Enter infix expression : \n");
	scanf ("%s",infix);
	char* postf = Infix_To_Post(infix);
	//printf("%s",postf);

}

// Stack Implementation.......

Stack  stack(int len){
	Stack stk;
	stk.a =(char*) malloc(sizeof(char)*len);
	stk.top = -1;

	return stk;
}

Stack push(Stack stk, char ele){
	stk.top ++;
	//stk.a = (int*) realloc(stk.a,sizeof(int) * stk.top+1);

	stk.a[stk.top] = ele;
	return stk;
}
Stack pop(Stack stk){
	if(stk.top == -1){
		printf("Stack is Empty ..\n");
	}
	else{
		stk.top --;
	}
}
char top (Stack stk){

	return stk.a[stk.top];
}
