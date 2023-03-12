#include <cstdio>

bool** hasWater;
int even;
int odd;
bool** visited;
int* dx;
int* dy;
int R, C, M, N;

void dfs(int x, int y);

void visit(int x, int y, int dx, int dy, int &reach) {
	int nx = x + dx;
	int ny = y + dy;
	if (nx >= 0 && ny >= 0 && nx < R && ny < C && !hasWater[nx][ny]) {
		if (!visited[nx][ny]) {
			dfs(nx, ny);
		}
		reach++;
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;
	int reach = 0;

	if (M == N) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				visit(x, y, dx[i], dy[j], reach);
			}
		}
	} else if (M == 0 || N == 0) {
		int* d = M > 0 ? dx : dy;
		for (int i = 0; i < 2; i++) {
			visit(x, y, d[i], 0, reach);
		}
		for (int i = 0; i < 2; i++) {
			visit(x, y, 0, d[i], reach);
		}
	} else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				visit(x, y, dx[i], dy[j], reach);
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				visit(x, y, dy[j], dx[i], reach);
			}
		}

	}

	if (reach & 1) {
		odd++;
	} else {
		even++;
	}
}

int main() {
	int T, W;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &R, &C, &M, &N);
		hasWater = new bool*[R];
		visited = new bool*[R];
		even = 0;
		odd = 0;
		dx = new int[2];
		dy = new int[2];
		dx[0] = M;
		dx[1] = M * -1;
		dy[0] = N;
		dy[1] = N * -1;

		for (int i = 0; i < R; i++) {
			hasWater[i] = new bool[C];
			visited[i] = new bool[C];
		}

		scanf("%d", &W);
		for (int i = 0; i < W; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			hasWater[x][y] = true;
		}

		dfs(0, 0);

		printf("Case %d: %d %d\n", t, even, odd);
	}

	return 0;
}
