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
int d[210][210],t,n,c[210][210];
vi v[210];
bool ada[210][210];
bool num[210];
int count_col(int idx){
    int res = 0;
    for(int i=0;i<v[idx].size();++i){
        if(num[v[idx][i]]) res++;
    }
    return res;
}
bool test(int idx, bool rev){
    vi ans;

    if(!rev)ans.pb(v[idx][0]);
    ans.pb(v[idx][1]);
    if(rev)ans.pb(v[idx][0]);

    bool used[210];
    for(int i=1;i<=n;i++) used[i] = false, num[i] = false;
    used[idx] = true;
    num[ans[0]] = true;
    num[ans[1]] = true;

    //for(int i=0;i<ans.size();++i) cout<<ans[i]<<" - "; cout<<newl;

    for(int maxlen=3;maxlen<=n;++maxlen){
        int maxcol = 0;
        int curlen = 0;
        int nexidx = 0;
        //watch(maxlen);
        for(int i=1;i<n;i++){
            if(v[i].size()<=maxlen && !used[i]){
                int fresh = 0;
                for(int j=0;j<v[i].size();j++){
                    if(!num[v[i][j]]) ++fresh;
                }
                if(fresh > 1) continue;
                int col = count_col(i);
                if(col > maxcol){
                    nexidx = i;
                    maxcol = col;
                    curlen = v[i].size();
                }
                else if(col == maxcol && v[i].size() < curlen){
                    nexidx = i;
                    curlen = v[i].size();
                }
            }
        }

        used[nexidx] = true;
        if(maxcol == 0) return false;
        for(int i=0;i<v[nexidx].size();i++){
            if(!num[v[nexidx][i]]){
                num[v[nexidx][i]] = true;
                ans.pb(v[nexidx][i]);
                break;
            }
        }
    }
//    validate;
//    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<newl;

    for(int i=0;i<ans.size();++i){
        for(int j=i+1;j<ans.size();++j){
            int a = ans[i];
            int b = ans[j];
            if(a > b) swap(a,b);
            int dist = abs(i-j);
//            cout<<d[a][b]<<" "<<a<<" - "<<b<<newl;
            if(dist > d[a][b]) return false;
        }
    }
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" ";cout<<newl;
    return true;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        v[i].clear();
        for(int j=1;j<=n;j++){
            ada[i][j] = false;
            d[i][j] = INT_MAX;
        }
    }

    for(int i=1;i<n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int temp; cin>>temp;
            v[i].pb(temp);
            ada[temp][i] = true;
        }
        for(int j=0;j<v[i].size();j++){
            for(k=j+1;k<v[i].size();k++){
                int a = v[i][j];
                int b = v[i][k];

                if(a > b) swap(a,b);
                d[a][b] = min(d[a][b],(int)v[i].size()-1);
            }
        }
    }


    for(int i=1;i<n;i++){
        if(v[i].size()==2){
            if(test(i,true)) return;
            if(test(i,false)) return;
        }
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t; while(t--){
        solve();
    }
    return 0;
}
