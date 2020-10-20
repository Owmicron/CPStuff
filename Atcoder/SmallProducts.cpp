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

ll n,k,s;
set <ll> z;
set <ll> :: iterator itr;
ll v[65000],memo[65000][102],ans;
ll md = 1000000007;
bool calc[65000][102];
ll dp (ll x, ll y){
    if(x==0)return 0;
    else if(y==0)return 1;
    else if(calc[x][y])return memo[x][y];
    else{
        ll p = s+1-x;
        ll sel = v[x] - v[x-1];
        ll a,b;
        a = dp(x-1,y);
        b = ((sel%md) * (dp(p,y-1)%md))%md;
        ll res = ((a%md) + (b%md))%md;
        calc[x][y] = true;
        memo[x][y] = res;
        return res;
    }
}
int main(){
	//IO();
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=sqrt(n);i++){
        z.insert(i);
        z.insert(n/i);
    }
    int idx = 0;
    for(itr = z.begin(); itr != z.end(); itr++){
        idx ++;
        v[idx] = *itr;
    }
    s = idx;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=s;j++){
            ans = dp(j,i);
        }
    }
    cout<<ans<<newl;
}

