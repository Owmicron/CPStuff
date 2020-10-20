#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,ans,z;
int contain, incharge;
stack <ll> s[2];
void masuk (ll x){
    if(s[incharge].empty()){s[incharge].push(x);}
    else if(x>=s[incharge].top()){
        z++;
        if(s[incharge].size() == 1){
            ans+=x;
            s[incharge].pop();
            s[incharge].push(x);
        }
        else{
            ll a,b,c;
            b = s[incharge].top();
            c = x;
            s[incharge].pop();
            a = s[incharge].top();
            s[incharge].pop();

            if((a<=b)&&(a<=c)){
                ans+=b;a=0;
            }
            else if((b<=a)&&(b<=c)){
                ans+=min(a,c);b=0;
            }
            if(a>0){masuk(a);}
            if(b>0){masuk(b);}
            if(c>0){masuk(c);}
        }
    }
    else{
        s[incharge].push(x);
    }
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;cin>>a;
        s[0].push(a);
    }
    contain = 0;
    incharge = 1;
    z=1;
    while(z>0){
        z=0;
        while(!s[contain].empty()){
            ll temp = s[contain].top();
            s[contain].pop();
            masuk(temp);
        }
        contain = 1 - contain;
        incharge = 1- incharge;
    }
    if(z==0){
        if(!s[contain].empty()){
            ll temp = -s[contain].top();
            while(!s[contain].empty()){
                temp+=s[contain].top();
                s[contain].pop();
            }
            ans+=temp;
        }
    }
    cout<<ans<<endl;
}
