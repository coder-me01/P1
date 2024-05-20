
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Node { int vertex, weight; struct Node* next; };

struct Node* createNode(int vertex, int weight) { 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    newNode->vertex = vertex; 
    newNode->weight = weight; 
    newNode->next = NULL; 
    return newNode; 
}

void dijkstra(struct Node** graph, int numVertices, int startVertex) {
    int* dist = calloc(numVertices, sizeof(int));
    for (int i = 0; i < numVertices; i++) dist[i] = INT_MAX;
    dist[startVertex] = 0;
    for (int i = 0; i < numVertices - 1; i++) {
        int minIndex = -1, minDist = INT_MAX;
        for (int j = 0; j < numVertices; j++) {
            if (dist[j] < minDist) { minIndex = j; minDist = dist[j]; }
        }
        struct Node* temp = graph[minIndex];
        while (temp) {
            if (dist[minIndex] != INT_MAX && dist[minIndex] + temp->weight < dist[temp->vertex]) {
                dist[temp->vertex] = dist[minIndex] + temp->weight;
            }
            temp = temp->next;
        }
        dist[minIndex] = INT_MAX;
    }
    printf("Shortest paths from vertex %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) printf("To %d: %d\n", i, dist[i]);
    free(dist);
}

int main() {
    int V = 5, E = 6, startVertex = 0;
    struct Node* graph[MAX_VERTICES] = {NULL};
    int edges[6][3] = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}};
    printf("Shortest paths for the given graph:\n");
    for (int i = 0; i < E; i++) {
        int src = edges[i][0], dest = edges[i][1], weight = edges[i][2];
        graph[src] = createNode(dest, weight);
        graph[src]->next = graph[src];
        graph[dest] = createNode(src, weight);
        graph[dest]->next = graph[dest];
    }
    dijkstra(graph, V, startVertex);
    return 0;
}


