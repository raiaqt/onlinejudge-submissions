// 11760

#include <cstdio>

int R, C, N;
const int dr[5] = {0, -1, 0, 1, 0};
const int dc[5] = {0, 0, 1, 0, -1};

bool canEscape(bool* rows, bool* cols, int arifR, int arifC) {
    for (int i = 0; i < 5; i++) {
        int r = arifR + dr[i];
        int c = arifC + dc[i];
        
        if (r >= 0 && c >= 0 && r < R && c < C) {
            if (!rows[r] && !cols[c]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d %d", &R, &C, &N);
    int t = 1;
    while (R + C + N > 0) {
        bool* rows = new bool[R];
        bool* cols = new bool[C];
        int arifR, arifC;
        int r, c;
        for (int n = 0; n < N; n++) {
            scanf("%d %d", &r, &c);
            rows[r] = true;
            cols[c] = true;
        }
        scanf("%d %d", &arifR, &arifC);
        
        bool escaped = canEscape(rows, cols, arifR, arifC);
        
        printf("Case %d: ", t++);
        if (escaped) {
            printf("%s\n", "Escaped again! More 2D grid problems!");
        } else {
            printf("%s\n", "Party time! Let's find a restaurant!");
        }
        
        scanf("%d %d %d", &R, &C, &N);
    }
}
