/* http://olimpiada.ic.unicamp.br/tobi/problem/show/1/59 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int y, t = 1986;
    cin >> y;
    while (t <= y) t += 76;
    cout << t << '\n';
}
