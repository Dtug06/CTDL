#include <stdio.h>
#include <stdlib.h>

int *createGraph(int n) {
    int *graph = (int *)calloc(n * n, sizeof(int));
    return graph;
}

void addEdge(int *graph, int u, int v, int n) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        graph[u * n + v] = 1;
        graph[v * n + u] = 1;
    }
}

void printGraph(int *graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", graph[i * n + j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *graph = createGraph(n);
    int u, v;
    while (scanf("%d %d", &u, &v) == 2) {
        printf("Nhap cac canh (u v), nhan Ctrl+d de ket thuc:\n");
        addEdge(graph, u, v, n);
    }
    printGraph(graph, n);
    free(graph);
    return 0;
}
