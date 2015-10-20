#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int K, W;
int pai[100005], sz[100005], degree[100005];

struct Wi { int u, v; } w[100005];

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find(pai[v]);
}

bool join (int a, int b) {
    if (find(a) != find(b)) {
        pai[find(a)] = find(b);
        return true;
    }
    return false;
}

int main () {
    while (scanf (" %d %d", &K, &W), K != 0) {
        map<int, int> m;
        int n = 0;
        for (int i = 0; i <= W; i++)
            pai[i] = -1, sz[i] = 1;
        for (int i = 0; i < W; i++) {
            int u, v;
            scanf (" %d %d", &u, &v);

            map<int, int>::iterator it;
            it = m.find(u);
            if (it == m.end())
                m.insert(make_pair(u, n)), u = n++;
            else u = it->second;

            it = m.find(v);
            if (it == m.end())
                m.insert(make_pair(v, n)), v = n++;
            else v = it->second;

            w[i].u = u, w[i].v = v;
        }
        int i, f = 0;
        for (i = 0; i < W && !f; i++) {
            if (!join (w[i].u, w[i].v)) printf ("%d %d\n",w[i].u, w[i].v), f = 1;
            else degree[w[i].u]++, degree[w[i].v]++;
        }
        degree[w[i].u]++, degree[w[i].v]++;
    }
}
