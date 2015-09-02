#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int q, dx, dy, x, y;
    while (cin >> q, q != 0) {
        cin >> dx >> dy;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            if (x == dx || y == dy)
                cout << "divisa\n";
            else if (x > dx && y > dy)
                cout << "NE\n";
            else if (x < dx && y > dy)
                cout << "NO\n";
            else if (x < dx && y < dy)
                cout << "SO\n";
            else if (x > dx && y < dy)
                cout << "SE\n";
        }
    }
}
