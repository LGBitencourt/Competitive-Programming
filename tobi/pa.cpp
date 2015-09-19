#include <climits>
#include <iostream>

using namespace std;

int main() {
    int count = 1, last, t, d;
    int pa[100005];

    cin >> t;

    for (int i = 0; i < t; i++)
        cin >> pa[i];

    if (t <= 2) {
        cout << 1 << endl;
        return 0;
    }

    d = pa[1] - pa[0];

    for (int i = 1; i < t - 1; i++) {
        if (pa[i + 1] - pa[i] != d) {
            count++, d = pa[i + 2] - pa[i + 1];
        }
    }
    cout << count << endl;
}
