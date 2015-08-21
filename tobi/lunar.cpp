#include <bits/stdc++.h>

int main(){
    int t = 1, n, m, v[10004];
    
    while(scanf("%d %d", &n, &m) && n != 0){
        int mini, maxi, sum = 0;
        
        printf("Teste %d\n", t++);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        for (int i = 0; i < m; i++)
            sum += v[i];

        int med;
        med = maxi = mini = sum / m;
        
        int j = 0;

        for(int i = m; i < n; i++){
            sum -= v[j++];
            sum += v[i];
            med = sum / m;
            if(med > maxi) maxi = med;
            if(med < mini) mini = med;  
        }
        
        printf("%d %d\n\n", mini, maxi);
    }
}
