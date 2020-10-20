#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll link,pearl;
int main(){
    str s;
    cin>>s;

    for(ll i=0;i<s.size();i++){
        if(s[i]=='o'){pearl++;}
        else{link++;}
    }

    if(pearl==0){cout<<"YES";}
    else if(link%pearl==0){cout<<"YES";}
    else{cout<<"NO";}
}






