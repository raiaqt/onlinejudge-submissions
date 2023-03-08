#include <cstdio>

int abs(int n) {
    return n > 0 ? n : n * -1;
}

int main() {
    int tc = 1;
    int r1, c1, r2, c2, r3, c3;
    
    while (scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3) != EOF) {
        // get absolute value of the differences
        int dr = r1 - r2;
        int dc = c1 - c2;
        int drAbs = abs(dr);
        int dcAbs = abs(dc);
        
        int dr1 = r1 - r3;
        int dc1 = c1 - c3;
        int dr1Abs = abs(dr1);
        int dc1Abs = abs(dc1);
        
        int dr2 = r3 - r2;
        int dc2 = c3 - c2;
        int result;
        
        if (drAbs == dcAbs && dr1Abs == dc1Abs && dr1 * dr2 > 0 && dc1 * dc2 > 0) {
            // block is on the same direction as destination
            result = drAbs + 1;
        } else {
            result = drAbs > dcAbs ? drAbs : dcAbs;
        }
        printf("Case %d: %d\n", tc++, result);
    }

    return 0;
}