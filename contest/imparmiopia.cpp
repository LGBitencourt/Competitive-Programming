#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    string n;
    unsigned long int c;
    while(cin >> n) {
        c = 0;
        for(int i = 0; i < n.length(); i++) {
            if(((int) n[i] - '0') % 2 == 1) c++;
        }           
        printf("%d\n", c);
    }
}
