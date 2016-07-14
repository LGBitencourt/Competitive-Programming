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
const int MAXN = 20000;
const int modn = 1000000007;

int ans[MAXN];
int st[MAXN];
int top = 0;
bool marked[MAXN];
char candidate[MAXN];
char in[MAXN];

int main() {
    scanf (" %s", in);
    int len = strlen(in);
    int size = len;

    for (int i = 0; i < len; i++) {
        if (in[i] == '[' || in[i] == ']') continue;
        if (in[i] == '(') st[top++] = i;
        else if (in[i] == ')' && top == 0) st[top++] = i;
        else if (in[i] == ')' && in[st[top-1]] == '(') marked[i] = marked[st[--top]] = true;
        else st[top++] = i;
    }
    for (int s = 0; s < len; s++) {
        int q_a = 0;
        int q_f = 0;
        int total = 0;
        if (marked[s]) continue;
        if (in[s] == '(') q_a++;
        else if (in[s] == ')') q_f++;
        else if (in[s] == '[') {
            for (int i = s+1; i < len; i++) {
                if (marked[i]) continue;
                if (in[i] == '(') q_a++;
                else if (in[i] == ')') {
                    if (q_a == 0) total++;
                    else q_a--;
                } else if (in[i] == '[') break;
            }
            ans[s] = total;
            size += total;
            size--;
        } else if (in[s] == ']') {
            for (int i = s-1; i >= 0; i--) {
                if (marked[i]) continue;
                if (in[i] == ')') q_f++;
                else if (in[i] == '(') {
                    if (q_f == 0) total++;
                    else q_f--;
                } else if (in[i] == ']') break;
            }
            ans[s] = total;
            size += total;
            size--;
        }
    }

    int i = 0, j = 0;
    while (i < size) {
        if (in[j] == '[')
            for (int k = 0; k < ans[j]; k++)
                candidate[i++] = '(';
        else if (in[j] == ']')
            for (int k = 0; k < ans[j]; k++)
                candidate[i++] = ')';
        else candidate[i++] = in[j];
        j++;
    }
    candidate[size] = 0;
    bool valid = true;
    stack<char> q;
    for (int i = 0; i < size && valid; i++) {
        if (candidate[i] == '(') q.push('(');
        else if (candidate[i] == ')' && q.empty()) valid = false;
        else if (candidate[i] == ')' && q.top() == '(') q.pop();
        else valid = false;
    }
    if (valid && q.empty()) printf("%s\n", candidate);
    else printf("Impossible\n");
}

