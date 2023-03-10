// 291

#include <iostream>

int size[6] = {0, 3, 4, 4, 2, 4};
int neighbor[6][4] = {{0, 0, 0, 0},
                    {2, 3, 5, 0},
                    {1, 3, 5, 0},
                    {1, 2, 4, 5},
                    {3, 5, 0, 0},
                    {1, 2, 3, 4}};
bool visited[6][6];
int result[9];
void findNext(int x, int index) {
    if (index == 9) {
        for (int i = 0; i < 9; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
        return;
    }
    result[index] = x;
    for (int i = 0; i < size[x]; i++) {
        int next = neighbor[x][i];
        if (!visited[x][next]) {
            visited[x][next] = true;
            visited[next][x] = true;
            findNext(next, index + 1);
            visited[x][next] = false;
            visited[next][x] = false;
        }
    }
}

int main() {
    findNext(1, 0);

    return 0;
}