#include <cstdio>

bool* visited;
int** adjList;
int* size;
int fallCount;

void dfs(int domino) {
	visited[domino] = true;
	for (int i = 0; i < size[domino]; i++) {
		int neighbor = adjList[domino][i];
		if (!visited[neighbor]) {
			fallCount++;
			dfs(neighbor);
		}
	}
}

int main() {
	int T, N, M, L;
	scanf("%d", &T);
	adjList = new int*[10005];
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &L);

		N++; // 1-indexed

		size = new int[10005];
		visited = new bool[N];
		fallCount = 0;

		for (int i = 0; i < N; i++) {
			adjList[i] = new int[10000];
		}

		for (int i = 0; i < M; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			adjList[x][size[x]++] = y;
		}

		for (int i = 0; i < L; i++) {
			int x;
			scanf("%d", &x);
			if (!visited[x]) {
				fallCount++;
				dfs(x);
			}
		}

		printf("%d\n", fallCount);
	}
	return 0;
}
