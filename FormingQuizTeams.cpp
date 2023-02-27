// 10911

#include <cstdio>
#include <cmath>

double memo[65600];
int x[20];
int y[20];
int N;
int pow2[17];

void setPow2() {
    int result = 1;
    for (int i = 0; i < 17; i++) {
        pow2[i] = result;
        result *= 2;
    }
}

double distance(int i, int j) {
    int xDist = x[i] - x[j];
    int yDist = y[i] - y[j];
    xDist *= xDist;
    yDist *= yDist;
    return sqrt(xDist + yDist);
}

double solveState(int num, int i, int j) {
    bool paired = (num & (1 << i)) && (num & (1 << j));
    if (paired) {
        int prevIndex = num & ~(1 << i) & ~(1 << j);
        int currIndex = (1 << i) | (1 << j);
        
        return (memo[prevIndex] + memo[currIndex]);
    }
    return -1;
}

double solveAll() {
    memo[0] = 0;
    for (int i = 0; i < (N * 2) - 1; i++) {
        for (int j = 1; j < N * 2; j++) {
            int index = 1 << i | 1 << j;
            memo[index] = distance(i, j);
        }
    }
    
    for (int a = 1; a < pow2[N * 2]; a++) {
        int count = __builtin_popcount(a);
        
        if (count > 2 && count % 2 == 0) {
            double min = 10000000;
            for (int i = 0; i < (N * 2) - 1; i++) {
                for (int j = i + 1; j < N * 2; j++) {
                    double dist = solveState(a, i, j);
                    if (dist >= 0 && dist < min) {
                        min = dist;
                    }
                }
            }
            memo[a] = min;
        }
    }
    
    return memo[pow2[N * 2] - 1];
} 

int main() {
    char name[25];
    int tc = 1;
    setPow2();

    scanf("%d", &N);
    
    while (N != 0) {
        for (int i = 0; i < N * 2; i++) {
            scanf("%s %d %d", name, &x[i], &y[i]);
        }
        
        double result = solveAll();
        memo[0] = 0;
        printf("Case %d: %.2f\n", tc++, result);
        scanf("%d", &N);
    }
    

    return 0;
}