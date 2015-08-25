#include <cstdio>

int grid[9][9];

bool row (int i, int n) {
    for (int j = 0; j < 9; j++)
        if (grid[i][j] == n)
            return true;
    return false;
}

bool column (int j, int n) {
    for (int i = 0; i < 9; i++)
        if (grid[i][j] == n)
            return true;
    return false;
}

bool box(int i, int j, int n) {
    i = i - (i % 3), j = j - (j % 3);
    for (int l = 0; l < 3; l++)
        for (int c = 0; c < 3; c++)
            if (grid[l + i][c + j] == n)
                return true;
    return false;
}

bool unassigned (int *i, int *j) {
    for (*i = 0; *i < 9; *i += 1)
        for (*j = 0; *j < 9; *j += 1)
            if (grid[*i][*j] == 0)
                return true;
    return false;
}

bool sudoku() {
    int i, j;

    if (!unassigned(&i, &j))
        return true;

    for (int n = 1; n <= 9; n++) {
        if (!row(i, n) && !column(j, n) && !box(i, j, n)) {
            grid[i][j] = n;
            if (sudoku())
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        char c;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf(" %c", &c);
                grid[i][j] = c - '0';
            }
        }
        sudoku();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                printf("%d", grid[i][j]);
            putchar('\n');
        }
    }
}
