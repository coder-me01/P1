
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge { int src, dest, weight; };

struct Subset { int parent, rank; };

struct Subset* createSubset(int parent, int rank) { 
    struct Subset* subset = malloc(sizeof(struct Subset)); 
    subset->parent = parent; 
    subset->rank = rank; 
    return subset; 
}

int find(struct Subset** subsets, int i) { 
    if (subsets[i]->parent != i) 
        subsets[i]->parent = find(subsets, subsets[i]->parent); 
    return subsets[i]->parent; 
}

void Union(struct Subset** subsets, int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
    if (subsets[xroot]->rank < subsets[yroot]->rank) 
        subsets[xroot]->parent = yroot; 
    else if (subsets[xroot]->rank > subsets[yroot]->rank) 
        subsets[yroot]->parent = xroot; 
    else { 
        subsets[yroot]->parent = xroot; 
        subsets[xroot]->rank++; 
    } 
}

int compare(const void* a, const void* b) { 
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight; 
}

void KruskalMST(struct Edge* edges, int numVertices, int numEdges) {
    struct Subset** subsets = malloc(numVertices * sizeof(struct Subset*));
    for (int i = 0; i < numVertices; i++) 
        subsets[i] = createSubset(i, 0);
    struct Edge* result = malloc((numVertices - 1) * sizeof(struct Edge));
    qsort(edges, numEdges, sizeof(edges[0]), compare);
    int i = 0, e = 0;
    while (i < numVertices - 1 && e < numEdges) {
        struct Edge nextEdge = edges[e++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) { 
            result[i++] = nextEdge; 
            Union(subsets, x, y); 
        } 
    }
    printf("Edges of Minimum Cost Spanning Tree:\n");
    for (int j = 0; j < i; j++) 
        printf("%d -- %d\t Weight: %d\n", result[j].src, result[j].dest, result[j].weight);
    free(result);
    for (int j = 0; j < numVertices; j++) 
        free(subsets[j]);
    free(subsets);
}

int main() {
    int V = 5, E = 6;
    struct Edge edges[MAX_EDGES] = { {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1} };
    KruskalMST(edges, V, E);
    return 0;
}


