#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string name;
    double s, b;
    cin >> name;
    cin >> s >> b;
    cout << "TOTAL = R$ " << fixed << setprecision(2) << (s + b*0.15) << endl;
    return 0;
}
