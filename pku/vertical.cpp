#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int h[26] = {0};
    int max = 0;
    string line;

    for (int i = 0; i < 4; i++) {
        getline(cin, line);
        for (int j = 0; j < line.length(); j++) {
            if (line[j] >= 'A' && line[j] <= 'Z') {
                h[line[j] - 'A'] += 1;
                if (h[line[j] - 'A'] > max) max = h[line[j] - 'A'];
            }
        }
    }

    while (max > 0) {
        int lastprint = 0, pf = 0;
        for (int i = 0; i < 26; i++) {
            if (h[i] >= max) cout << '*', lastprint = i;
            printf("%c", j == 25 ? '\n' : ' ');
        }
        max--;
    }

    for (char i = 'A'; i < 'Z'; i++) cout << i << " ";
    cout << "Z\n";

}
