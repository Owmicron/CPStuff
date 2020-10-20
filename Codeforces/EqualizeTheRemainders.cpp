#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a[200001],r[200001],moves,ex[200001];
deque<ll>v [200001];
int main(){
    ll n,m;
    cin>>n>>m;
    ll desired=n/m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        r[ a[i]%m ]++;
        v[a[i]%m].push_back(i);

    }

    ll t=0;
    for(ll i=0;i<m;i++){

        if(r[i]>desired){
            if(i<m-1){
                t = r[i] - desired;
                r[i+1]+= t;
                r[i]=desired;
            }
            else{
                t = r[i] - desired;
                r[0]+= t;
                r[i]=desired;
            }
            ex[i]=t;
            moves+=t;
//            for(ll j=1;j<=n;j++){
//                if(a[j]%m == i){a[j]++;t--;moves++;if(t==0){break;}}
//            }

        }

    }

    t = 0;

    for(ll i=0;i<m;i++){

        if(r[i]>desired){
            if(i<m-1){
                t = r[i] - desired;
                r[i+1]+= t;
                r[i]=desired;
            }
            else{
                t = r[i] - desired;
                r[0]+= t;
                r[i]=desired;
            }
            ex[i]=t;
            moves+=t;
//            for(ll j=1;j<=n;j++){
//                if(a[j]%m == i){a[j]++;t--;moves++;if(t==0){break;}}
//            }
        }


    }

    for(ll i=0;i<m;i++){
        while(ex[i]>0){

            a[v[i].front()]++;
            v[i+1].push_back (v[i].front());
            v[i].pop_front();
            ex[i]--;

        }

    }

    cout<<moves<<endl;
    for(ll i=1;i<=n;i++){cout<<a[i]<<" ";}
}


