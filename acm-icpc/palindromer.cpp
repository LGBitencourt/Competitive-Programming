#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool is_palindrome(string m) {
    bool p = true;
    int i = 0;
     while (i < m.length()) {
        if (m[i] != m[m.length() - i - 1]) p = false;
        i++;
    }
    return p;    
}

int main() {
    ios::sync_with_stdio(false);

    string m, x;
    char mc[10];
    char mci;
    int l, step;

    cin >> mc;
    m = mc;
    l = m.length();

    while (m.compare("0") != 0) {
        int i = 0;
        step = 0;
        bool p;

        p = is_palindrome(m);

        if (p) cout << "0\n";
        else {
            int k = atoi(mc);
            do {
                stringstream ss;
                step++;
                ss << (k + step);
                x = ss.str();
                while (x.length() < l) x.insert(0, 1, '0');
            } while (!is_palindrome(x));
            cout << step << "\n";
        }
        cin >> mc;
        m = mc;
        l = m.length();
    }
}
