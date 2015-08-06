#include <cstdio>

#define MAX 500

int properties[MAX][MAX];

int bsearch(int l[], int start, int end, int target) {
    if (start == end) {
        if (l[start] >= target) return start;
        else return -1;
    }
    int center = (start + end)/2;
    if (l[center] >= target) bsearch(l, start, center, target);
    else bsearch(l, center + 1, end, target);
}

int main() {
    int n, m, c, l, u;
    
    scanf ("%d %d", &n, &m);
    do {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int h;
                scanf("%d", &h);
                properties[i][j] = h;
            }
        }
        scanf ("%d", &c);
        while (c > 0) {
            scanf ("%d %d", &l, &u);
            int currentLine = 0, currentColumn = 0;
            for (int i = 0; i < n; i++) {
                int x = bsearch(properties[i], 0, m - 1, l);
                int y = bsearch(properties[i], x, m - 1, u);
                if (x == -1) printf("0");
                else if (y == -1) printf("%d %d\n", x, m-1);
                else printf("%d %d\n", x, y);
            }
            
            c--;
        }
        
        scanf ("%d %d", &n, &m);
    } while (n != 0 && m != 0);
}
