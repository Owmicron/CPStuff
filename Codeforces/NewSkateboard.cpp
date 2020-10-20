#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
ll ans;
void cnt(ll x){
    if(((int(s[x])-48)%4)==0){
        ans++;
    }
    ll temp = (int(s[x])-48);
    x--;
    if(x>=0){
            temp = temp + (int(s[x])-48)*10;
            if(temp%4==0){
                ans++;
                x--;
                if(x>=0){
                    ans+= x+1;
                }
            }
    }
}
int main(){
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if((int(s[i])-48)%2==0){
            cnt(i);
        }
    }
    cout<<ans<<endl;
}
