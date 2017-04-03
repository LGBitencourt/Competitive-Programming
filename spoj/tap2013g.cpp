#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, j=0;
    cin >> n;
    vector <int> ini, eu;
    for(int i=0; i<n; i++) {
        int aux;
        scanf("%d", &aux);
        ini.push_back(aux);
    }
    sort(ini.begin(), ini.end());
    for(int i=0; i<n; i++) {
        int aux;
        scanf("%d", &aux);
        eu.push_back(aux);
    }
    sort(eu.begin(), eu.end());
    for(int i=0; i<n; i++) {
        while(eu[j]<=ini[i]) {
            j++;
            if(j>=n) {
                printf("%d\n", i);
                return 0;
            }
        }
        j++;
        if(j>=n){
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("%d\n", n);
    return 0;
}
