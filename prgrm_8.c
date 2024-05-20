
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node { int data; struct Node* next; };

struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
}

void DFS(struct Node** graph, int* visited, int vertex) { 
    visited[vertex] = 1; 
    struct Node* temp = graph[vertex]; 
    while (temp) { 
        int adjVertex = temp->data; 
        if (!visited[adjVertex]) 
            DFS(graph, visited, adjVertex); 
        temp = temp->next; 
    } 
}

int isConnected(struct Node** graph, int numVertices) { 
    int* visited = (int*)calloc(numVertices, sizeof(int)); 
    DFS(graph, visited, 0); 
    for (int i = 0; i < numVertices; i++) 
        if (!visited[i]) return 0; 
    return 1; 
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
        newNode = createNode(src); 
        newNode->next = graph[dest]; 
        graph[dest] = newNode; 
    } 
    printf(isConnected(graph, V) ? "The graph is connected.\n" : "The graph is not connected.\n"); 
    return 0; 
}
