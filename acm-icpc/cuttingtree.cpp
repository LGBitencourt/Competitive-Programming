#include <cstdio>
#include <vector>
#include <stack>
#define MAXN 20005

using namespace std;

int height[MAXN];
int pai[MAXN];
vector<int> children[MAXN];
stack<int> s;

int query(int a, int b) {
   bool mudou = 1;

    while (height[a] != height[b]) {
        mudou = 0;

        if (height[a] > height[b] && pai[a] != 0) {
            a = pai[a];
            mudou = 1;
        } else if (height[b] > height[a] && pai[b] != 0) {
            mudou = 1;
            b = pai[b];

        }

        if (!mudou) break;
    }

    while(height[a] == height[b] && a != b && pai[b] != 0 && pai[a] != 0) {
        a = pai[a];
        b = pai[b];
    }

    return a == b;
}

void dfs(int cur, int h) {
    height[cur] = h;

    for (int x = 0; x < children[cur].size(); x++)
        dfs(children[cur][x], h+1);
}

int main() {
    int t, at, x, y, n, m, cur;
    char c;

    scanf("%d", &t);

    at = 1;

    while(t--) {
        scanf("%d %d", &n, &m);

        for (x = 1; x <= n; x++) {
            height[x] = 0;
            pai[x] = x;
            children[x].clear();
        }

        for (x = 1; x <= n; x++) {
            scanf("%d", &pai[x]);

            if (pai[x] == 0)
                s.push(x);
            else
                children[pai[x]].push_back(x);
        }


        while(!s.empty()) {
            cur = s.top();
            s.pop();

            dfs(cur, 1);
        }

        printf("Case #%d:\n", at++);

        while(m--) {
            scanf(" %c", &c);

            if (c == 'Q') {
                scanf("%d %d", &x, &y);

                //for (int z = 1; z <= n; z++)
                //    printf("%d ", pai[z]);

               // printf("\n");

                //for (int z = 1; z <= n; z++)
                 //   printf("%d ", height[z]);

               // printf("\n");

                if (query(x, y)) printf("YES\n");
                else printf("NO\n");

            } else {
                scanf("%d", &x);

                pai[x] = 0;
            }
        }
    }

    return 0;
}
