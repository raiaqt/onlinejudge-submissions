// Online C++ compiler to run C++ program online
#include <cstdio>

int graph[8][8] = {
    {1, 2, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 0, 0, 0, 0, 0},
    {2, 4, 0, 0, 0, 0, 0, 0},
    {3, 5, 6, 0, 0, 0, 0, 0},
    {4, 6, 7, 0, 0, 0, 0, 0},
    {4, 5, 0, 0, 0, 0, 0, 0},
    {7, 0, 0, 0, 0, 0, 0, 0},
};
int size[8] = {2, 2, 3, 2, 3, 3, 2, 1};

bool visited[8];
int id[8];
int low[8];
int parent[8];
int pAdj = 0;
int counter = 0;
int pId = 0;

void dfs(int u) {
    bool ap = false;
    visited[u] = true;
    id[u] = counter++;
    low[u] = id[u];
    
    for (int i = 0; i < size[u]; i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            if(id[u] == pId)
                pAdj++;
            parent[v] = u;
            dfs(v);
            
            if (id[u] <= low[v])
                ap = true;
            if (id[u] < low[v])
                printf("Bridge: %d - %d\n", u, v);
        }
        
        if (parent[u] != v) {
            if (low[v] < low[u])
                low[u] = low[v];
        }
    }
    
    if ((id[u] == pId && pAdj > 1) || (id[u] != pId && ap)) {
        printf("Articulation point: %d\n", u);
    }
}

int main() {
    dfs(0);
    
    return 0;
}