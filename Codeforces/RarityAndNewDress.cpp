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
int dp[5][2010][2010],n,m;
char grid[2010][2010];
void solve(int idx, vi dirx, vi diry){
    if(dirx[0] < 0 || dirx[1] < 0)
        for(int i = 2; i < n; ++i){
            if(diry[0] < 0 || diry[1] < 0)
                for(int j = 2; j < m; ++j){
                    int res = INT_MAX;
                    for(int k = 0; k < dirx.size(); ++k){
                        int nr = i + dirx[k];
                        int nc = j + diry[k];
                        if(grid[nr][nc] != grid[i][j]) {res = 0; break;}
                        res = min(res,dp[idx][nr][nc]);
                    }
                    dp[idx][i][j] = 1 + res;
                }
            else{
                for(int j = m-1; j > 1; --j){
                    int res = INT_MAX;
                    for(int k = 0; k < dirx.size(); ++k){
                        int nr = i + dirx[k];
                        int nc = j + diry[k];
                        if(grid[nr][nc] != grid[i][j]) {res = 0; break;}
                        res = min(res,dp[idx][nr][nc]);
                    }
                    dp[idx][i][j] = 1 + res;
                }
            }
        }
    else
        for(int i = n-1; i > 1; --i){
            if(diry[0] < 0 || diry[1] < 0)
                for(int j = 2; j < m; ++j){
                    int res = INT_MAX;
                    for(int k = 0; k < dirx.size(); ++k){
                        int nr = i + dirx[k];
                        int nc = j + diry[k];
                        if(grid[nr][nc] != grid[i][j]) {res = 0; break;}
                        res = min(res,dp[idx][nr][nc]);
                    }
                    dp[idx][i][j] = 1 + res;
                }
            else{
                for(int j = m-1; j > 1; --j){
                    int res = INT_MAX;
                    for(int k = 0; k < dirx.size(); ++k){
                        int nr = i + dirx[k];
                        int nc = j + diry[k];
                        if(grid[nr][nc] != grid[i][j]) {res = 0; break;}
                        res = min(res,dp[idx][nr][nc]);
                    }
                    dp[idx][i][j] = 1 + res;
                }
            }
        }
}
vi dirx,diry;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j) cin>>grid[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1;j <=m;++j)
            dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 1;

    dirx.clear(); dirx = {1,0};
    diry.clear(); diry = {0,1};
    solve(0,dirx,diry);

    dirx.clear(); dirx = {-1,0};
    diry.clear(); diry = {0,1};
    solve(1,dirx,diry);

    dirx.clear(); dirx = {1,0};
    diry.clear(); diry = {0,-1};
    solve(2,dirx,diry);

    dirx.clear(); dirx = {-1,0};
    diry.clear(); diry = {0,-1};
    solve(3,dirx,diry);

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            ans += min({dp[0][i][j],dp[1][i][j],dp[2][i][j],dp[3][i][j]});

    cout << ans << newl;

    return 0;
}
