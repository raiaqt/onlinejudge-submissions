#include <cstdio>

int main() {
    const int max = 1000000005;
    int T, N;
    
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        int *lastOccurrence = new int[max];
        int lastRepeat = 0;
        int maxRange = 0;
        
        for (int i = 1; i <= N; i++) {
            int s;
            scanf("%d", &s);
            if (lastOccurrence[s] > lastRepeat) {
                lastRepeat = lastOccurrence[s];
            }
            int indexMaxRange = i - lastRepeat;
            if (indexMaxRange > maxRange)
                maxRange = indexMaxRange;
            lastOccurrence[s] = i;
        }
        
        printf("%d\n", maxRange);
    }

    return 0;
}