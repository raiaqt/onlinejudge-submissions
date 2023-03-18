// 1368

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	const char bases[4] = {'A', 'C', 'G', 'T'};
	char DNA[50][1005];
	int count[1005][4];
	int error;
	int code[50][1005];
	char consensus[1005];

	for (int t = 0; t < T; t++) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			scanf("%s", DNA[i]);

			for (int j = 0; j < m; j++) {
				if (DNA[i][j] == 'A') { code[i][j] = 0; }
				else if (DNA[i][j] == 'C') { code[i][j] = 1; }
				else if (DNA[i][j] == 'G') { code[i][j] = 2; }
				else if (DNA[i][j] == 'T') { code[i][j] = 3; }
			}
		}

		for (int i = 0; i < 1005; i++) {
			consensus[i] = 0;
			for (int j = 0; j < 4; j++) {
				count[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int base = code[i][j];
				count[j][base]++;
			}
		}

		error = 0;
		for (int i = 0; i < m; i++) {
			int max = 0;
			int maxIndex = 0;

			for (int j = 0; j < 4; j++) {
				if (count[i][j] > max) {
					max = count[i][j];
					maxIndex = j;
				}
			}
			consensus[i] = bases[maxIndex];
			error += (n - count[i][maxIndex]);
		}

		printf("%s\n%d\n", consensus, error);
	}
	return 0;
}
 