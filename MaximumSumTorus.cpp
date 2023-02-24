// 10827

#include <iostream>
#include <cstdio>

int T, N;
int torus[80][160];

int getRowSum(int i, int j, int r) {
    int s = i == 0 ? 0 : torus[r][i - 1];
    int rowSum = torus[r][j] - s;

    return rowSum;
}

int main()
{

    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int num;
                scanf("%d", &num);
                torus[i][j] = num;
                torus[i][j + N] = num;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N * 2; j++)
            {
                torus[i][j] += torus[i][j - 1];
            }
        }

        int maxSum = 0;
        // inclusive i, j
        for (int i = 0; i < N; i++) {
            for (int j = i; j < i + N; j++) {
                // max 1D sum per start

            	for (int start = 0; start < N; start++) {
            		int currSum = 0;
            		for (int r = start; r < start + N; r++) {
            			int currRow = r % N;
            			currSum += getRowSum(i, j, currRow);
            			if (currSum < 0) currSum = 0;

            			if (currSum > maxSum) maxSum = currSum;
            		}
            	}
            }
        }

        printf("%d\n", maxSum);
    }
    return 0;
}
