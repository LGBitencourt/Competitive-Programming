#include <cstdio>
#include <queue>

using namespace std;

struct telefonista {
    int id;
    int time = 0;
    int total = 0;

    bool operator < (const telefonista &e) const {
        if (time != e.time) return time > e.time;
        return id > e.id;
    }

};

priority_queue<telefonista> pq;

int main() {
    int n, l;
    telefonista t[1005];
    telefonista k;
    scanf("%d %d", &n, &l);

    for (int i = 1; i <= n; i++) {
        t[i].id = i;
        pq.push(t[i]);
    }

    for (int i = 1; i <= l; i++) {
        int c;
        k = pq.top(), pq.pop();
        scanf(" %d", &c);
        k.time += c, k.total++;
        pq.push(k);
        t[k.id] = k;
    }

    for (int i = 1; i <= n; i++) printf("%d %d\n", t[i].id, t[i].total);

}
