#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() { 
    ios::sync_with_stdio(false);
 
    string f_word, e_word, word, line;
    map<string, string> d;
    map<string, string>::iterator it;

    while (1) {
        getline(cin, line);
        if (line.empty()) break;

        int i = 0, j = 0;
        while (line[i] != ' ') e_word.push_back(line[i]), i++;
        i++;
        while (i < line.length()) f_word.push_back(line[i]), i++;
        d.insert(pair<string, string>(f_word, e_word));
        e_word.clear(), f_word.clear();
    }

    while (cin >> word) {
        it = d.find(word);
        if (it != d.end()) {
            cout << it->second << "\n";
        } else {
            cout << "eh\n";
        }
    }

}
