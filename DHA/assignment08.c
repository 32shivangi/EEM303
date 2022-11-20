//DFS in graph
#include <stdio.h>
#include<stdlib.h>
#define V 10
int main() 
{
 struct stack
 {
     int adj[V];
     int top;
 };

 struct node
 {      int d;
        struct node * next;
    };

struct Graph
{      struct node * vertices[V];
      int vis[V];
    };
 struct edge 
 {    int s;
      int d;
    };

    struct stack * create()
    {
        struct stack * S=(struct stack *)malloc(sizeof(struct stack));
        S->top=-1;
        return S;
    }

    struct stack * push(struct stack *SS, int val)
    {
        SS->top++;
        SS->adj[SS->top]=val;
        return SS;

    }

    int  pop(struct stack *SS)
    {
        int R=SS->adj[SS->top];
        SS->top--;
        return R;
    }

    void print(struct stack *S)
    {
        for(int i=0;i<=S->top;i++)
        {
            printf("%d ",S->adj[i]);
        }
    }
   /* struct stack *A=create();
    A= push(A,3);
    A= push(A,5);
    A= push(A,6);
    print(A);
    printf("\n");
    A= pop(A);
    print(A);
    */
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

    void dfs(struct Graph * gr, int start)
    {
        for (int i = 0; i < V; i++)
        {
            gr->vis[i] = 0;
        }
        printf(">>DFS Traversal<<\n");
        struct Graph * graph = gr;
        struct stack * q = create();
        q = push(q, start); 
        graph->vis[start] = 1; 

        while  (q->top > -1)
        {
             int visit = pop(q);
            printf("%d->", visit); 
            struct node * temp = graph->vertices[visit]; 
            while (temp)
            {
                if (graph->vis[temp->d] == 0)
                {
                    q = push(q, temp->d);
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
    //printf("%d",g->vertices[2]->d);
    dfs(g,1);

    struct stack * s = create();
    s=push(s, 1);
    s=push(s, 2);
    s=push(s, 3);
    
    for (int i = 0; i<=s->top; i++)
    printf("%d",s->adj[i]);
    int popped = pop(s);
    printf("\n%d",popped);
    printf("\n%d",s->top);
    return 0;
}
