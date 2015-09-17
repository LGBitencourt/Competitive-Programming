#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int mdp[100][100];
int ks[100];
int n,k;
int dp(int i,int d) {
    if(d < 0)return 0;
    if(i == n + 1) return d == 0;
    if(mdp[i][d] != -1) return mdp[i][d];
    if(ks[i]) return mdp[i][d] = dp(i + 1, d + 1);
    return mdp[i][d] = dp(i + 1, d + 1) + dp(i + 1, d - 1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(ks, 0, sizeof(ks));
        memset(mdp, -1, sizeof(mdp));
        cin >> n >> k;
        n<<=1;
        for(int i=1; i<= k; i++) {
            int temp;
            cin >> temp;
            ks[temp] = 1;            
        }
        cout << dp(1, 0) << endl;
    }
    return 0;
}

