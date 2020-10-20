#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//turn on extra precision
//#pragma GCC target("fpmath=387")

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
#define rall(x) x.rbegin(),x.rend()
#define watch(x) cout << (#x) << " is : " << (x) << newl

vi dirx = {0,0,1,-1};
vi diry = {1,-1,0,0};
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
    if(97 <= int(x) && int(x) <= 122) return int(x-96);
    if(65 <= int(x) && int(x) <= 90) return int(x-64);
    return -1;
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1 = {l1,r1};
    pii p2 = {l2,r2};
    if(p1>p2)swap(p1,p2);
    return (p2.fi <= p1.se);
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
int sur[200],f1[200],f2[200],spec[200];
bool used[200];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector <str> a,b;
    cin >> n;
    for(int i = 0; i < n; ++i){
        str s; cin >> s;
        a.pb(s);
        f1[numerize(s[0])]++;
    }
    for(int i = 0; i < n; ++i){
        str s; cin >> s;
        b.pb(s);
        f2[numerize(s[0])]++;
    }
    sort(all(a));
    sort(all(b));

    for(int i = 1; i <= 26; ++i) spec[i] = min(f1[i],f2[i]);

    for(int i = 0; i < n; ++i){
        int x = numerize(a[i][0]);
        if(spec[x] && f1[x] == spec[x]){
            for(int j = 0; j < n; ++j){
                if(used[j]) continue;
                int y = numerize(b[j][0]);
                if(x == y) {sur[i]=j; used[j]=true; spec[x]--; f2[x]--; spec[x] = max(spec[x],0); break;}
            }
        }
        else{
            for(int j = 0; j < n; ++j){
                if(used[j]) continue;
                int y = numerize(b[j][0]);

                if(spec[y] && y != x){
                    if(f2[y] > spec[y]){
                        sur[i] = j;
                        used[j] = true;
                        f2[y]--;
                        spec[y] = max(spec[y],0);
                        break;
                    }
                }
                else {
                    f2[y]--;
                    used[j] = true;
                    sur[i] = j;
                    if(x==y) spec[y]--;
                    spec[y] = max(spec[y],0);
                    break;
                }
            }
        }
        f1[x]--;

    }


    for(int i = 0; i < n; ++i){
        if(i) cout <<" ";
        cout << a[i] << " " << b[sur[i]];
        if(i == n-1) cout << newl;
        else cout << ",";
    }
    return 0;
}
