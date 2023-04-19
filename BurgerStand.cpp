// 13048

#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    
    char S[51];
    for (int t = 1; t <= T; t++) {
        scanf("%s", S);
        
        int i = 0;
        while (S[i] != '\0') {
            if (S[i] == 'B') {
                if (i - 1 >= 0) {
                    S[i - 1] = 'A';
                }
                if (i - 2 >= 0) {
                    S[i - 2] = 'A';
                }
            } else if (S[i] == 'S') {
                if (i - 1 >= 0) {
                    S[i - 1] = 'A';
                }
                if (S[i + 1] != '\0' && S[i + 1] == '-') {
                    S[i + 1] = 'A';
                }
            }
            i++;
        }
        
        int total = 0;
        i = 0;
        while (S[i] != '\0') {
            if (S[i] == '-') {
                total++;
            }
            i++;
        }
        
        printf("Case %d: %d\n", t, total);
    }

    return 0;
}