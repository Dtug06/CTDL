#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest) {
    if (src >= 0 && src < graph->V && dest >= 0 && dest < graph->V) {
        graph->matrix[src][dest] = 1;
        graph->matrix[dest][src] = 1;
    } else {
        printf("dinh khong hop le .\n");
    }
}
void printGraph(Graph *graph) {
    printf("Ma trận kề:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}
int main() {
    Graph *graph = createGraph(3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}
