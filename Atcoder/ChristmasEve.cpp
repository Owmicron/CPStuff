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
int n,k,h[200000],mn;
int main(){
    cin>>n>>k;
    mn = 1000000000;
    for(int i=1;i<=n;i++)cin>>h[i];
    sort(h+1,h+1+n);

    for(int i=1;i<=n-k+1;i++){
        int dif;
        dif = h[i+k-1] - h[i];
        mn = min(mn,dif);
    }
    cout<<mn<<endl;
}
