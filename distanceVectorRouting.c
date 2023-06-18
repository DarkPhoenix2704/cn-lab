#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INFINITY 9999

struct Edge {
    int source, destination, weight;
};

void bellmanFord(int numNodes, int numEdges, struct Edge edges[], int source) {
    int distance[MAX_NODES];

    // Step 1: Initialize distance from source to all other nodes as infinity
    for (int i = 0; i < numNodes; i++) {
        distance[i] = INFINITY;
    }
    distance[source] = 0;

    // Step 2: Relax all edges numNodes-1 times
    for (int i = 1; i < numNodes; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INFINITY && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (distance[u] != INFINITY && distance[u] + weight < distance[v]) {
            printf("Negative-weight cycle detected\n");
            return;
        }
    }

    // Step 4: Print the distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int numNodes, numEdges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Edge edges[MAX_NODES];
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    bellmanFord(numNodes, numEdges, edges, source);

    return 0;
}
