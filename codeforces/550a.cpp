#include <cstdio>
#include <string>
#include <utility>

using namespace std;

pair<int, int> * ab_positions;
pair<int, int> * ba_positions;

int main() {
    ab_positions = new pair<int, int>[100005];
    ba_positions = new pair<int, int>[100005];
    char w[100005];
    char ant;
    string s;
    int has = 0, l, ab = 0, ba = 0;

    scanf("%s", w);
    s = w, l = s.length(), ant = s[0];

    for (int i = 1; i < l; i++) {
        if (ant == 'A' && s[i] == 'B') {
            ab_positions[ab++] = make_pair(i - 1, i);
        } else if (ant == 'B' && s[i] == 'A') {    
            ba_positions[ba++] = make_pair(i - 1, i);
        }
        ant = s[i];
    }
    
    for (int i = 0; i < ab; i++) {
        for (int j = 0; j < ba; j++) {
            if (ab_positions[i].first != ba_positions[j].second && ab_positions[i].second != ba_positions[j].first) {
                has = 1;
                break;
            }
        }
    }

    if (has) printf("YES\n");
    else printf("NO\n");

}
