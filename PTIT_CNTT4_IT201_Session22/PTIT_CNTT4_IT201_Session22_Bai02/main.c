#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v) {
    Node* node1 = createNode(v);
    node1->next = adjList[u];
    adjList[u] = node1;

    Node* node2 = createNode(u);
    node2->next = adjList[v];
    adjList[v] = node2;
}

void printGraph(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* adjList[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    int u, v;
    while (scanf("%d %d", &u, &v) == 2) {
        printf("Nhap cac canh (u v), nhan Ctrl+d de ket thuc:\n");
        addEdge(adjList, u, v);
    }

    printGraph(adjList, n);
    freeGraph(adjList, n);

    return 0;
}
