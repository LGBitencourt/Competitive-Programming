#include <bits/stdc++.h>
#define endl '\n'
#define fore(i,a,n) for(int i=a;i<n;i++)

using namespace std;

char a[105][10005];
int cant[10005][2];
int main () {
    ios::sync_with_stdio(false);
    int n,m;
    scanf("%d %d",&n,&m);

    fore(i,0,m)
    	scanf("%s",a[i]);

    fore(i,0,m) {
    	fore(j,0,n) {
		  	cant[j][0] += a[i][j] == 'W';
		  	cant[j][1] += a[i][j] == 'E';
		  }
    }
    fore(i,1,n) {
		  	cant[i][0] += cant[i-1][0];
		  	cant[i][1] += cant[i-1][1];
    }
    //fore(i,0,n-1)
    	//printf("%d : %d %d\n",i,cant[i][0], cant[i][1]);
    int mn = 1e9;
    mn = min(mn,cant[n-1][0]);
    //cout << mn << endl;
    mn = min(mn,cant[n-1][1]);
    //cout << mn << endl;
    fore(i,0,n-1) {
    	mn = min(mn,cant[i][1] + cant[n-1][0] - cant[i][0]);
    }
    if(mn == cant[n-1][0])
    	printf("0 1\n");
    else {
    	bool flag = 1;
    	fore(i,0,n-1) {
    		if(mn == cant[i][1] + cant[n-1][0] - cant[i][0]) {
    			printf("%d %d\n",i+1,i+2);
    			flag = 0;
    			break;
    		}
    	}
    	if(flag && mn == cant[n-1][1])
    		printf("%d %d\n",n,n+1);
    }

}

