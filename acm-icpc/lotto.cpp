#include <iostream>
#include <cstring>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long long int vpd[15][2007];
long long int n, m;

long long int elev(long long int x, int k){
    if(k==1) return x;
    if(k%2==0) return elev(x*x, k/2);
    return x*elev(x, k-1);
}

long long int pd(long long int k, long long int num){
    if(num > m) return 0;
    if(k==n) return m-num+1;
    if(vpd[k][num] != -1) return vpd[k][num];

    long long int ans = 0;
    long long int aux = elev(2, n-k);
    aux = m/aux+1;
    for(int i=0; num+i<=aux; i++){
        ans += pd(k+1, (num+i)*2);
    }

    vpd[k][num] = ans;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long int t;
    cin >> t;
    f(t){
        cin >> n >> m;
        ms(vpd, -1);
        cout << "Data set " << i+1 << ": " << n << " " << m << " " << pd(1, 1) << "\n";
    }
}
