// 12658

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    char temp[50];
    char line[50];

    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        scanf("%s", temp);
    }

    scanf("%s", line);
    scanf("%s", temp);

    for (int i = 0; i < (n * 4); i++) {
        if (line[i] == '*') {
            if (i % 4 == 1) printf("%d", 1);
            if (i % 4 == 0) printf("%d", 2);
            if (i % 4 == 2) printf("%d", 3);
        }
    }

    printf("\n");
    return 0;
}