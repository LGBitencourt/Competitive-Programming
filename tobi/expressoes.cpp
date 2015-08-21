#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

char inverte (char c) {
    if (c == '}') return '{';
    if (c == ']') return '[';
    if (c == ')') return '(';
}

int main() {
    string exp;
    char e[100005];
    int t;
    scanf(" %d", &t);

    while (t--) {
        stack<char> op;
        bool shit = false;
        scanf(" %s", e);
        exp = e;
        for (int i = 0; i < exp.length() && !shit; i++) {
            if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
                op.push(exp[i]);
            } else {
                if (op.empty())
                    shit = true;
                else {
                    if (inverte(exp[i]) == op.top())
                       op.pop();
                    else shit = true; 
                }
            }
        }

        if (op.empty() && !shit) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
}
