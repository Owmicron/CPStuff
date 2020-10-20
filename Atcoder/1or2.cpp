#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
int parent[200000],f[200000];
int findrep(int x){
    if(parent[x]==x) return parent[x];
    else{
        return findrep (parent[x]);
    }
}
void join (int a, int b){
    int repa,repb;
    repa = findrep(a);
    repb = findrep(b);
    if(repa>repb)swap(repa,repb);
    if(repa!=repb)parent[repb]=repa;
}
int n,m,ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        join (a,b);
    }

    for(int i=1;i<=n;i++){
        int par = findrep(i);
        if(f[par]==0){f[par]++;ans++;}
    }
    cout<<ans<<endl;
}
