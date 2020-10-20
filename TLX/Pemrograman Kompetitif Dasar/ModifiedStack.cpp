#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x,y,d;
str s;
stack<ll> z;
pair<ll,ll> data[10100];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        if(s=="add"){
            cin>>x>>y;
            for(ll i=1;i<=y;i++){
                z.push(x);
            }
            cout<<z.size()<<endl;
        }
        else if(s=="del"){
            cin>>y;
            ll t=0;
            for(ll i=d;i>=1;i--){
                if(z.size()<=data[i].first){
                    t+=data[i].second;
                }
                else{break;}
            }
            cout<<z.top()+t<<endl;
            for(ll i=1;i<=y;i++){
                if(!z.empty()){z.pop();}
                else{break;}
            }
            for(ll i=d;i>=1;i--){
                if(data[i].first > z.size()){data[i].first=z.size();}
                else{break;}
            }
        }
        else if(s=="adx"){
            cin>>x;
            d++;
            data[d].first = z.size();
            data[d].second = x;
        }
        else if(s=="dex"){
            cin>>x;
            d++;
            data[d].first = z.size();
            data[d].second = -x;
        }
    }
}
