#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[2],b[2],c[2],d[2];
    int ans = 0;
    bool flag = 0;
    while ( scanf("%d %d %d %d", &a[0], &b[0], &c[0], &d[0]) != EOF ) {
        flag = 0;
        ans = 0;
        if ( !a[0] && !b[0] && !c[0] && !d[0] )
            break;
        while (1) {
            if ( a[flag] == b[flag] && b[flag] == c[flag] && c[flag] == d[flag]  ) {
                break;
            }
            ans++;
            flag = !flag;
            int i = !flag;
            a[flag] = abs(abs(a[i]-b[i]));
            b[flag] = abs(abs(b[i]-c[i]));
            c[flag] = abs(abs(c[i]-d[i]));
            d[flag] = abs(abs(d[i]-a[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
