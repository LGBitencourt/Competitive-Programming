#include <cstdio>
#include <iostream>
#include <algorithm>
#define all(x) x.begin(), x.end()

using namespace std;
typedef int num;

//REMEMBER TO DECLARE GLOBAL VARIABLES

int t, n, na, nb;
int ca[101], cb[101], sa[101], sb[101];

int hour(int *h, int *m, int d) {
    if (*m + d >= 60) {
        *h += 1;
        *m = (*m + d) - 60;
    } else {
        *m += d;
    }
}

int lb (int arr[101], int i, int e, int v) {
    int mid = (i + e)/2;
    if (i == e) return mid;
    if (arr[mid] >= v) return lb(arr, i, mid, v);
    return lb(arr, mid + 1, e, v);
}

int main(){
    scanf(" %d", &t);
    int aux, aux2;
    for(int ii=1; ii<=t; ii++){
        scanf(" %d %d %d", &n, &na, &nb);
        int A, B;
        A = na, B = nb;
        for(int i=0; i<na; i++){
            scanf("%d:%d", &aux, &aux2);
            hour(&aux, &aux2, 0);
            sa[i] = aux*100 + aux2;

            scanf("%d:%d", &aux, &aux2);
            hour(&aux, &aux2, n);
            cb[i] = aux*100 + aux2;
        }
        for(int i=0; i<nb; i++){
            scanf("%d:%d", &aux, &aux2);
            hour(&aux, &aux2, 0);
            sb[i] = aux*100 + aux2;

            scanf("%d:%d", &aux, &aux2);
            hour(&aux, &aux2, n);
            ca[i] = aux*100 + aux2;
        }
        sort(ca, ca+nb);
        sort(sa, sa+na);
        sort(cb, cb+na);
        sort(sb, sb+nb);
        
        for (int l = 0; l < nb; l++) {
            int k = 0;
            while (lower_bound(sa + k, sa + na, ca[l]) != (ca + nb)) A--;
        }
        cout << A << '\n';
    }
}
