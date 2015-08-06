#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    bool f = true;
    while (!cin.eof()) {
        map<string, int> trees;
        string tree;
        double t = 0.0;
        while (getline(cin, tree)) {
            cout << tree << "\n";
            if (tree.empty()) break;
            t++;
            map<string, int>::iterator f = trees.find(tree);
            if (f != trees.end()) f->second++;
            else trees.insert(pair<string, int>(tree, 1));
        }

        if (!f) cout << '\n';
        f = false;

        for (map<string, int>::iterator it = trees.begin(); it != trees.end(); ++it) {
            cout << it->first << ' ' << fixed << setprecision(4) << 100*((it->second)/t) << '\n';
        }
    }
}
