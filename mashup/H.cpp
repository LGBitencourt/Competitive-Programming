
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;
int B;
vector<int> V;
bool p[10004];
unordered_map<long long,int> Us;

void sieve() {
    for (int i = 2; i < 10004; i++)
        p[i] = true;
    for (int i = 2; i < 10004; i++) {
        for (int j = i + i; j < 10004; j += i)
            p[j] = false;
    }
}

int dp( long long num )
{
    if( num == 1 )
        return 0;
    if( Us.find(num) == Us.end() ){
        int ans = 1 << 30;

        for( int i : V ) {
            if (i > num) break;
            if( num % i == 0 )
                ans = min( 1 + dp( num / i ) , ans );
        }
        return Us[num ] = ans;
    }
    return Us[num ] ;

}

int main() 
{
    long long n  ;

    cin >> B >> n;

    for( int i = 2 ; i < B ; ++i )
        if( n % i == 0 )
            V.push_back( i );

    int L = dp(n);

    if( L < 70 )
    {
        long long ans = 0 ;
        long long prod = 1;
        for( int i = 0 ; i < L ; ++i )
        {
            int j;
            for( j = B - 1 ; j > 1 ; --j )
                if( n %j == 0 and dp( n / j ) == L - i - 1 )
                    break;
            n/= j;
            ans += prod * j;
            prod *= B;
        }
        cout << ans << endl;
    }
    else 
        cout <<"impossible" <<endl;
    return 0;


}

