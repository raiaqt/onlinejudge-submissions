// 1641

#include <cstdio>

int main() {
	int W, H;
	char line[105];

	while (scanf("%d %d", &H, &W) != EOF) {
		int area = 0;
		for (int i = 0; i < H; i++) {
			scanf("%s", line);

			bool inside = false;

			for (int j = 0; j < W; j++) {
				if (line[j] == '/' || line[j] == '\\') {
					inside = !inside;
					area += 1;
				} else if (inside) {
					area += 2;
				}
			}
		}

		area /= 2;
		printf("%d\n", area);
	}
    return 0;
}
