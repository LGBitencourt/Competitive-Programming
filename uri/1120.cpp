/* The input consists of several test cases, each in one line. Each line contains two integers
 *  * D and N (1 ≤ D ≤ 9, 1 ≤ N < 10^100 ), representing, respectively, the digit that has failed in the machine
 *   * and the number that was originally agreed for the contract (which can be very large because of hiperinflation).
 *    * The last test case is followed by a line which contains only two zeros separated by white space. */

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string replace(string word, string target, string replacement){
    int loop = 0;
    string let;
    while (loop < word.length()) {
        let = word.substr(loop, 1);
        if(let == target) {
            word.erase(loop, 1);
            loop--;
        }
        if(word.substr(0, 1).compare("0") == 0 && word.length() > 1) {
            word.erase(0, 1);
            if (loop > 0) loop--;
        }
        if(word.length() == 0) return "0";
        loop++;
    }
    
    return word;
}

int main() {
    string d, n, s;
    
    while (cin >> d >> n){
        if ((n.compare("0") != 0 && d.compare("0") != 0)) {
            s = replace(n , d, "");
            cout << s << endl;
        }
    }

    return 0;
}
