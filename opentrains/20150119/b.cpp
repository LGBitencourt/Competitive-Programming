#include <bits/stdc++.h>
#define endl '\n'
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair
using namespace std;
typedef long long ll;
int x[3005],y[3005];
char d[3005];
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int m[300];
bool vis[3005];
vector<vector<int> > g;

int dfs(int u) {
	vis[u] = 1;
	int mx = 0;
	fore(i,0,g[u].size()) {
		int v = g[u][i];
		if(!vis[v])
			mx = max(mx,dfs(v));
	}
	return mx+1;
}

int main () {
  ios::sync_with_stdio(false);
  m['v'] = 1;
  m['^'] = 3;
  m['<'] = 2;
  m['>'] = 0;
  
  int n;
  cin >> n;
  
  g.resize(n);
  fore(i,0,n)
  	cin >> x[i] >> y[i] >> d[i];
  	
  fore(i,0,n) {
  	int tx = x[i], ty = y[i];
  	char c = d[i];
  	fore(j,0,n) {
  		if(i != j) {
  			if(c == 'v' && tx == x[j] && ty < y[j])
  				g[i].push_back(j);
  			if(c == '^' && tx == x[j] && ty > y[j])
  				g[i].push_back(j);
  			if(c == '<' && tx > x[j] && ty == y[j])
  				g[i].push_back(j);
  			if(c == '>' && tx < x[j] && ty == y[j])
  				g[i].push_back(j);
  		}
  	}
  }
  int mx = 0;
  fore(i,0,n) {
  	memset(vis,0,sizeof vis);
  	mx = max(mx,dfs(i));
  }
  cout << mx << endl;
  
}

