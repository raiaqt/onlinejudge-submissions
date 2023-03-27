#include <cstdio>

int main() {
    int N;
    int set = 1;
    scanf("%d", &N);

    while (N != 0) {
        int heights[N];
        for (int i = 0; i < N; i++) {
        	scanf("%d", &heights[i]);
        }

        int total = 0;
        for (int i = 0; i < N; i++) {
        	total += heights[i];
        }

        int wall = total / N;

        int moves = 0;
        for (int i = 0; i < N; i++) {
        	int diff = wall - heights[i];
        	if (diff > 0) {
        		moves += diff;
        	}
        }

        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n\n", moves);

    	scanf("%d", &N);
    	set++;
    }

    return 0;
}
