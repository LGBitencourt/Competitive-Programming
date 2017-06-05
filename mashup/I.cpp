#include <bits/stdc++.h>


using namespace std;

const int MAXN = 112345;

int primos[112345];
vector <int> primo; 

void crivo () {

    for (int i = 2; i <= MAXN; i++)
        primos[i] = i;
    for (int i = 2; i <= MAXN; i++) {
        if (primos[i] == i) {
            for (int j = i+i; j <= MAXN; j += i) 
                primos[j] = i;
                    
        primo.push_back (i);     
       }
    }
}


int main () {
    int q;
    bool flag = true;
    scanf ("%d", &q);
    
    if (q == 1) {
        printf ("no\n");
        return 0;
    }
    crivo ();
    for (int p : primo) {
        int w = q;
        while (w % p == 0 && w > 1) {
            w /= p;
        }
        if (w == 1) {
            printf ("yes\n");
            return 0;
        }
    }
    for (int p : primo) {
        if (q % p == 0)
            flag = false;
    }
    if (flag) 
        printf ("yes\n");
    else
        printf ("no\n");
    return 0;
}
