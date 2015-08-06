#include <iostream>
#include <algorithm>

using namespace std;

struct Country {
    int id, medals;
};

bool operator <(const Country &a, const Country &b) {
    if (a.medals != b.medals) return a.medals > b.medals;
    return a.id < b.id;
}

int main() {
    Country countries[105];
    int n, m, o, p, b;
    cin >> n >> m;

    for (int i = 0; i < n; i++) countries[i].id = i, countries[i].medals = 0;

    for (int i = 0; i < m; i++) {
        cin >> o >> p >> b;
        countries[o-1].medals++;
        countries[p-1].medals++;
        countries[b-1].medals++;
    }

    sort(countries, countries + n);

    for (int i = 0; i < n; i++) cout << countries[i].id + 1 << ' ';
    cout << '\n';
}
