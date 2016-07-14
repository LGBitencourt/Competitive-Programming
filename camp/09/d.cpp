#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 8;
const int modn = 1000000007;

char s[2][3];
char d[2][3];
pii ini[2];
pii fim[2];
int dist[MAXN+10][MAXN+10][MAXN+10][MAXN+10];
ppii parent[MAXN+10][MAXN+10][MAXN+10][MAXN+10];


int dx[] = {2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,1,-1,2,2,-2,-2};

bool can( int x, int y )
{
    if ( x < 0 || y < 0 || x >= MAXN || y >= MAXN )
        return false;
    return true;
}

bool diff( int x0, int y0, int x1, int y1 )
{
    if ( x0 == x1 && y0 == y1 )
        return false;
    return true;
}

void bfs()
{
    for ( int i = 0; i < MAXN; i++ )
        for ( int j = 0; j < MAXN; j++ ) 
            for ( int k = 0; k < MAXN; k++ )
                for ( int t = 0; t < MAXN; t++ ) {
                    dist[i][j][k][t] = inf;
                    parent[i][j][k][t] = ppii(pii(-1,-1),pii(-1,-1));
                }
    queue<ppii> Q;
    int l0 = ini[0].first, l1 = ini[1].first, c0 = ini[0].second, c1 = ini[1].second;
    Q.push(ppii(pii(l0,c0),pii(l1,c1)));
    dist[l0][c0][l1][c1] = 0;
    parent[l0][c0][l1][c1] = ppii(pii(l0,c0),pii(l1,c1));
    while ( !Q.empty() ) {
        ppii atual = Q.front(); Q.pop();
        //printf("%d %d %d %d\n", atual.ff.ff, atual.ff.ss, atual.ss.ff, atual.ss.ss);
        int l0 = atual.first.first, l1 = atual.second.first, c0 = atual.first.second, c1 = atual.second.second;
        //printf("%d\n", dist[l0][c0][l1][c1]);
        for ( int i = 0; i < 8; i++ ) {
            int l = l0 + dx[i], c = c0 + dy[i];
            if ( can(l,c) && diff(l,c,l1,c1) && dist[l][c][l1][c1] > dist[l0][c0][l1][c1] + 1 ) {
                Q.push(ppii(pii(l,c),pii(l1,c1)));
                parent[l][c][l1][c1] = ppii(pii(l0,c0),pii(l1,c1));
                dist[l][c][l1][c1] = dist[l0][c0][l1][c1] + 1;
               /*if ( pii(l,c) == fim[0] && pii(l1,c1) == fim[1] ) {
                    break;
                }*/
            }            
        }
        for ( int i = 0; i < 8; i++ ) {
            int l = l1 + dx[i], c = c1 + dy[i];
            if ( can(l,c) && diff(l0,c0,l,c) && dist[l0][c0][l][c] > dist[l0][c0][l1][c1] + 1 ) {
                Q.push(ppii(pii(l0,c0),pii(l,c)));
                dist[l0][c0][l][c] = dist[l0][c0][l1][c1] + 1;
                parent[l0][c0][l][c] = ppii(pii(l0,c0),pii(l1,c1));
               /* if ( pii(l0,c0) == fim[0] && pii(l,c) == fim[1] ) {
                    break;
                }*/
            }
        }            
    }
}

void caminho( int x0, int y0, int x1, int y1 )
{
    ppii atual = parent[x0][y0][x1][y1];
    if ( atual == ppii(pii(x0,y0),pii(x1,y1)) ) { 
        return;
    }
    caminho(atual.ff.ff,atual.ff.ss,atual.ss.ff,atual.ss.ss);
    if ( atual.ff.ff == x0 && atual.ff.ss == y0 ) {
        printf("B %c%d\n", x1+'a',y1+1); 
    }
    else {
        printf("W %c%d\n", x0+'a',y0+1);
    }
}

int main() 
{
    scanf(" %s %s", s[0], s[1]);
    scanf(" %s %s", d[0], d[1]);
    ini[0] = pii(s[0][0]-'a',s[0][1]-'1');
    ini[1] = pii(s[1][0]-'a',s[1][1]-'1');
    fim[0] = pii(d[0][0]-'a',d[0][1]-'1');
    fim[1] = pii(d[1][0]-'a',d[1][1]-'1');
    bfs();
    int l0,l1,c0,c1;
    l0 = fim[0].first; l1 = fim[1].first; c0 = fim[0].second; c1 = fim[1].second;
    printf("%d\n", dist[l0][c0][l1][c1]);
    caminho(l0,c0,l1,c1);
    return 0;
}

