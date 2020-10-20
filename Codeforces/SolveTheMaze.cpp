#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// pragma to turn on excess precision
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
char grid[60][60];
int n,m;
bool vis[60][60];
bool visitable(int r, int c){
    return ( grid[r][c] != '#' && 1<=r && r<=n && 1<=c && c<=m && !vis[r][c]);
}
bool is_good(int r, int c){
    return (1<=r && r<=n && 1<=c && c<=m && grid[r][c]=='G');
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vpii good,bad;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>grid[i][j];
                if(grid[i][j] == 'B') bad.pb(mp(i,j));
                else if(grid[i][j] == 'G') good.pb(mp(i,j));
            }
        }

        if(good.empty()) {
            cout<<"Yes\n";
            continue;
        }

        for(int i=0;i<bad.size();++i){
            pii p = bad[i];
            int r = bad[i].fi;
            int c = bad[i].se;

            if(grid[r+1][c] == '.') grid[r+1][c] = '#';
            if(grid[r-1][c] == '.') grid[r-1][c] = '#';
            if(grid[r][c+1] == '.') grid[r][c+1] = '#';
            if(grid[r][c-1] == '.') grid[r][c-1] = '#';

        }

        queue <pii> q;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                vis[i][j] = false;
                //cout<<grid[i][j];
            }//cout<<newl;
        }
        q.push(mp(n,m));

        bool valid = true;
        while(!q.empty()){
            int r = q.front().fi;
            int c = q.front().se;
            q.pop();

            if(visitable(r,c)){
                vis[r][c] = true;
                q.push(mp(r+1,c));
                q.push(mp(r-1,c));
                q.push(mp(r,c+1));
                q.push(mp(r,c-1));
            }
        }

        for(int i=0;i<good.size();++i){
            int r = good[i].fi;
            int c = good[i].se;
            if(!vis[r][c]){valid = false; break;}
        }
        for(int i=0;i<bad.size();++i){
            int r = bad[i].fi;
            int c = bad[i].se;
            if(is_good(r+1,c)) valid = false;
            if(is_good(r-1,c)) valid = false;
            if(is_good(r,c+1)) valid = false;
            if(is_good(r,c-1)) valid = false;
        }

        if(good.empty()) valid = true;

        if(valid) cout<<"Yes\n";
        else cout<<"No\n";


    }


    return 0;
}
