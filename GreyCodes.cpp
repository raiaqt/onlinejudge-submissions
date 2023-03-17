#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N, K;
        scanf("%d %d", &N, &K);
        
        int R = 0;
        bool rev = false;
        for (int i = 0; i < N; i++) {
            int ithBit = 1 << (N - i - 1);
            bool on = K & ithBit;
            
            if (on != rev) {
                R = R | ithBit;
                rev = !rev;
            }
        }
        
        printf("%d\n", R);
    }
}
