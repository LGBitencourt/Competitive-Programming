#include <cstdio>
#include <algorithm>

using namespace std;

int s, n;
int triangle[105][105];
int paths[105][105] = {0};

int max_path(int i, int j) {
    if (i > n) return 0;
    if (paths[i][j] != 0) return paths[i][j];

    int path1 = max_path(i + 1, j);
    int path2 = max_path(i + 1, j + 1);

    int path = max(path1, path2) + triangle[i][j];

    paths[i][j] = path;

    return path;

}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) scanf(" %d", &triangle[i][j]);

    printf("%d\n", max_path(0, 0));

}
