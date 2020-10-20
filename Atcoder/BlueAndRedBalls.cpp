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
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'
char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

ll n,k,b,r;
ll md = 1000000007;
ll f[10000];
ll pm (ll x, ll y){
    if(y==0)return 1;
    else if(y==1){return x;}
    else{
        ll t = pm (x,y/2);
        ll res = ((t%md)*(t%md))%md;
        if(y%2==1){res = ((res%md) * (x%md))%md ;}
        return res;
    }
}
ll invers(ll x){
    return pm(x,md-2);
}
ll conf(ll slot, ll sum){
    if(sum==0)return 1;
    else if(sum<0)return 0;
    else if(slot==1)return 1;
    else{
        ll bar = slot-1;
        ll up = f[sum+bar];
        ll d1 = f[bar];
        ll d2 = f[sum];
        ll d = ((d1%md)*(d2%md))%md;
        ll din = invers(d);
        ll star = ((up%md) * (din%md))%md;
        return star;
    }
}
ll solve(ll x){
    ll slot,sum,red,blue;
    slot = x + 1;
    sum = r - (x-1);
    red = conf(slot,sum);

    slot = x;
    sum = b - x;
    blue = conf(slot,sum);
    ll res = ((red%md)*(blue%md))%md;
    return res;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    b = k;
    r = n - k;
    f[0] = 1;
    for(int i=1;i<=8000;i++){
        f[i] = ((f[i-1]%md)*(i%md))%md;
    }
    for(int i=1;i<=k;i++){
        cout<<solve(i)<<newl;
    }
}
