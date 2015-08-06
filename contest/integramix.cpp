#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string check, until, in, current;
    int p;
    while(scanf("%s", &in)!=EOF){
        p=1;
        until = "";
        check = "";
        check[0] = in[0];
        while(until!=in && !(check.length()>(in.length()/2))&&p<in.length()-1){
            current = in.substr(p, check.length());
            if(check==current){
                until = until +  current;
                p+=check.length();
            }
            else{
                until[until.length()] = current[0];
                check = until;
                p++;
            }
        }
        if(check.length()>in.length()/2)
            printf("%d\n", in.length());
        else
            printf("%d\n", check.length());
    }
}
