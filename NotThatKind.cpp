#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    
    int val[55];
    char in[55];
    for (int t = 1; t <= T; t++) {
        scanf("%s", in);
        
        int size = 0;
        int num = 100;
        int min = 200;
        int max = 0;
        
        while (in[size] != '\0') {
            int n = num;
            if (in[size] == 'R') {
                n = num;
                num++;
                val[size] = n;
            } else if (in[size] == 'F') {
                num--;
                n = num;
                val[size] = n;
            } else {
                val[size] = num;
            }
            size++;
            if (n > max) max = n;
            if (n < min) min = n;
        }
        
        printf("Case #%d:\n", t);
        for (int i = 0; i < max - min + 1; i++) {
            printf("| ");
            int space = 0;
            for (int j = 0; j < size; j++) {
                if (val[j] == max - i) {
                    if (in[j] == 'R') {
                        printf("%*s", space + 1, "/");
                        space = 0;
                    } else if (in[j] == 'F') {
                        printf("%*s", space + 1, "\\");
                        space = 0;
                    } else {
                        printf("%*s", space + 1, "_");
                        space = 0;
                    }
                } else {
                    space++;
                }
            }
            printf("\n");
        }
        printf("+");
        for (int i = 0; i < size + 2; i++) {
            printf("-");
        }
        printf("\n\n");
    }

    return 0;
}