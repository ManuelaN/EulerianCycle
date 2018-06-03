#include <stdio.h>
#include <stdlib.h>
#include "Hierholzer.h"
#include "Fleury.h"

void Hierholzer(struct ungraph *graph, int start_node)
{
    struct node *head_stack, *head_stack1;
    int current,*v,i,ok;

    head_stack = calloc(1, sizeof(struct node));
    head_stack->next = NULL;
    head_stack->info = 0;
    v= calloc((graph->no_nodes+1)*(graph->no_nodes+1), sizeof(int));
    push_begining_list(head_stack, start_node);

    head_stack1 = calloc(1, sizeof(struct node));
    head_stack1->next = NULL;
    head_stack1->info = 0;
    current=start_node;

    while(head_stack->next!=NULL){

        ok=0;
        for(i=graph->no_nodes;i>=1 && ok==0;i--){
            if(*(graph->adj_matrix+current*graph->no_nodes+i)!=*(v+current*graph->no_nodes+i)){
                *(v+current*graph->no_nodes+i)=*(v+i*graph->no_nodes+current)=1;
                current=i;
                push_begining_list(head_stack,current);
                ok=1;

            }

       }

       if(ok==0){
          current=pop_begining_list(head_stack);
          push_begining_list(head_stack1,current);

       }
    }

    while(head_stack1->next!=NULL){
        current=pop_begining_list(head_stack1);
        printf("%d ", current);
    }


    free(head_stack);
    free(head_stack1);
    free(v);
}
