#include <iostream>
#include <algorithm>
#include <vector>
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

vi va(101), vb(101);
int a, b, c, d;

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> a >> d, a!=0 && d!=0){
        f(a){
            cin >> b;
            va[i] = b;
        }
        f(d){
            cin >> c;
            vb[i] = c;
        }
        sort(va.begin(), va.begin()+a);
        sort(vb.begin(), vb.begin()+d);

        b = *(va.begin());
        vit it = vb.begin();
        if(b == *it && b == *(it+1)){
            cout << "N\n";
        }
        else if(b > *it && b >= *(it+1)){
            cout << "N\n";
        }
        else{
            cout << "Y\n";
        }
    }

}
