#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, min, m, p;
    vector<int> v;

    scanf(" %d", &N);
    
    while (N) {
        int n = N, m = 0, p = 1;
        while (n) {
            if (n % 10) m += p;
            n /= 10, p *= 10;
        }
        v.push_back(m);
        N -= m;
    }

    printf("%d\n", v.size());
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) printf("%d ", *it);
    putchar('\n');

}
