#include <cstdio>
#include <algorithm>

using namespace std;

struct call {
    int start, end;
} calls[10005];

bool compare (call a, call b) { return a.end < b.end; }

int main() {
    int n, m, trash, s, d;
    
    while (scanf(" %d %d", &n, &m), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf(" %d %d %d %d", &trash, &trash, &s, &d);
            calls[i].start = s, calls[i].end = (s + d);
        }
        sort(calls, calls + n, compare);
        for (int i = 0; i < m; i++) {
            int c = 0;
            scanf(" %d %d", &s, &d);
            for (int j = 0; j < n; j++) {
                /*if ((calls[j].start <= s && calls[j].end <= s) || (calls[j].start >= (s + d))) continue;*/
                if ((s + d) > calls[j].start && s < calls[j].end)
                    c++;
            }
            printf("%d\n", c);
        }
    }
}
