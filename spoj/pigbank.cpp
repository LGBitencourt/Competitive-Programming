#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct coin {
	int p, w;
} coins[505];

int E, F, N;

int mpd[505][50005];

int pd (int i, int W) {
	if (W == 0) return 0;
	if (i == N) return 1234560;
	if (mpd[i][W] != -1) return mpd[i][W];
	int a1, a2;
	a1 = INT_MAX;
	if (coins[i].w <= W)
		a1 = coins[i].p + pd(i, W - coins[i].w);
	a2 = pd (i + 1, W);
	mpd[i][W] = min(a1, a2);
	return mpd[i][W];
}

int main() {
	int t;
	scanf(" %d", &t);
	while (t--) {
		for (int i = 0; i < 505; i++)
			for (int j = 0; j < 50005; j++)
				mpd[i][j] = -1;
		scanf(" %d %d %d", &E, &F, &N);
		for (int i = 0; i < N; i++)
			scanf(" %d %d", &coins[i].p, &coins[i].w);
		int ans = pd(0, F - E);
		if (ans != 1234560)
			printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
		else printf("This is impossible.\n");
	}
}
