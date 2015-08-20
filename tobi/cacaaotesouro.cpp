#include <cstdio>
#include <algorithm>

using namespace std;

struct pista {
	int x, y, d;
}v[105];

int main() {
	int n, d;
	int t = 0;
	int xt, yt;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < d; i++) 
		scanf(" %d %d %d", &v[i].x, &v[i].y, &v[i].d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ok = 1;
			for (int k = 0; k < d && ok; k++) {
				if (abs(i - v[k].x) + abs(j - v[k].y) != v[k].d)
					ok = 0;
			}
			if (ok) {
				t++;
				if (t > 1) {
					printf("-1 -1\n");
					return 0;
				} else xt = i, yt = j;
			}
		}
	}
	printf("%d %d\n", xt, yt);
}
