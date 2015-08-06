#include <cstdio>

int main() {
    int a, c, i, l, turns = 0;


    do{

        turns = 0;
        
        scanf("%d %d", &a, &c);
        if (a == 0 && c == 0) break;

        scanf("%d", &l);
        turns = a - l;
        for(i = 1; i < c; i++) {
            int h;
            scanf("%d", &h);
            if(h < l){
                turns += (l - h);
            }
            l = h;
        }

        printf("%d\n", turns);

    } while(a != 0 && c != 0);


    return 0;
}
