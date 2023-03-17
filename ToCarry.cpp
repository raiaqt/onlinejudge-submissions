#include <cstdio>

int main() {
    int A, B, C;
    
    while (scanf("%d %d", &A, &B) != EOF) {
        C = A ^ B;
        printf("%d\n", C);
    }
    
    return 0;
}