#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "Fleury.h"
#include "Fleury.c"
#include "Hierholzer.h"
#include "Hierholzer.c"

int i,j;
void read_graph(struct ungraph *graph,int *found)
{
 int *vect_n,aux,nr_gd,k;
 vect_n=calloc(graph->no_nodes+1,sizeof(int));

  if(*found==1){
    graph->no_edges=0;
    for(graph->v1=1; graph->v1<=graph->no_nodes;graph->v1++)
    { i=graph->v1;
      for(graph->v2=k; graph->v2<=graph->no_nodes ;graph->v2++){
         j=graph->v2;
         if(i!=j && *(graph->adj_matrix +graph->no_nodes*i + j)==0 ){
           *(graph->adj_matrix +graph->no_nodes*i + j)=*(graph->adj_matrix +graph->no_nodes*j+i)=rand()%2;
           *(vect_n+i)=*(vect_n+i)+1;
           *(vect_n+j)=*(vect_n+j)+1;
       }
      }
    graph->no_edges+=*(vect_n+i);
  }

  }

    if(*found==-1){
        for(i=1; i<=graph->no_edges; i++)
        {
              scanf("%d %d", &graph->v1, &graph->v2);

      *(graph->adj_matrix + graph->v1*graph->no_nodes+graph->v2)=1;
      *(graph->adj_matrix + graph->v2*graph->no_nodes +graph->v1)=1;
      *(vect_n+graph->v1)=*(vect_n+graph->v1)+1;
      *(vect_n+graph->v2)=*(vect_n+graph->v2)+1;}
    }
  for( i=1; i<=graph->no_nodes; i++)
      if(*(vect_n+i)%2!=0 || *(vect_n+i)==0){
          *found=0;
          break;
      }

}

void print_graph(struct ungraph *graph)
{
    printf("Matricea de adiacenta a grafului este:\n");
    for(i=1; i<=graph->no_nodes; i++){
        for(j=1; j<=graph->no_nodes; j++)
            printf("%d ", *(graph->adj_matrix + i*graph->no_nodes +j));
      printf("\n");
    }
}
int main()
{
    int found=1,start;
    int choice;
    struct ungraph *graph;
    graph = calloc(1, sizeof(struct ungraph));
    while(1>0)
    {
        printf("\n1 Citire matrice adiaceta random\n");
        printf("2 Citire matrice adiacenta de la tastatura\n");
        printf("3 Afisare matrice adiacenta\n");
        printf("4 Metoda Fleury\n");
        printf("5 Metoda Hierholzer\n");
        printf("6 Iesire program\n");

        printf("Tastati alegerea:");
        scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("n=");
            srand((unsigned)time(NULL));
            graph->no_nodes=rand()%20;
            while(graph->no_nodes==0 || graph->no_nodes<3)
                graph->no_nodes=rand()%20;
            printf("%d", graph->no_nodes);

            graph->adj_matrix = calloc((graph->no_nodes+1) *(graph->no_nodes+1), sizeof(int));
            read_graph(graph,&found);
            break;

        case 2:
                printf("n=");
                scanf("%d", &graph->no_nodes);

                printf("\nnr. muchii=");
                scanf("%d", &graph->no_edges);
                graph->adj_matrix = calloc((graph->no_nodes+1) *(graph->no_nodes+1), sizeof(int));
                found=-1;

                read_graph(graph,&found);
                break;

        case 3:
            if(graph->no_nodes==0)
                printf("Nu s-a citit graful.\n");
            else if(found==1 || found==-1)
                print_graph(graph);
            else if(found==0)
            {
                printf("Nu exista ciclu eulerian.\n");
                print_graph(graph);
            }

            break;

        case 4:
            start=1;
            Fleury(graph,start);

            break;
        case 5:
            start=1;
            Hierholzer(graph,start);
            break;
        case 6:
            exit(0);

        default:
            printf("Operator gresit.\n");

    }}

    return 0;
}
