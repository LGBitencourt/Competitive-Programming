#include <cstdio>
#include <set>

using namespace std;

struct query {
    int id, time, ntime;
};

bool operator<(const query& a, const query& b) { 
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;
};

int main() {
    int k;
    char c;
    query q;
    set<query> sq;
    while (scanf(" Register %d %d", &q.id, &q.time)) {
        q.ntime = q.time;
        sq.insert(q);
    }

    scanf("%c %d", &c, &k);

    while (k--) {
        query nq = *(sq.begin());
        printf("%d\n", nq.id);
        nq.time += nq.ntime;
        sq.erase(sq.begin());
        sq.insert(nq);
    }

}
