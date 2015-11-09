#include <cstdio>
#include <cstring>

using namespace std;

int a, b, x;
char str[10];
int d[10], ds[10];
int mdp[10][270][2][2];

int dp (int i, int sum, bool pre, bool f) {
    if (str[i] == 0) return sum;
    int &m = mdp[i][sum][pre][f];
    if (m != -1) return m;
    int ans = 0;
    for (int j = 0; j <= 9; j++) {
        if (pre && j > str[i] - '0') break;
        if (j != 0) f = true;
        ans += dp (i + 1, sum + (j == x && f), pre && (j == str[i] - '0'), f);
    }
    return m = ans;
}

int main () {
    while (scanf (" %d %d", &a, &b), a != 0) {

        sprintf (str, "%d", b);
        for (int i = 0; i <= 9; i++) {
            memset (mdp, -1, sizeof mdp);
            x = i, d[i] = dp (0, 0, true, false);
        }

        sprintf (str, "%d", a-1);
        for (int i = 0; i <= 9; i++) {
            memset (mdp, -1, sizeof mdp);
            x = i, ds[i] = dp (0, 0, true, false);
        }

        printf ("%d", d[0]-ds[0]);
        for (int i = 1; i <= 9; i++)
            printf (" %d", d[i] - ds[i]);
        putchar ('\n');
    }
}
