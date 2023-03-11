// 11764

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int walls, prevHeight, currHeight;
		int highJump = 0;
		int lowJump = 0;

		scanf("%d", &walls);

		if (walls != 0) {
			scanf("%d", &prevHeight);
		}

		for (int i = 1; i < walls; i++) {
			scanf("%d", &currHeight);
			if (currHeight < prevHeight) {
				lowJump++;
			} else if (currHeight > prevHeight) {
				highJump++;
			}
			prevHeight = currHeight;
		}

		printf("Case %d: %d %d\n", t, highJump, lowJump);
	}
	return 0;
}
