#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int N,T1,T2,T3;
	int ans;
	while ( cin >> N >> T1 >> T2 >> T3 ) {
		if ( !N && !T1 && !T2 && !T3 ) break;
		ans = 3*N + N - 1;
		ans += T2 - T1;
		if ( T2 < T1 )
			ans += N;
		ans += T2 - T3;
		if ( T2 < T3 )
			ans += N;
		cout << ans << endl;
	}
	return 0;
}	
