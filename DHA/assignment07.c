//BFS in graph
#include <stdio.h>
#include <stdlib.h>
#define V 10
int main() 
{
    struct queue 
    {
      int adj[V];
      int front;
      int rear;
    }; 
   
    struct node 
    {
        int d;
        struct node * next;
    };
   
    struct Graph
    {
      struct node * vertices[V];  
      int vis[V];
    }; 
   
    struct edge
    {
      int s;
      int d;
    }; 
   
    struct queue * createQ() 
    {
      struct queue* Q = malloc(sizeof(struct queue));
      Q->front = -1;
      Q->rear = -1;
      return Q;
    }
   
    struct queue * enq(struct queue * q, int toVisit)
    {
        struct queue * Q = q;
        if (Q->rear==-1) Q->front++;
        Q->rear++;
        Q->adj[Q->rear] = toVisit;
        return Q;
    }
   
    int deq(struct queue * q)
    {
        struct queue * Q = q;
        int removed = Q->adj[Q->front];
        Q->front++;
        return removed;
    }
   
    void printQ(struct queue * q)
    {
        struct queue * Q = q;
        for(int i = Q->front; i < Q->rear; i++)
        {
            printf("%d,",Q->adj[i]);
        }
        printf("\n");
    }
   
    struct Graph * e2g(struct edge edges[], int e)
    {
        struct Graph * graph = (struct Graph *)malloc(sizeof(struct Graph));
        for (int i = 0; i < V; i++)
        {
            graph->vertices[i] = NULL; 
        }
        for (int i = 0; i < e; i++)
        { 
            int src = edges[i].s;
            int dest = edges[i].d;
           
            struct node * newNode = (struct node *)malloc(sizeof(struct node));
            newNode->d = dest; 
            newNode->next = graph->vertices[src];
            graph->vertices[src] = newNode; 
        }
        return graph;
    }
   
    void bfs(struct Graph * gr, int start)
    {
        for (int i = 0; i < V; i++)
        {
            gr->vis[i] = 0;
        }
      
        printf(">>BFS Traversal<<\n");
        struct Graph * graph = gr;
        struct queue * q = createQ();
        q = enq(q, start);    
        graph->vis[start] = 1; 
       
        while  (q->front <= q->rear)
        { 
          
          int visit = deq(q);  
          printf("%d->", visit); 
            
            struct node * temp = graph->vertices[visit]; 
            while (temp)
            {
                if (graph->vis[temp->d] == 0)
                {
                    q = enq(q, temp->d);
                
                    graph->vis[temp->d] = 1;
                }
                temp = temp->next;
            }
           
        }
        printf("END\n"); 
    }
   

    struct edge edges [] = {{1,2}, {1,3}, {2,3}, {2,4}, {3,4}, {4,5}};
    int num = sizeof(edges)/sizeof(edges[0]);
   
    struct Graph * g = e2g(edges, num);
   
    bfs(g,1);
   
    return 0;
   
}
