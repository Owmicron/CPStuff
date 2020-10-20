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

str l;
vi one;
int n;
ll md = 1000000007;
ll p3[100100];
bool hitung[100100];
ll nex[100100];
ll pow3(ll x){
    if(x==0)return 1;
    else if(x==1)return 3;
    else if(hitung[x])return p3[x];
    else{
        ll temp = pow3(x/2);
        ll res = (((temp%md) * (temp%md))%md);
        if(x%2==1){
            res = ((res%md) * (3%md))%md;
        }
        hitung[x]=true;
        p3[x] = res;
        return res;
    }
}
bool calc[100100];
ll memo[100100];
ll dp (ll x){
    if(x>n)return 1;
    else if(calc[x])return memo[x];
    else{
        ll sisa = n - x;
        ll a,b;
        a = pow3(sisa);
        b = ((2%md) * (dp(nex[x])%md))%md;
        ll res = ((a%md + b%md))%md;
        calc[x]=true;
        memo[x]=res;
        return res;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l;
    for(int i=0;i<l.size();i++){
       if(l[i]=='1'){one.pb(i+1);}
    }
    n = l.size();
    one.pb(n+1);
    for(int i=0;i<one.size()-1;i++){
        nex[one[i]] = one[i+1];
    }

    ll ans = dp(one[0]);
    cout<<ans<<newl;

}
