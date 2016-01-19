#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main () {
    int n, k, x, y, l, h, m;
    ios::sync_with_stdio(false);
    l = 0; h = 1000000005;
    while (l != h) {
        m = (l + h)/2;
        cout << m << " " << 0 << endl;
        cout.flush();
        cin >> n;
        /*if (!n && !k) h = m;
        else if ((k && !n) || (!k && n)) {
            cout << m + 1 << " " << 0 << endl;
            cout.flush();
            cin >> n;
            if (n) l = m + 1;
            else {
                cout << m - 1 << " " << 0 << endl;
                cout.flush();
                cin >> n;
                if (n) h = m;
                else l = m;
            }
        } else {
            cout << m - 1 << " " << 0 << endl;
            cout.flush();
            cin >> n;
            if (!n) l = m;
            else h = m - 1;
        }
        k = n;*/
        cout << m-1 << " " << 0 << endl;
        cout.flush();
        cin >> k;
        if (n && k) h = m - 1;
        else if (n && !k) l = m;
        else if (!n && k) h = m - 1;
        else l = m;
    }
    x = l, l = 0, h = 1000000005;
    /*while (l != h) {
        m = (l + h)/2;
        cout << x << " " << m << endl;
        cout.flush();
        cin >> n;
        if (!n && !k) h = m;
        else if ((k && !n) || (!k && n)) {
            cout << x << " " << m + 1 << endl;
            cout.flush();
            cin >> n;
            if (n) l = m + 1;
            else {
                cout << x << " " << m-1 << endl;
                cout.flush();
                cin >> n;
                if (n) h = m - 1;
                else l = m;
            }
        } else {
            cout << x << " " << m-1 << endl;
            cout.flush();
            cin >> n;
            if (!n) l = m;
            else h = m - 1;
        }
        k = n;
    }
    y = l;*/
    cout << "A " << x << " " << y << endl;
}
