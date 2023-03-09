#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while(n + m > 0) {
        n++;
        int* hasParent = new int[n];
        int* size = new int[n];
        int** list = new int*[n];
        for (int i = 0; i < n; i++) {
            list[i] = new int[n];
        }
        
        for (int i = 0; i < m; i++) {
            int source, dest;
            scanf("%d %d", &source, &dest);
     
            list[source][size[source]++] = dest;
            hasParent[dest] = true;
        }
        
        // bfs
        int* queue = new int[n];
        bool* visited = new bool[n];
        int start = 0;
        int end = 0;
        
        for (int i = 1; i < n; i++) {
            if (!hasParent[i]) {
                queue[end++] = i;
                visited[i] = true;
            } 
        }
        
        while (start < end) {
            int task = queue[start++];
            for (int i = 0; i < size[task]; i++) {
                int next = list[task][i];
                if (!visited[next]) {
                    queue[end++] = next;
                }
            }
        }
        for (int i = 0; i < n - 2; i++) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[n - 2]);
        scanf("%d %d", &n, &m);
    }

    return 0;
}