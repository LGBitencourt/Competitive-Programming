#include <bits/stdc++.h>
#define tam 1123456
#define div agshdhj
using namespace std;
int d [30][tam];
int dp[tam], p;
set <int> div[tam];
int main () {
    for(int i=2; i<tam; i++) {
        if(div[i].empty()) {
            for(int j=2*i; j<tam; j+=i) {
                div[j].insert(i);
            }
        }
    }
    for(int i=0; i<tam; i++) {
        if(!div[i].empty()) {
            int ant=0;
            for(int x: div[i]) {
                ant+=x;
            }
            dp[i]=dp[ant]+1;
            d[dp[i]][i]=1;
        }
        else {
        dp[i]=1;
        d[1][i]=1;
        }
    }
    /*for(int i=0; i<100; i++) {
        printf("i = %d d[i] = %d\n", i, dp[i]); 
    }*/
    for(int i=0; i<30; i++) {
        for(int j=1; j<tam; j++) {
            d[i][j]=d[i][j-1]+d[i][j];
        }
    }
    /*for(int i=0; i<100; i++) {
        printf("i = %d d[i] = %d\n", i, d[3][i]); 
    }*/
    cin >> p;
    for(int i=0; i<p; i++) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        if(k<30)printf("%d\n", d[k][b]-d[k][a-1]);
        else printf("0\n");
    }
    return 0;
}
