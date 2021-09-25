
#include<stdio.h>
#include<stdlib.h>
struct queue{
   int a[100];
   int rear;
   int front;
   int max;
};
void enqueue(struct queue *q,int ele){
      if(q->front == q->max){
          printf("__queue is full__\n");}
      else{
          q->front ++;
          q->a[q->front]=ele;}
        }
int dequeue(struct queue *q){
      if(q->front == q->rear)
          printf("__queue is empty__\n");
       else{
          q->rear ++;
          return q->a[q->rear];}
    }
int isempty(struct queue *q){
    if(q->rear != q->front)
         return 0;
     else
         return 1;
}

int main(){
   int n;
   printf("enter no of nodes ");
   scanf("%d",&n);
   int graph[n][n];
   for (int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ )
          scanf( "%d",&graph[i][j]);
   }
   printf("The graph is :\n");
   for (int i = 0; i < n; i++ ){
      for (int j = 0; j < n; j++ )
        printf("%d ",graph[i][j]);
    printf("\n");
   }
   printf("__Breadth first search__\n");
   bfs(n,graph);
}
void bfs(int n, int graph[n][n]){
      int visit[n];
      int p;
      struct queue *q;
      q=(struct queue *)malloc(sizeof(struct queue));
      q->front=-1;
      q->rear=-1;
      q->max=n*n;
      for(int i=0;i<n;i++){
          visit[i]=0;}
      enqueue(q,0);
      while(! isempty(q)){
           p=dequeue(q);
           if(visit[p] == 0){
              visit[p]=1;
              printf("%d ",p);
              for(int j=0;j<n;j++){
                   if(graph[p][j] == 1 && visit[j] == 0){
                          enqueue(q,j);}
              }
            }
      }
}