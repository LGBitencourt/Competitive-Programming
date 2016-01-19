#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main () {
    int n, k, x, y, l, h, m;
    ios::sync_with_stdio(false);
    l = 0; h = 1000000000;
    while (h-l>1) {
        m = ((l + h)+1)/2;
        cout << m << " " << 0 << endl;
        cout.flush();
        cin >> n;
        cout << m-1 << " " << 0 << endl;
        cout.flush();
        cin >> k;
        if (n && k) h = m;
        else if (n && !k) l = m;
        else if (!n && k) h = m;
        else l = m;
    }
    cout << h << " " << 0 << endl;
    cout.flush();
    cin >> n;
    cout << l << " " << 0 << endl;
    cout.flush();
    cin >> k;
    if(k)
    	x = l;
    else
    	x = h;

    l = 0, h = 1000000005;
    while (h - l > 1) {
        m = ((l + h)+1)/2;
        cout << x << " " << m << endl;
        cout.flush();
        cin >> n;
        cout << x << " " << m-1 << endl;
        cout.flush();
        cin >> k;
        if (n && k) h = m;
        else if (n && !k) l = m;
        else if (!n && k) h = m;
        else l = m;
    }
    cout << x << " " << h << endl;
    cout.flush();
    cin >> n;
    cout << x << " " << l << endl;
    cout.flush();
    cin >> k;
    if(k)
    	y = l;
    else
    	y = h;
    cout << "A " << x << " " << y << endl;
    cout.flush();
}

