#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int r, e, c, aux;
        scanf("%d%d%d", &r, &e, &c);
        aux = e-r;
        if(aux>c) printf("advertise\n");
        else if(aux==c) printf("does not matter\n");
        else printf("do not advertise\n");
    }
}
