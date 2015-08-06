#include <cstdio>
#include <algorithm>

using namespace std;

struct event {
    int time, arrive, station;
};

bool compare(event a, event b) { 
    if (a.time != b.time) return a.time < b.time;
    return a.arrive > b.arrive;
}

int main() {
    int n, na, nb, A, B, t, ta, tb;
    struct event events[405];
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        A = B = ta = tb = 0;
        scanf("%d %d %d", &t, &na, &nb);
        int h, m, e = 0;
        while (na--) {
            scanf(" %d:%d", &h, &m);
            events[e].time = 60*h + m;
            events[e].arrive = 0;
            events[e].station = 1;
            e++;
            scanf(" %d:%d", &h, &m);
            events[e].time = 60*h + m + t;
            events[e].arrive = 1;
            events[e].station = 0;
            e++;
        }
        while (nb--) {
            scanf(" %d:%d", &h, &m);
            events[e].time = 60*h + m;
            events[e].arrive = 0;
            events[e].station = 0;
            e++;
            scanf(" %d:%d", &h, &m);
            events[e].time = 60*h + m + t;
            events[e].arrive = 1;
            events[e].station = 1;
            e++;
        }

        sort(events, events + e, compare);

        for (int j = 0; j < e; j++) {
            if (events[j].arrive) {
                if (events[j].station) ta++;
                else tb++;
            } else {
                if (events[j].station) {
                    if (ta) ta--;
                    else A++;
                } else {
                    if (tb) tb--;
                    else B++;
                }
            }
        }
        printf("Case #%d: %d %d\n", i, A, B);
    }
}
