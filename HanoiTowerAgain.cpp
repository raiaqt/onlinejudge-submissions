// 10276

#include <cstdio>
#include <iostream>

using namespace std;

int memo[52];

int main() {
    int T;
    scanf("%d", &T);

    memo[0] = 1;
    memo[1] = 2;
    memo[2] = 4;
    
    for (int i = 3; i <= 50; i = i + 2) {
        memo[i] = memo[i - 1] + i + 1;
        memo[i + 1] = memo[i] + i + 1;
    }

    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        printf("%d\n", memo[N] - 1);
    }
    return 0;
}
