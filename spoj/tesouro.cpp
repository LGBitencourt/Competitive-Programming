#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, Vmax;
int mpd[100][100][100];
int V[100], C[100];

int pd (int i, int v, int c) {
    if (i == n) return 0;
    if (mpd[i][v][c]) return mpd[i][v][c];

    int ans, r1, r2;
    r1 = r2 = INT_MAX;

    if (
}

int main() {
    
}
