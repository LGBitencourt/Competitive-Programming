#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int points;
};

bool operator < (const Player &a, const Player &b) {
    if (a.points != b.points) return a.points > b.points;
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    int p, ma, mi, j, t = 0;

    Player players[1005];
    cin >> p;
    while (p != 0) {
        for (int i = 0; i < p; i++) {
            cin >> players[i].name;
            players[i].points = 0;
            cin >> ma;
            players[i].points = mi = ma;
            for (int x = 1; x < 12; x++) {
                cin >> j;
                if (j > ma) ma = j;
                if (j < mi) mi = j;
                players[i].points += j;
            }
             players[i].points -= (ma + mi);
        }


        sort(players, players + p);

        cout << "Teste " << ++t << "\n";
        int lp = players[0].points, li = 1;
        cout << "1 " << lp << " " << players[0].name << "\n";
        for (int i = 1; i < p; i++) {
            if (players[i].points == lp) cout << li << " ";
            else {
                li = i + 1;
                cout << i + 1 << " ";
                lp = players[i].points;
            }
            cout << lp << " " << players[i].name << "\n";
        }

        cout << "\n";
        cin >> p;
    }
}
