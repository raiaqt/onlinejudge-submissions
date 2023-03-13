// 12442

#include <cstdio>

int* martians;
int* recipient;
bool* visited;
bool* hasSender;
int* start;
int* id;
int* low;
int count;

void dfs(int m, int s) {
	if (visited[m]) {
		return;
	}
	visited[m] = true;
	start[m] = s;
	id[m] = count++;
	low[m] = id[m];

	if (recipient[m] == 0) {
		martians[m] = 0;
		return;
	}

	int n = recipient[m];
	if (!visited[n]) {
		dfs(recipient[m], s);
		if (low[m] >= low[n]) {
			martians[m] = martians[n];
			low[m] = low[n];
		} else {
			martians[m] = martians[n] + 1;
		}
	} else if (start[m] == start[n]) {	    // visited and on the same dfs
		low[m] = low[n] < low[m] ? low[n] : low[m];
		martians[m] = id[m] - low[n] + 1;
	} else {
		martians[m] = martians[n] + 1;      // visited before, use the recorded value
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		N++; 								// 1-indexed;
		martians = new int[N]; 				// number of Martians who receive from i
		recipient = new int[N];
		visited = new bool[N];
		hasSender = new bool[N];
		start = new int[N];
		id = new int[N];
		low = new int[N];
		count = 0;
		int u, v; 							// Martian u sends to Martian v
		int max = 0;
		int maxMartian = 0;

		for (int i = 1; i < N; i++) {
			martians[i] = 0;
		}

		for (int i = 1; i < N; i++) {
			scanf("%d %d", &u, &v);
			recipient[u] = v;
			hasSender[v] = true;
		}

		for (int i = 1; i < N; i++) {
			dfs(i, i);
			if (martians[i] > max) {
				max = martians[i];
				maxMartian = i;
			}
		}

		printf("Case %d: %d\n", t, maxMartian);
	}
	return 0;
}
