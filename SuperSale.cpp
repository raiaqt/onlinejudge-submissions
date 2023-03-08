// 10130

#include <cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int T, N, G;
	int* price;
	int* weight;
	int* person;
	int maxWeight;
	int** memo;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		price = new int[N + 1];
		weight = new int[N + 1];
		for (int n = 1; n <= N; n++) {
			scanf("%d %d", &price[n], &weight[n]);
		}

		scanf("%d", &G);
		person = new int[G];
		for (int g = 0; g < G; g++) {
			scanf("%d", &person[g]);
			if (person[g] > maxWeight)
				maxWeight = person[g];
		}

		// create memo table
		memo = new int*[N + 1];
		for (int i = 0; i <= N; i++) {
			memo[i] = new int[maxWeight + 1];
			memo[i][0] = 0;
		}

		for (int j = 0; j <= maxWeight; j++) {
			memo[0][j] = 0;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= maxWeight; j++) {
				int weightWithout = j - weight[i];
				int priceWithout = memo[i - 1][j];
				int priceWith = weightWithout >= 0 ? memo[i - 1][weightWithout] + price[i] : 0;

				memo[i][j] = max(priceWithout, priceWith);
			}
		}

		int value = 0;
		for (int i = 0; i < G; i++) {
			value += memo[N][person[i]];
		}

		printf("%d\n", value);
	}

	return 0;
}
