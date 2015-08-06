#include <iostream>

using namespace std;

int adj[9][9];

int main() {
    int degree, nodes;

    cin >> nodes;

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            cin >> adj[i][j];

    for (int i = 0; i < nodes; i++) {
        degree = 0;
        for (int j = 0; j < nodes; j++) degree += adj[i][j];
        cout << "out-degree node " << i << " = " << degree << endl;
    }

    cout << endl;

    for (int j = 0; j < nodes; j++) {
        degree = 0;
        for (int i = 0; i < nodes; i++) degree += adj[i][j];
            cout << "in-degree node " << j << " = " << degree << endl;
    }

}
