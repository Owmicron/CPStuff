#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
ll n,m,gcd;
int main(){
    cin>>n>>m;
    for(int i=1;i<=sqrt(m);i++){
        if(m%i==0){
            ll a,b;
            a = i; b = m/i;
            if(b>=n){gcd=max(gcd,a);}
            swap(a,b);
            if(b>=n){gcd=max(gcd,a);}
        }
    }
    cout<<gcd<<endl;


}
