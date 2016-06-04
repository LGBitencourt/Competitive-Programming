#include <bits/stdc++.h>
#define u first
#define l second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, room;
pii t[MAX];

int main () {
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &t[i].l, &t[i].u);
        }
        sort (t, t+n);
        int fim = t[0].u, room = 1;
        for (int i = 0; i < n; i++) {
            if (t[i].l > fim) {
                room++;
                fim = t[i].u;
            }
        }
        printf ("%d\n", room);
    }
}
