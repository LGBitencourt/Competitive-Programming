#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

bool p[MAX];
char str[5];
vector<int> adj[10000];
queue<int> q;
int d[10000];

void crivo() {
    for (int i = 2; i < MAX; i++) p[i] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX; j += i)
            p[j] = false;
    }
}

void gen_path (int k) {
    char s[5];
    for (int i = 0; i < 4; i++) {
        strncpy(s, str, 5);
        for (int j = 0; j <= 9; j++) {
            if (str[i] - '0' == j || (i == 0 && j == 0)) continue;
            s[i] = j + '0';
            int x = atoi (s);
            if (p[x])
                adj[k].push_back(x), adj[x].push_back(k);
        }
    }
}

void bfs () {
    while (!q.empty()) {
        int f = q.front ();
        q.pop();
        for (int i = 0; i < adj[f].size(); i++) {
            int n = adj[f][i];
            if (d[n] > d[f] + 1) {
                d[n] = d[f] + 1;
                q.push(n);
            }
        }
    }
}

int main () {
    int t;

    crivo ();
    for (int i = 1000; i < 10000; i++)
        if (p[i]) {
            sprintf (str, "%d", i);
            gen_path (i);
        }
    scanf (" %d", &t);

    while (t--) {
        int x, y;
        for (int i = 1000; i < 10000; i++) d[i] = INT_MAX;
        scanf (" %d %d", &x, &y);
        q.push(x);
        d[x] = 0;
        bfs ();
        if (d[y] == INT_MAX)
            printf ("Impossible\n");
        else printf ("%d\n", d[y]);
    }
}

