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
ll md = 1000000007;
ll n,m,k,temp;
ll p (ll a, ll b){
    if(b==0)return 1;
    else if(b==1)return a;
    else{
        ll temp = p (a,b/2);
        ll t = ((temp % md) * (temp % md))%md;
        if(b%2==1){ t = ((t%md) * (a%md))%md; }
        return t;
    }
}
ll ans = 0,occ;
ll choose (ll a, ll b){
    if(a<b)return 0;
    else if(b==0)return 1;
    else if(b==1)return 2;
    else{
        ll c = a-b;
        if(b<c)swap(b,c);

        vll up,down;
        for(int i=a;i>max((ll)1,b);i--)up.pb(i);
        for(int i=2;i<=c;i++)down.pb(i);

        ll u,d;
        u = 1;
        d = 1;
        for(int i=0;i<up.size();i++){
            u = ((u%md) * (up[i]%md))%md;
        }
        for(int i=0;i<down.size();i++){
            d = ( (d%md) * (down[i]%md) ) % md;
        }
        ll inverse = p (d , md-2);
        inverse %= md;

        ll total = ((u % md) * (inverse % md))%md;
        return total;
    }

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    occ = choose (n*m - 2 , k - 2);

    for(int i=1;i<m;i++){
        temp = ((n*n)%md * (m-i)%md)%md;
        temp = ((i%md)*(temp%md))%md;
        ans = ((ans%md) + (temp%md))%md;
    }

    for(int i=1;i<n;i++){
        temp = ( (m*m)%md * (n-i)%md )%md;
        temp = ((i%md)*(temp%md))%md;
        ans = ((ans%md) + (temp%md))%md;
    }

    ans = ((ans%md) * (occ%md))%md;
    cout<<ans<<newl;

}
