#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[200005][2];
int v[200005];
int n, c;

int main(){
    while(scanf("%d %d",&n,&c) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d",v+i);
        memo[n][0] = memo[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            memo[i][0] = max(memo[i+1][0], memo[i+1][1] - c - v[i]);
            memo[i][1] = max(memo[i+1][1], memo[i+1][0] + v[i]);
        }
        printf("%d\n", memo[0][0]);
    }
}
