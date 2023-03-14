#include <cstdio>

const char QUERY = 'E';
const char JOIN = 'I';
const char STOP = 'O';
int* parent;
int* distance;

int getDistanceSum(int child) {
    int curr = child;
    int distanceSum = 0;
    while (parent[curr] != curr) {
        distanceSum = (distanceSum + distance[curr]) % 1000;
        curr = parent[curr];
    }
    return distanceSum;
}

int getDistance(int i, int j) {
    int d = i - j;
    d = d >= 0 ? d : d * -1;
    return d % 1000;
}

int main() {
    int T, N;
    
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        N++; // 1-indexed
        parent = new int[N];
        distance = new int[N];
        
        // initialize self as parent
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        
        char command;
        scanf("%c", &command);
        while (command != STOP) {
            if (command == QUERY) {
                int q;
                scanf("%d", &q);
                printf("%d\n", getDistanceSum(q));
            } else if (command == JOIN) {
                int i, j;
                scanf("%d %d", &i, &j);
        
                parent[i] = j;
                distance[i] = getDistance(i, j);
            }
            scanf("%c", &command);
        }
    }
 
    return 0;
}