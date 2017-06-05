#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int r;
    scanf(" %d", &r);
    while (r--) {
	int l;
	scanf(" %d", &l);
	bool ok = true;
	bool snake = false;
	for (int i = 0; i < l; i++) {
	    char c;
	    scanf(" %c", &c);
	    if (!ok) continue;
	    if (c == 'H') {
		if (snake)
		    ok = false;
		else
		    snake = true;
	    } else if (c == 'T') {
		if (snake)
		    snake = false;
		else
		    ok = false;
	    }
	}
	if (snake) ok = false;

	if (ok) printf("Valid\n");
	else printf("Invalid\n");
    }
} 
