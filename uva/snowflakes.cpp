#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t, j, max = 0, sum=0, aux;
    vector<int> v1, v2;
    scanf("%d %d", &t, &n);

    while (t--) {
        
        for (int i = 0; i < n; i++){
            scanf(" %d", &aux);
            v1.push_back(aux);
        }

        int start = 0, max = 1;
        for (int i = 1; i < n; i++) {
            if(!binary_search(v1.begin() + start, v1.begin() + i - 1, v1[i])) {
                if (i - start + 1 > max) max = i - start + 1;
            } else {
                start = i;
            }
        }

        printf("%d\n", max);

    }

}
