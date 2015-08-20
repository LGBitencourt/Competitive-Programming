#include <cstdio>

int n, p, t, f;
int main() {
	scanf(" %d", &n);
	while (n--) {
		scanf(" %d", &p);
		if (p >= t) t = p + 10, f += 10;
		else if (p < t) f += (p + 10 - t), t = p + 10;
	}
	printf("%d\n", f);
}
