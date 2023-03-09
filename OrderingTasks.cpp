#include <cstdio>

int** list;
int* size;
bool* visited;
int* sorted;
int sz;

void dfs(int task) {
    visited[task] = true;
    
    for (int i = 0; i < size[task]; i++) {
        int next = list[task][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
    sorted[sz++] = task;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while(n + m > 0) {
        n++;
        int* hasParent = new int[n];
        size = new int[n];
        list = new int*[n];
        
        for (int i = 0; i < n; i++) {
            list[i] = new int[n];
        }
        
        for (int i = 0; i < m; i++) {
            int source, dest;
            scanf("%d %d", &source, &dest);
     
            list[source][size[source]++] = dest;
            hasParent[dest] = true;
        }
        
        visited = new bool[n];
        sorted = new int[n];
        sz = 0;
        
        for (int i = 1; i < n; i++) {
            if (!hasParent[i]) {
                dfs(i);
            } 
        }
       
        for (int i = n - 2; i > 0; i--) {
            printf("%d ", sorted[i]);
        }
        printf("%d\n", sorted[0]);
        scanf("%d %d", &n, &m);
    }

    return 0;
}