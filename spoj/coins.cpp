#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<long long int, long long int> mpd;

long long int pd(long long int n) {
    if (n == 0) return 0;
    if (mpd.find(n) != mpd.end()) return mpd[n];
    mpd[n] = max(n, pd(n/2) + pd(n/3) + pd(n/4));
    return mpd[n];
}

int main() {
    long long int n;
    while (scanf(" %lld", &n) != EOF)
        printf("%lld\n", pd(n));
}
