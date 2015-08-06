#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int m, n, cotas[1000], da;
    while(scanf("%d %d", &n, &m)!=EOF){
        da = 1;
        for(int i = 0; i<n; i++){
            scanf("%d", &cotas[i]);
        }
        sort(cotas, cotas+n);
        if(m==0){
            printf("0\n");
            da = 0;
        }
        for(int j = 0; j<n&&da==1&&m>0; j++){
            m-=cotas[n-1-j];
            if(m<=0){
                printf("%d\n", j+1);
                da = 0;
            }
        }
        if(da==1)
            printf("NOOOO!\n");
    }
    return 0;
}
