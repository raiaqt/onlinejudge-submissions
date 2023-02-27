// 929

#include <cstdio>

struct Node {
    int n;
    int m;
    int d;
};

const int dn[4] = {-1, 0, 1, 0};
const int dm[4] = {0, 1, 0, -1};
const int MAX_SIZE = 1000005;
struct Node heap[MAX_SIZE];
int size = 0;
int grid[1000][1000];
int cost[1000][1000];
bool visited[1000][1000];
int N, M;

void swap(int i, int j) {
    struct Node temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push(int d, int n, int m) {
    int curr = size;
    struct Node* newNode = new Node;
    newNode->d = d;
    newNode->n = n;
    newNode->m = m;
    heap[size++] = *newNode;
    
    while (curr != 0) {
        int parent = (curr - 1) / 2;
        if (heap[curr].d < heap[parent].d) {
            swap(curr, parent);
            curr = parent;
        } else {
            break;
        }
    }
}

struct Node pop() {
    struct Node min = heap[0];
    
    swap(0, --size);
    int start = 0;
    while(true) {
        int left = (start * 2) + 1;
        int right = (start * 2) + 2;
        int curr = start;
        
        if (left < size) {
            if (heap[left].d <= heap[curr].d)
                curr = left;
        }
        if (right < size) {
            if (heap[right].d <= heap[curr].d)
                curr = right;
        }
        if (curr != start) {
            swap(curr, start);
            start = curr;
        } else {
            break;
        }
    }
    
    return min;
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        size = 0;
        scanf("%d %d", &N, &M);
        
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                scanf("%d", &grid[n][m]);
                cost[n][m] = 20000000;
                visited[n][m] = false;
            }
        }
        
        
        cost[0][0] = grid[0][0];
        
        push(cost[0][0], 0, 0);
        while(size > 0) {
            struct Node curr = pop();
            
            for (int i = 0; i < 4; i++) {
                int nextN = curr.n + dn[i];
                int nextM = curr.m + dm[i];
                if (nextN >= 0 && nextM >= 0 && nextN < N && nextM < M) {
                    if (!visited[nextN][nextM]) {
                        int newCost = curr.d + grid[nextN][nextM];
                        if (newCost < cost[nextN][nextM]) {
                            cost[nextN][nextM] = newCost;
                            push(newCost, nextN, nextM);
                        }
                    }
                }
            }
            
            visited[curr.n][curr.m] = true;
        }
        
        printf("%d\n", cost[N - 1][M - 1]);
    }
    
    
    return 0;
}