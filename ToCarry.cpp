// 10469

#include <cstdio>

bool isOne(unsigned int num, int bit) {
    return num & (1 << bit);
}

int main() {
    unsigned int A, B, C;
    
    while (scanf("%d %d", &A, &B) != EOF) {
        C = 0;
        for (int i = 0; i < 32; i++) {
            if (isOne(A, i) != isOne(B, i)) {
                C += 1 << i;
            }
        }
        printf("%d\n", C);
    }
    
    return 0;
}