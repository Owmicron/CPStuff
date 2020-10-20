#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,h,a,b,k,ta,fa,tb,fb,ans;
bool pass(ll x){
    if((x>=a)&&(x<=b)){return true;}
    else{return false;}
}

int main(){
    cin>>n>>h>>a>>b>>k;
    for(ll i=1;i<=k;i++){
        ans=0;
        cin>>ta>>fa>>tb>>fb;
        if(ta==tb){ans += abs(fa-fb);}
        else{
            ans+=abs(tb-ta);
            if(!pass(fa)){
                if (abs(fa-a)<abs(fa-b)){ans+=abs(fa-a)+abs(a-fb);}
                else {ans+=abs(fa-b)+abs(b-fb);}
            }
            else{
                ans+= abs(fa-fb);
            }
        }
        cout<<ans<<endl;
    }
}
