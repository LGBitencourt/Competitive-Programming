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

void swapsome(int vet[35], int n){
    if(n%2==0){
        f(n/2, i){
            swap(vet[i], vet[n-1-i]);
            vet[i] = -vet[i];
            vet[n-1-i] = -vet[n-1-i];
        }
    }
    else{
        f(n/2, i){
            swap(vet[i], vet[n-1-i]);
            vet[i] = -vet[i];
            vet[n-1-i] = -vet[n-1-i];
        }
        vet[n/2] = -vet[n/2];
    }
}

bool comp(int a, int b){
    return (a>b);
}

int main(){
    std::ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    f(t, x){
        int szs[35], ord[35], size, aux;
        queue<int> q;
        cin >> size;
        f(size, i){
            cin >> aux;
            ord[i] = aux;
            szs[i] = abs(aux);
        } 
        sort(szs, szs+size, comp);
        int tsize = size;
        f(tsize, i){
            aux = 0;
            while(szs[i] != abs(ord[aux])){
                aux++;
            }
            if(tsize-1-i == aux && ord[aux]>0){
                size--;
                continue;
            }
            if(aux>0){
                q.push(aux+1);
                swapsome(ord, aux+1);
            }
            if(ord[0]>0){
                q.push(1);
                ord[0] = -ord[0];
            }
            q.push(size);
            swapsome(ord, size);
            size--;
            /*
            int ok = 1;
            f(tsize-1, j){
                if(ord[j+1] != szs[j+1]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                if(szs[0] == abs(ord[0])){
                    break;
                }
            }
            */
        }
        if(ord[0]<0){
            q.push(1);
        }
        cout << x+1 << " " << q.size();
        while(q.size()!=0){
            cout << " " << q.front();
            q.pop();
        }
        cout << "\n";
    }
}
