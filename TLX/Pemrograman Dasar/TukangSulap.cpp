#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll ball[3][1000];
void sh(char p, ll x, char q, ll y){
    ll a,b;
    if (p=='A'){a=1;}
    else{a=2;}
    if (q=='A'){b=1;}
    else{b=2;}

    swap(ball[a][x],ball[b][y]);
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>ball[1][i];
    }
    for(ll i=1;i<=n;i++){
        cin>>ball[2][i];
    }
    ll q;
    cin>>q;
    char c,d;ll a,b;
    for(ll i=1;i<=q;i++){
        cin>>c>>a>>d>>b;
        sh(c,a,d,b);
    }

    for(ll i=1;i<=n;i++){
        cout<<ball[1][i];
        if(i<n){cout<<" ";}
        else{cout<<endl;}
    }
    for(ll i=1;i<=n;i++){
        cout<<ball[2][i];
        if(i<n){cout<<" ";}
        else{cout<<endl;}
    }
}


