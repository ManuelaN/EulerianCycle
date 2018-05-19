#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "Fleury.h"
#include "node.c"

int conex(struct ungraph *graph, int *v, int edge1, int edge2){

    int i,ok1=0,ok2=0,current_nodes1,current_nodes2,start;
    *(v+edge1*graph->no_nodes+edge2)=*(v+edge2*graph->no_nodes+edge1)=1;
    for(i=1; i<=graph->no_nodes; i++)
        if(*(v+edge1*graph->no_nodes+i)!=*(graph->adj_matrix+edge1*graph->no_nodes+i) && ok1==0){
           start=i;
           ok1=1;
    }
    else if(*(v+edge2*graph->no_nodes+i)!=*(graph->adj_matrix+edge2*graph->no_nodes+i) && ok2==0){
          start=i;
          ok2=1;
    }
    *(v+edge1*graph->no_nodes+edge2)=*(v+edge2*graph->no_nodes+edge1)=0;
    current_nodes1=graph_bfs(graph,start,v);
    *(v+edge1*graph->no_nodes+edge2)=*(v+edge2*graph->no_nodes+edge1)=1;
    current_nodes2=graph_bfs(graph,start,v);
    *(v+edge1*graph->no_nodes+edge2)=*(v+edge2*graph->no_nodes+edge1)=0;

    if(current_nodes1==current_nodes2 || (ok1==0 || ok2==0))
        return 1;
    else return 0;

}
int graph_bfs(struct ungraph *graph, int start_node, int *v){
    struct node *head_queue;
    int *visited;
    int i,aux=0,current_node;

    head_queue = calloc(1, sizeof(struct node));
    head_queue->next = NULL;
    head_queue->info = 0;
    visited = calloc((graph->no_nodes+1), sizeof(int));
    push_begining_list(head_queue, start_node);
    visited[start_node] = 1;

    while (head_queue->next != NULL){
        current_node = pop_end_list(head_queue);
        aux++;
        for(i = 1; i<=graph->no_nodes; i++){
            if ( *(v+current_node*graph->no_nodes+i)!=*(graph->adj_matrix+current_node*graph->no_nodes+i)&& ( (visited[i])==0)){
                push_begining_list(head_queue, i);
                visited[i] = 1;

            }
        }
    }

    free(head_queue);
    free(visited);
    return aux;
}
void Fleury(struct ungraph *graph, int start)
{
    int  i, j,aux=0,k,*v,p,ok;
    v=calloc((graph->no_nodes+1)*(graph->no_nodes+1),sizeof(int));
    struct node *head_cycle;
    head_cycle = calloc(1, sizeof(struct node));
    head_cycle->next = NULL;
    head_cycle->info = 0;
    push_begining_list(head_cycle,start);
    k=start;
    ok=0;
    while(graph->no_edges>=aux)
    {
        if(head_cycle->next!=NULL)
        {
            p=pop_end_list(head_cycle);
            printf("%d ", p);
            ok=0;
        }
        for(i=1; i<=graph->no_nodes; i++)
            if(*(graph->adj_matrix+k*graph->no_nodes+i)==1 && *(v+k*graph->no_nodes+i)==0 && i!=start && conex(graph,v,k,i)==1)
        {
            *(v+k*graph->no_nodes+i)=*(v+i*graph->no_nodes+k)=1;
            k=i;
            ok=1;
            push_begining_list(head_cycle, k);
            break;
        }else if(i==start && aux==graph->no_edges-1)
        {
            *(v+k*graph->no_nodes+i)=*(v+i*graph->no_nodes+k)=1;
            k=i;
            ok=1;
            push_begining_list(head_cycle, k);
            break;
        }
      if(ok==0)
        for(i=1; i<=graph->no_nodes; i++)
            if(*(graph->adj_matrix+k*graph->no_nodes+i)!=*(v+k*graph->no_nodes+i)==0)
        {
            *(v+k*graph->no_nodes+i)=*(v+i*graph->no_nodes+k)=1;
            k=i;
            ok=1;
            push_begining_list(head_cycle, k);
            break;

        }
        aux++;

    }

    free(head_cycle);
    free(v);
}
