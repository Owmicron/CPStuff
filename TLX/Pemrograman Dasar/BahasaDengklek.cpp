#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b,c,d;
bool isupper(char c){
    if((c>96)&&(c<123)){return false;}
    else{return true;}
}
char change(char c){
    if(isupper(c)){return char(int(char(c)+32));}
    else{return char(int(char(c)-32));}
}
int main(){
    str s;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        cout<<change(s[i]);
    }
    cout<<endl;
}





