#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define fbo find_by_order
#define ook order_of_key
#define all(x) (x).begin(), x.end()

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 122) return char(x-32);
    if( 65 <= int(x) && int(x) <= 90) return x;
    return -1;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122) return x;
    if( 65 <= int(x) && int(x) <= 90) return char(x+32);
    return -1;
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57) return int(x-'0');
    if( 97 <= int(x) && int(x) <= 122) return int(x-96);
    if( 65 <= int(x) && int(x) <= 90) return int(x-64);
    return -1;
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll quickpow (ll num1, ll num2, ll MOD){
    if(num2==0)return 1%MOD;
    else if(num2==1)return num1%MOD;
    else{
        ll temp = quickpow (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return quickpow (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template
bool calc[5010][5010],memo[5010][5010];
str s;
bool dp(int l, int r){
    if(l>r) return true;
    if(calc[l][r]) return memo[l][r];
    else{
        calc[l][r] = true;
        bool res;
        if(s[l] == s[r]){
            res = dp(l+1,r-1);
        }
        else{
            res = false;
        }
        memo[l][r] = res;
        return res;
    }
}
void prec(str s){
    for(int i=0;i<s.size();i++)
        for(int j=0;j<s.size();j++)
            calc[i][j] = false;
    dp(0,s.size()-1);
}
str creat(str s, int l, int r){
    str res = "";
    for(int i=l;i<=r;i++) res += s[i];
    return res;
}
str solve(str s){
    prec(s);
    pair < int,pii > mx;
    int N = s.size()-1;
    mx.fi = 0;
    for(int i=0;i<=N;i++){
        if(dp(0,i) && i+1 > mx.fi) mx = mp(i+1,mp(0,i));
    }
    for(int i=N;i>=0;i--){
        if(dp(i,N) && N-i+1 > mx.fi) mx = mp(N-i+1,mp(i,N));
    }

    int b = 0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] == s[N-i]) b++;
        else break;
    }

    if(!b) return creat(s,mx.sf,mx.ss);
    else{
        int l = b;
        int r = N-b;
        //cout<<"ni N "<<N<<newl;
        pair <int,pii> mx2 = mp(0,mp(0,0));
        //cout<<l<<" "<<r<<newl;
        for(int i=l;i<=r;i++){
            //cout<<l<<" "<<i<<" "<<dp(l,i)<<newl;
            if(dp(l,i) && i-l+1 > mx2.fi) mx2 = mp(i-l+1,mp(l,i));
        }
        for(int i=r;i>=l;i--){
            if(dp(i,r) && r-i+1 > mx2.fi) mx2 = mp(r-i+1,mp(i,r));
        }

        if(mx2.fi + 2*b > mx.fi){
            str res = "";
            res += creat(s,0,l-1);
            res += creat(s,mx2.sf,mx2.ss);
            res += creat(s,r+1,N);
            return res;
        }
        else return creat(s,mx.sf,mx.ss);
    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        cin>>s;
        cout<<solve(s)<<newl;
    }
}
