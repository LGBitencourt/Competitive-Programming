#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
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

int vpd[1130][20][1130], np;
vi prs;

int pd(int n, int k, int num){
    if(num == 0 && k==0) return 1;
    if(num < 0) return 0;
    if(n == np) return 0;
    if(k==0) return 0;
    if(vpd[n][k][num] != -1) return vpd[n][k][num];
    
    vpd[n][k][num] = pd(n+1, k-1, num-prs[n]) + pd(n+1, k, num);

    return vpd[n][k][num];
}

int main(){
    std::ios::sync_with_stdio(false);
    int paux[10151];
    ms(paux, 1);
    for(int i=2; i<=34; i++){
        if(paux[i]==0) continue;
        for(int j=i*i; j<=1120; j+=i){
            paux[j] = 0;
        }
    }
    for(int i=2; i<=1120; i++)
        if(paux[i])
            prs.pb(i);
    np = prs.size();
    int k, num;
    ms(vpd, -1);
    while(cin >> num >> k, num!=0){
        int ans = pd(0, k, num);
        cout << ans << "\n";
    }
}
