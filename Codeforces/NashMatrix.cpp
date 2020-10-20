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

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 122)return char(x-32);
    if( 65 <= int(x) && int(x) <= 90)return x;
    return -1;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122)return x;
    if( 65 <= int(x) && int(x) <= 90)return char(x+32);
    return -1;
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    if( 97 <= int(x) && int(x) <= 122)return int(x-96);
    if( 65 <= int(x) && int(x) <= 90)return int(x-64);
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
    if(num2==0)return 1;
    else if(num2==1)return num1;
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
int n;
bool blocked[2000][2000];
bool valid = true;
bool vis[2000][2000];
pii grid[2000][2000];
char ans[2000][2000];
pii inf = mp(-1,-1);
void bfsb(int r, int c){
    queue < pair <pii,char> > q;
    q.push(mp(mp(r,c),'X'));
    pii p = mp(r,c);
    while(!q.empty()){
        r = q.front().ff;
        c = q.front().fs;
        char k = q.front().se;
        q.pop();
        if(!vis[r][c]){
            vis[r][c] = true;
            ans[r][c] = k;
            if(grid[r-1][c] == p){q.push(mp(mp(r-1,c),'D'));}
            if(grid[r+1][c] == p){q.push(mp(mp(r+1,c),'U'));}
            if(grid[r][c+1] == p){q.push(mp(mp(r,c+1),'L'));}
            if(grid[r][c-1] == p){q.push(mp(mp(r,c-1),'R'));}
        }
    }
}
void bfsi(int r, int c){
    queue <pii> q;
    q.push(mp(r,c));
    while(!q.empty()){
        r = q.front().fi;
        c = q.front().se;
        q.pop();
        if(!vis[r][c]){
            vis[r][c] = true;
            ans[r][c] = '?';
            if(grid[r+1][c] == inf) q.push(mp(r+1,c)), ans[r][c] = 'D';
            if(grid[r-1][c] == inf) q.push(mp(r-1,c)), ans[r][c] = 'U';
            if(grid[r][c+1] == inf) q.push(mp(r,c+1)), ans[r][c] = 'R';
            if(grid[r][c-1] == inf) q.push(mp(r,c-1)), ans[r][c] = 'L';
        }

    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int r,c; cin>>r>>c;
            grid[i][j] = mp(r,c);
            if(r>0) blocked[r][c] = true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(blocked[i][j]){
                bfsb(i,j);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j] && grid[i][j] == inf) bfsi(i,j);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j] || ans[i][j] == '?') valid = false;
        }
    }

    if(valid){
        cout<<"VALID\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<ans[i][j];
            }cout<<newl;
        }
    }
    else cout<<"INVALID\n";



}
