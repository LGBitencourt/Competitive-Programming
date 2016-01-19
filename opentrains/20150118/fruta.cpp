#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main () {
   int n;
   cin >> n;
   int p = 1;
   if(n & 1) {
   		while(p<n) {
   			if(p != 1)
   				cout << " ";
   			cout << p;
   			p*=2;
   		}
   } else {
   	while(p<n) {
   			if(p != 1)
   				cout << " ";
   			cout << p;
   			p*=3;
   		}
   }
   cout << endl;
}

