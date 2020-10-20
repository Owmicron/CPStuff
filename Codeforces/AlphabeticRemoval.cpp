#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
char alpha[30];
deque<ll> v[30];
str s;
bool e[400001];
int main(){
    ll n,k;
    cin>>n>>k;
    cin>>s;
    for(ll i=1;i<=26;i++){
        alpha[i]=char(96+i);
    }

    for(ll i=0;i<s.size();i++){
        ll temp;
        temp = int(s[i]-96);
        v[temp].push_back(i);
        //cout<<temp<<s[i]<<endl;
    }

    ll c=1;
    while(k>0){
        k--;

        while(v[c].empty()){c++;}
        if(!v[c].empty()){
            e[v[c].front()]=true;
            v[c].pop_front();
        }
    }

    for(ll i=0;i<s.size();i++){
        if(!e[i]){cout<<s[i];}

    }
}

