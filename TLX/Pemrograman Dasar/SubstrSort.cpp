#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
pair<ll,str> s[1000];ll n;
bool conf(){
    bool x=true;
    for(ll i=1;i<n;i++){
        ll z;
        z=s[i+1].second.find(s[i].second);
        if(z>101){x = false;break;}

    }
    return x;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        //getline(cin,s[i]);
        cin>>s[i].second;
        s[i].first=s[i].second.size();
    }
    sort(s+1,s+1+n);
    bool c=conf();
    //cout<<c<<endl;

    if(c){cout<<"YES"<<endl;
    for(ll i=1;i<=n;i++){
        cout<<s[i].second<<endl;
    }
    }
    else{cout<<"NO"<<endl;}
}

