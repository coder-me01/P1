
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void DFS(struct Node** graph, int* visited, int vertex, struct Node** stack) {
    visited[vertex] = 1;
    struct Node* temp = graph[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            DFS(graph, visited, adjVertex, stack);
        temp = temp->next;
    }
    *stack = createNode(vertex);
    (*stack)->next = temp;
}

void topologicalSort(struct Node** graph, int numVertices) {
    int* visited = calloc(numVertices, sizeof(int));
    struct Node* stack = NULL;
    for (int i = 0; i < numVertices; i++)
        if (!visited[i])
            DFS(graph, visited, i, &stack);
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    free(visited);
}

int main() {
    int V, E;
    printf("Enter V and E: ");
    scanf("%d %d", &V, &E);
    struct Node* graph[MAX_VERTICES] = {NULL};
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        struct Node* newNode = createNode(dest);
        newNode->next = graph[src];
        graph[src] = newNode;
    }
    printf("Topological order: ");
    topologicalSort(graph, V);
    return 0;
}



