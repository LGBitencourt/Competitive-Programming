#include <bits/stdc++.h>
#define endl '\n'
#define fore(i,a,n) for(int i=a;i<n;i++)

using namespace std;
typedef long long ll;
ll x[1005],y[1005],z[1005];

set<pair<pair<ll,ll>,ll> > s;
int main () {
  ios::sync_with_stdio(false);
  ll a,b,c, n;
  cin >> a >> b >> c >> n;
  
  fore(i,0,n)
  	cin >> x[i] >> y[i] >> z[i];

	ll sur = (a*b+b*c+a*c)*2LL;
	ll sum = 0;
	fore(i,0,n) {
		bool arriba = 1,abajo = 1,adelante = 1,atras = 1,izq = 1,der = 1;
		ll tx = x[i],ty = y[i],tz = z[i];
		if(tx == 0)
			izq = 0;
		if(tx == a-1LL)
			der = 0;
		if(ty == 0)
			adelante = 0;
		if(ty == b-1LL)
			atras = 0;
		if(tz == 0)
			abajo = 0;
		if(tz == c-1LL)
			arriba = 0;
		
		fore(j,0,n) {
			if(j != i) {
				if(x[j] == tx-1LL)
					izq = 0;
				if(x[j] == tx+1LL)
					der = 0;
				if(y[j] == ty-1LL)
					adelante = 0;
				if(y[j] == ty+1LL)
					atras = 0;
				if(z[j] == tz-1LL)
					abajo = 0;
				if(z[j] == tz+1LL)
					arriba = 0;
			}
		}
		if(arriba && abajo)
			sum+=2LL;
		if(izq && der)
			sum+=2LL;
		if(adelante && atras)
			sum+=2LL;
	}
	fore(i,0,n) {
		ll cantx = 0,canty = 0, cantz = 0;
		ll tx = x[i],ty = y[i],tz = z[i];
		fore(j,0,n) {
			if(y[j] == ty && z[j] == tz)
				cantx++;
			if(x[j] == ty && z[j] == tz)
				canty++;
			if(y[j] == ty && x[j] == tx)
				cantz++;
		}
		if(cantx == a)
			s.insert(make_pair(make_pair(-1LL,ty),tz));
		if(canty == b)
			s.insert(make_pair(make_pair(tx,-1LL),tz));
		if(cantz == c)
			s.insert(make_pair(make_pair(tx,ty),-1LL));
	}
	
	ll si = s.size();
	for(set<pair<pair<ll,ll>,ll> >::iterator it = s.begin();it != s.end(); it++)
		cout << (*it).first.first << " " << (*it).first.second << " " << (*it).second << endl;
	sum-= 2LL * si;
	cout << sur+sum << endl;
}

