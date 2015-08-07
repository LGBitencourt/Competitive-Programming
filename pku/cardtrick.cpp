#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;
int ans[20];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, cont=0, which=1, aux;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            q.push(i);
        }
        while(!q.empty()){
            if(cont < which){
                cont++;
                aux = q.front();
                q.pop();
                q.push(aux);
            }
            else{
                ans[q.front()] = which;
                which++;
                cont = 0;
                q.pop();
            }
        }
        printf("%d", ans[0]);
        for(int i=1; i<n; i++){
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
}
