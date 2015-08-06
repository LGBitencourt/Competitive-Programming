#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int r, g, b;
    int r1, g1, b1, r2, g2, b2, m1, m2;
    r1 = g1 = b1 = r2 = g2 = b2 = m1 = m2 = 0;
    cin >> r >> g >> b;

    int m_0 = r/3 + g/3 + b/3;

    if (r > 0 && g > 0 && b > 0) r1 = r-1, g1 = g - 1, b1 = b - 1, m1 = 1;
    if (r > 1 && g > 1 && b > 1) r2 = r-2, g2 = g - 2, b2 = b - 2, m2 = 2;
    
    int m_1 = (r1/3) + (g1/3) + (b1/3) + m1;
    int m_2 = (r2/3) + (g2/3) + (b2/3) + m2;

    cout << max(m_0, max(m_1, m_2)) << "\n";
}
