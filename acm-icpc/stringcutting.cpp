#include <cstdio>
#include <string>
#include <set>

using namespace std;

int main() {
    int t, c, k;

    char sc[10005];
    string s;

    scanf(" %d", &t);

    while (t--) {
        int l, cust = 0;
        set<int> set_cuts;
        set_cuts.insert(0);
        int cuts[1005];
        int acu[10005][26] = {0};

        scanf(" %d", &c);
        for (int i = 0; i < c; i++) scanf(" %d", &cuts[i]);
        scanf(" %s", &sc);
        s = sc;
        l = s.length();
        set_cuts.insert(l);

        for (int i = 1; i <= l; i++) {
            for (int j = 0; j < 26; j++) acu[i][j] = acu[i-1][j];
            acu[i][sc[i-1]-'a']++;
        }

        for (int i = 0; i < c; i++) {
            set<int>::iterator it = set_cuts.insert(cuts[i]).first;
            set<int>::iterator u = ++it;
            --it;
            set<int>::iterator l = --it;
            ++it;

            for (int j = 0; j < 26; j++) {
                int a = acu[*it][j] - acu[*l][j], b = acu[*u][j] - acu[*it][j];
                if ((!a && b) || (!b && a)) cust++;
            }
        }

        printf("%d\n", cust);

    }

}
