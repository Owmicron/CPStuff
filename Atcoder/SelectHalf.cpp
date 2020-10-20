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
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
ll n,a[200010];
ll dp[200010];
ll solve_even(){
    int q = n/2;
    dp[1] = a[1];
    dp[2] = a[2];

    for(int i=3;i<=n;i+=2){
        dp[i] = a[i] + dp[i-2];
        dp[i+1] = a[i+1] + max(dp[i-1],dp[i-2]);
    }

    ll res = max(dp[n],dp[n-1]);
    return res;
}
ll solve_odd(){
    dp[1] = a[1];
    dp[2] = a[2];
    dp[3] = a[3];

    int q = n/2;
    for(int i=2;i<=q;i++){
        vi choice;
        choice.pb((i-1)*2 - 1);
        choice.pb((i-1)*2);
        choice.pb((i-1)*2 + 1);

//        cout<<"i = "<<i<<newl;
//        for(int j=0;j<choice.size();j++){
//            cout<<choice[j]<<" "<<dp[choice[j]]<<newl;
//        }
        for(int j=(2*i+1);j>=(2*i-1);j--){
            vll c;
            for(int k=0;k<choice.size();k++){
                int temp = choice[k];
                if(abs(j - temp) > 1){
                    c.pb(a[j] + dp[temp]);
                    //cout<<j<<" === "<<dp[j]<<newl;
                }
            }
            ll r = - (1e17);
            for(int j=0;j<c.size();j++) r = max(r,c[j]);
            dp[j] = r;
        }
    }

//    cout<<(q-1)*2-1 <<" "<<(q-1)*2<<" "<<(q-1)*2+1<<newl;
//    cout<<dp[(q-1)*2-1]<<" // "<<dp[(q-1)*2]<<" // "<<dp[(q-1)*2+1]<<newl;
    ll res = dp[(q)*2-1];
    res = max(res , dp[(q)*2]);
    res = max(res , dp[(q)*2+1]);

    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<=2e5;i++) dp[i] = - (1e17);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n%2) cout<<solve_odd()<<newl;
    else cout<<solve_even()<<newl;
    return 0;
}

