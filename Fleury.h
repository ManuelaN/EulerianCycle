#ifndef FLEURY_H_INCLUDED
#define FLEURY_H_INCLUDED

struct ungraph
{
    int no_nodes;
    int v1,v2;
    int no_edges;
    int *adj_matrix;
}*graph;

int conex(struct ungraph *graph, int *v, int edge1, int edge2);
int graph_bfs(struct ungraph *graph, int start_node, int *v);
void Fleury(struct ungraph *graph, int start);


#endif // FLEURY_H_INCLUDED
