/* http://olimpiada.ic.unicamp.br/tobi/problem/show/1/54 */
#include <iostream>

using namespace std;

int main() {
    int l, d, p, k;
    cin >> l >> d >> k >> p;
    cout << (l * k) + ((l/d) * p) << endl;
}
