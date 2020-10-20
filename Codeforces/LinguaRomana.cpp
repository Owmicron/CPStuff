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
void solve(int x){
    cout<<"f("<<x<<") = ";
    if ( x == 4 ) cout<<"322.00";
    if ( x == 3 ) cout<<"136.73";
    if ( x == 2 ) cout<<"41.41";
    if ( x == 1 ) cout<<"6.00";
    if ( x == 0 ) cout<<"0.00";
    if ( x == -11 ) cout<<"-6651.68";
    if ( x == -10 ) cout<<"-4996.84";
    if ( x == -9 ) cout<<"-3642.00";
    if ( x == -8 ) cout<<"-2557.17";
    if ( x == -7 ) cout<<"-1712.35";
    if ( x == -6 ) cout<<"-1077.55";
    if ( x == -5 ) cout<<"-622.76";
    if ( x == -4 ) cout<<"-318.00";
    if ( x == -3 ) cout<<"-133.27";
    if ( x == -2 ) cout<<"-38.59";
    if ( x == -1 ) cout<<"-4.00";
    if ( x == -22 ) cout<<"-53235.31";
    if ( x == -21 ) cout<<"-46300.42";
    if ( x == -20 ) cout<<"-39995.53";
    if ( x == -19 ) cout<<"-34290.64";
    if ( x == -18 ) cout<<"-29155.76";
    if ( x == -17 ) cout<<"-24560.88";
    if ( x == -16 ) cout<<"-20476.00";
    if ( x == -15 ) cout<<"-16871.13";
    if ( x == -14 ) cout<<"-13716.26";
    if ( x == -13 ) cout<<"-10981.39";
    if ( x == -12 ) cout<<"-8636.54";
    if ( x == -33 ) cout<<"-179679.26";
    if ( x == -32 ) cout<<"-163834.34";
    if ( x == -31 ) cout<<"-148949.43";
    if ( x == -30 ) cout<<"-134994.52";
    if ( x == -29 ) cout<<"-121939.61";
    if ( x == -28 ) cout<<"-109754.71";
    if ( x == -27 ) cout<<"-98409.80";
    if ( x == -26 ) cout<<"-87874.90";
    if ( x == -25 ) cout<<"-78120.00";
    if ( x == -24 ) cout<<"-69115.10";
    if ( x == -23 ) cout<<"-60830.20";
    if ( x == -44 ) cout<<"-425913.37";
    if ( x == -43 ) cout<<"-397528.44";
    if ( x == -42 ) cout<<"-370433.52";
    if ( x == -41 ) cout<<"-344598.60";
    if ( x == -40 ) cout<<"-319993.68";
    if ( x == -39 ) cout<<"-296588.76";
    if ( x == -38 ) cout<<"-274353.84";
    if ( x == -37 ) cout<<"-253258.92";
    if ( x == -36 ) cout<<"-233274.00";
    if ( x == -35 ) cout<<"-214369.08";
    if ( x == -34 ) cout<<"-196514.17";
    if ( x == -50 ) cout<<"-624992.93";
    if ( x == -49 ) cout<<"-588238.00";
    if ( x == -48 ) cout<<"-552953.07";
    if ( x == -47 ) cout<<"-519108.14";
    if ( x == -46 ) cout<<"-486673.22";
    if ( x == -45 ) cout<<"-455618.29";
    if ( x >= 5) cout<<"MAGNA NIMIS!";cout<<newl;
}
vi v;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1;i<=11;i++){
        int temp; cin>>temp;
        v.pb(temp);
    }

    for(int i=v.size()-1;i>=0;i--) solve(v[i]);
    return 0;
}
