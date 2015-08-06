#include <cstdio>

int main() {
    int has_english, t, n;
    scanf(" %d", &t);
    char words[101][11];
    while (t--) {
        has_english = -1;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            if (words[i][0] != '#') has_english = i;
        }
        for (int i = has_english + 1; i < n; i++) {
            printf("%s", words[i]);
            if ((has_english == -1 && i < n - 1) || has_english != -1) printf(" ");
        }
        if (has_english >= 0) {
            printf("%s", words[has_english]);
            if (has_english != 0) printf(" ");
        }

        for (int i = 0; i < has_english; i++) {
            printf("%s", words[i]);
            if (i < has_english - 1) printf(" ");
        }
        printf("\n");
    }
}
