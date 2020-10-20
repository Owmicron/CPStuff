#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
vector <pair<ll,ll> >stores;
ll n,m;
ll spent;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a,b;cin>>a>>b;
        stores.push_back(make_pair(a,b));
    }
    sort(stores.begin(),stores.end());
    ll buy = 0;
    for(int i=0;i<stores.size();i++){
        ll cost,stock;
        cost=stores[i].first;
        stock=stores[i].second;

        if(buy+stock > m){
            ll p = m - buy;
            spent += p*cost;
            break;
        }
        else{
            buy+=stock;
            spent += stock*cost;
        }
    }
    cout<<spent<<endl;
}
