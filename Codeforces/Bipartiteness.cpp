#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
pair <ll,ll> node[100001];
ll s;
bool l[100001],a[100001];
int main(){
    cin>>n;
    for(ll i=1;i<n;i++){
        cin>>node[i].first>>node[i].second;
        if(node[i].second < node[i].first){swap(node[i].second,node[i].first);}
    }
    sort(node+1,node+n);
    l[node[1].first]=true;
    a[node[1].first]=true;s++;

    while(s<n){

    for(ll i=1;i<n;i++){
        if(a[node[i].first]){l[node[i].second ] = not l[node[i].first];a[node[i].second ] =true;s++;}
        else if(a[node[i].second]){l[node[i].first ] = not l[node[i].second];a[node[i].first ]=true;s++;}
    }

    }
    ll k=0;
    for(ll i=1;i<=n;i++){
        if(l[i]){k++;}
    }
    cout<<(k*(n-k))-(n-1);


}
