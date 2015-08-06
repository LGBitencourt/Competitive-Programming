#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    char b[10005];
    char p[105];
    string bracelete, sequencia, r;
    scanf(" %d", &t);
    while (t--) {
        cin >> sequencia >> bracelete;
        do{
            bracelete.append(bracelete);
        } while(bracelete.length() < sequencia.length());

        if (bracelete.find(sequencia) != string::npos) cout << "S" << endl;
        else {
            reverse(bracelete.begin(), bracelete.end());
            if (bracelete.find(sequencia) != string::npos) cout << "S" << endl;
            else cout << "N" << endl;
        }
    }
}
