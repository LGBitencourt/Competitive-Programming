#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
//REMEMBER TO DECLARE GLOBAL VARIABLES

char get(char c, int dir){
    if(c=='p'){
        if(dir==UP || dir==LEFT)
            return 'x';
        if(dir==DOWN)
            return 's';
        if(dir==RIGHT)
            return 'q';
    }
    if(c=='q'){
        if(dir==UP || dir==RIGHT)
            return 'x';
        if(dir==DOWN)
            return 'r';
        if(dir==LEFT)
            return 'p';
    }
    if(c=='s'){
        if(dir==DOWN || dir==LEFT)
            return 'x';
        if(dir==UP)
            return 'p';
        if(dir==RIGHT)
            return 'r';
    }
    if(c=='r'){
        if(dir==DOWN || dir==RIGHT)
            return 'x';
        if(dir==UP)
            return 'q';
        if(dir==LEFT)
            return 's';
    }
}

int op(int dir){
    if(dir==UP) return DOWN;
    if(dir==LEFT) return RIGHT;
    if(dir==DOWN) return UP;
    if(dir==RIGHT) return LEFT;
}

string move(string s, int dir){
    if(s.length()==0) return "x";
    char c, d;
    string ans;
    c = s[s.length()-1];
    d = get(c, dir);
    if(d!='x'){
        ans = s.substr(0, s.length()-1) + d;
    }
    else{
        ans = move(s.substr(0, s.length()-1), dir);
        if(ans != "x") ans += get(c, op(dir));
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long int t;
    string s, ans;
    cin >> t;
    while(t--){
        cin >> s;
        s = s.substr(1, s.length()-1);
        for(int i = 1; i<4; i++){
            ans = move(s, i);
            if(ans != "x")
                cout << "m" << ans << " ";
            else
                cout << "<none> ";
        }
        ans = move(s, 4);
        if(ans != "x")
            cout << "m" << ans;
        else
            cout << "<none>";
        cout << "\n";
    }
}
