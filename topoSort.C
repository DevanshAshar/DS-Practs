#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int n,adj[MAX_VERTICES][MAX_VERTICES],indegree[MAX_VERTICES]; 
int visited[MAX_VERTICES],stack[MAX_VERTICES],top = -1; 
void readGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter 0/1 for (%d,%d) ",i,j);
            scanf("%d", &adj[i][j]);
        }
    }
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i]==0) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[j][i])//imp step,j and i ki position alag hai normally karte usse kyuki indegree=no. of edges going AWAY from that vertex 
            {
                indegree[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i]==0) {
            dfs(i);
        }
    }

    printf("Topological Sort: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    readGraph();
    topologicalSort();
    return 0;
}
