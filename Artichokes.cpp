// 1709

#include <cstdio>
#include <iostream>
#include <cmath>

double getPrice (int p, int a, int b, int c, int d, int n, int k) {
    double price = p * (sin((a * k) + b) + cos((c * k) + d) + 2);
    return price;
}
int main() {
    int p, a, b, c, d, n;

    bool cont = true;
    while (cont) {
        int scanned = scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);

        if (scanned == 6) {
            double max = getPrice(p, a, b, c, d, n, 1);
            double res = 0;

            for (int k = 2; k <= n; k++) {
                double price = getPrice(p, a, b, c, d, n, k);

                if (price > max) {
                    max = price;
                } else {
                    double kRes = max - price;
                    if (kRes > res) {
                        res = kRes;
                    }
                }
            }

            if (res == 0) {
                printf("0.00\n");
            } else {
                printf("%.7f\n", res);
            }
        } else {
            cont = false;
        }
    }

    return 0;
}
