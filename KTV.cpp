// 11218

#include <cstdio>

int countOnes(int num) {
    int ones = 0;
    for (int i = 0; i < 9; i++) {
        if (num & (1 << i)) {
            ones++;
        }
    }
    return ones;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    const int size = 512;
    int N, c;
    scanf("%d", &N);
    int scores[size];
   
    int t = 1;
    while (N != 0) {
        for (int i = 0; i < size; i++) {
            scores[i] = -1;
        }
        
        for (int n = 0; n < N; n++) {
            int id = 0;
            int score;
            for (int i = 0; i < 3; i++) {
                scanf("%d", &c);
                id = id | (1 << c - 1);
            }
            scanf("%d", &score);
            
            scores[id] = score;
        }
        
        for (int n = 0; n < size; n++) {
            int ones = countOnes(n);
            if (ones == 6 || ones == 9) {
                for (int i = 0; i < n; i++) {
                    if (countOnes(i) == (ones - 3) && (n & i) == i) {
                        int j = n - i;
                        if (scores[i] != -1 && scores[j] != -1) {
                            scores[n] = max(scores[n], scores[i] + scores[j]);
                        }
                    }
                }
            }
        }
        
        printf("Case %d: %d\n", t++, scores[size - 1]);
        scanf("%d", &N);
    }

    return 0;
}