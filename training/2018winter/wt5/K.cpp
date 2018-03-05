#include <bits/stdc++.h>
using namespace std;
string morse;
int parse(int l,int r) {
    string tmp="";
    for(int i=l;i<=r;++i) {
        tmp+=morse[i];
    }
    if(tmp==".-") return 0;
    else if(tmp=="-...") return 1;
    else if(tmp=="-.-.") return 2;
    else if(tmp=="-..") return 3;
    else if(tmp==".") return 4;
    else if(tmp=="..-.") return 5;
    else if(tmp=="--.") return 6;
    else if(tmp=="....") return 7;
    else if(tmp=="..") return 8;
    else if(tmp==".---") return 9;
    else if(tmp=="-.-") return 10;
    else if(tmp==".-..") return 11;
    else if(tmp=="--") return 12;
    else if(tmp=="-.") return 13;
    else if(tmp=="---") return 14;
    else if(tmp==".--.") return 15;
    else if(tmp=="--.-") return 16;
    else if(tmp==".-.") return 17;
    else if(tmp=="...") return 18;
    else if(tmp=="-") return 19;
    else if(tmp=="..-") return 20;
    else if(tmp=="...-") return 21;
    else if(tmp==".--") return 22;
    else if(tmp=="-..-") return 23;
    else if(tmp=="-.--") return 24;
    else if(tmp=="--..") return 25;
}
int main() {
    while(cin>>morse) {
        string ans=""; morse+="/";
        int last_pos=0;
        for(int i=0;i<morse.size();i++) {
            if(morse[i]=='/') {
                if(i==last_pos) {
                    ans+=" ";
                }else ans+=parse(last_pos,i-1)+'A';
                last_pos=i+1;
            }
        }
        cout<<ans<<endl;
    }
}