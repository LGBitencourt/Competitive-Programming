#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string a, b, c;
    int t;
    scanf("%d", &t);
    while (t > 0) {
        cin >> a >> b >> c;
        if((a[0] == a[1] && a[0] == a[2]) && a[0] != '.') printf("Y\n");
        else if((b[0] == b[1] && b[0] == b[2]) && b[0] != '.') printf("Y\n");
        else if((c[0] == c[1] && c[0] == c[2]) && c[0] != '.') printf("Y\n");
        else if((a[0] == b[0] && a[0] == c[0]) && a[0] != '.') printf("Y\n");
        else if((a[1] == b[1] && a[1] == c[1]) && a[1] != '.') printf("Y\n");
        else if((a[2] == b[2] && a[2] == c[2]) && a[2] != '.') printf("Y\n");
        else if((a[0] == b[1] && a[0] == c[2]) && a[0] != '.') printf("Y\n");
        else if((c[0] == b[1] && c[0] == a[2]) && c[0] != '.') printf("Y\n");
        else printf("N\n");
        t--;
    }
    return 0;
}
