#include <bits/stdc++.h>
#define tam 112345
using namespace std;
int v[tam], bin[tam];
char c[tam];
int main () {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", c);
        int n=strlen(c), resp=1, pot=2, marc=0;
        for(int i=0; i<n; i++) {
            bin[i]=c[i]=='1'? 1: 0;
        }
        for(;pot<=n-resp+1;resp++) {
            for(int i=0; i<tam; i++) {
                v[i]=0;
            }
            for(int i=0; i<n-resp+1; i++) {
                int aux=0;
                for(int j=0; j<resp; j++) {
                    aux*=2;
                    aux+=bin[i+j];
                }
                v[aux]++;
                //printf("aux=%d\n", aux);
            }
            for(int i=0; i<pot; i++) {
                if(v[i]==0) {
                    printf("%d\n", resp);
                    //printf("i=%d\n", i);
                    marc=1;
                    break;
                }
            }
            pot*=2;
            if(marc==1) break;
        }
        if(marc!=1) printf("%d\n", resp);
        marc=0;
        /*for(int i=0; i<pot; i++) {
            printf("v[%d]=%d\n", i, v[i]);
        }*/
    }
    return 0;
}
