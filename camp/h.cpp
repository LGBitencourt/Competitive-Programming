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
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int MAX = 212345;
const int modn = 1000000007;

int n;
char s[MAX];
int qtdH, qtdM;
int neg[2][MAX];
int bin[2][MAX], pos[2];

void calc (int num, int t) {
    pos[t] = n;
    while (num > 0) {
        bin[t][pos[t]++] = num % 2;
        num /= 2;
    }
}

void inv (int t) {
    for (int i = 0; i < pos[t]; i++) {
        if (neg[t][i] == 1) {
            neg[t][i] = 0;
        } else {
            neg[t][i] = 1;
        }
    } 
    int carry = 1;
    for (int i = 0; carry && i < pos[t]; i++) {
        if (neg[t][i] == 1) {
            neg[t][i] = 0;
            carry = 1;
        } else if (neg[t][i] == 0) {
            neg[t][i] = 1;
            carry = 0;
        }
    }
}

void sub (int t) {
    int carry = 0;
    for (int i = 0; i < pos[t]; i++) {
        int sum = bin[t][i]+neg[t][i]+carry;
        if (sum < 2) {
            carry = 0;
            bin[t][i] = sum;
        } else if (sum == 2) {
            bin[t][i] = 0;
            carry = 1;
        } else {
            bin[t][i] = 1;
            carry = 1;
        }
    }
}

int main() {
    scanf ("%d %s", &n, s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'H') {
            qtdH++, neg[0][i+1]++;
        } else {
            qtdM++, neg[1][i+1]++;
        }
    }
    calc (qtdH, 0);
    /*for (int i = 0; i <= n; i++) 
        printf ("%d ", neg[0][i]);
    printf ("\n");*/
    inv (0);
    /*for (int i = 0; i < pos[0]; i++) 
        printf ("%d ", bin[0][i]);
    printf ("\n");*/
    /*for (int i = 0; i <= n; i++)
        printf ("%d ", neg[0][i]);
    printf ("\n");*/
    sub (0);
    calc (qtdM, 1);
    inv (1);
    sub (1);
    int p = max (pos[0], pos[1]);
    int win = 0;
    for (int i = p-1; win == 0 && i >= 0; i--) {
        if (bin[0][i] > bin[1][i]) 
            win = 1;
        else if (bin[0][i] < bin[1][i])
            win = 2;
    }
    if (win == 0) {
        printf ("HM\n");
    } else if (win == 1) {
        printf ("H\n");
    } else {
        printf ("M\n");
    }
}

