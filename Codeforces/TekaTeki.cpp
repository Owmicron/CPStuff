#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a;
str ans;
int main(){
    str s;
    cin>>s;
    ll k; cin>>k;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='_'){a++;}
    }
    for(ll i=1;i<=a;i++){
        ans+="a";
    }
    for(ll i=2;i<=k;i++){
        for(ll j=0;j<a;j++){
            if (ans[j] < 'z'){
                ans[j]=char(int (ans[j])+1);
                break;
            }
            else{ans[j]='a';}

        }
        //cout<<ans<<endl;

    }
    a--;
    for(ll i=0;i<s.size();i++){
        if(s[i]!='_'){cout<<s[i];}
        else{cout<<ans[a];a--;}

    }
    sort(1,1,1);


}
