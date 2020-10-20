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
#define all(x) x.begin(), x.end()
#define watch(x) cout << (#x) << " == " << (x) << newl

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
vector < vi > v;
char s[20][20];
int memo[10];
int cnt[4][4];
void prec(int depth){
    if(depth <= 9){
        for(int i=1;i<=3;i++){
            int block = depth/3;
            if(depth%3) ++block;

            //cnt[block][i]++;
            bool valid = true;
            memo[depth] = i;
            for(int j = depth-3; j>0; j-=3){
                if(memo[depth] == memo[j]) valid = false;
            }
            if(depth>3 && memo[depth] == memo[depth-3]) valid = false;
            //if(cnt[block][i] > 1) valid = false;

            if(valid){
                if(depth == 9){
                    vi temp;
                    for(int i=1;i<=9;i++) temp.pb(memo[i]);
                    v.pb(temp);
                }
                else prec(depth+1);
            }
            //cnt[block][i]--;
        }
    }
}
bool valid (vi temp){
    for(int i = 0; i < temp.size(); i++){
        int r,c;
        r = (i%3)*3 + temp[i];
        c = i+1;
        if(s[r][c] == '1') return false;
    }
    return true;
}
void solve(vi temp){
    for(int i = 0; i < temp.size(); i++){
        int r,c;
        r = (i%3)*3 + temp[i];
        c = i+1;
        s[r][c] = '1';
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    prec(1);
//    for(int i=0;i<v.size();i++){
//        vi temp = v[i];
//        for(int j=0;j<temp.size();j++) cout<<temp[j]<<" ";cout<<newl;
//    }

    int t; cin>>t;
    while(t--){
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                cin>>s[i][j];
            }
        }
        for(int i=0;i<v.size();i++){
            if(valid(v[i])){
                solve(v[i]);
                break;
            }
        }

        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                cout<<s[i][j];
            }cout<<newl;
        }
    }

    return 0;
}
