#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int T;
	int seq[1000005];
	int sum[1000005];
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &seq[i]);
		}

		sum[0] = 0;

		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + seq[i];
		}

		int total = 0;
		unordered_map<int, int> map;

		for (int i = 0; i < N + 1; i++) {
			int num = sum[i];
			total += map[num - 47];

			map[num]++;
		}
		printf("%d\n", total);
	}
	return 0;
}
