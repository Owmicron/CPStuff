#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;bool l[130];ll ans;
bool inrange(char c){
    if((int (c) <= 96+26) && (int (c) >=96+1)){return true;}
    else{return false;}
}
int main(){
    getline(cin,s);
    for(ll i=0;i<s.size();i++){
        if(inrange(s[i])){
            ll z=int(s[i]);
            if(not l[z]){l[z] = true; ans++;}
        }
    }
    cout<<ans;
}

