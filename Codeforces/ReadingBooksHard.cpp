#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//turn on excess precision
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
int n,m,k,t[200010],con[200010];
set <pii> sing,trash;
priority_queue <pair<int,pii> > doub;
priority_queue <pii> alice,bob;
ll sc,dc,tc;

void solve(int solver){
    priority_queue <pii> x,z;
    priority_queue <pair <int,pii> > y;

    for(int i=1;i<=n;++i){
        int a,b;
        if(con[i] == 0) a = 0, b = 0;
        if(con[i] == 1) a = 1, b = 0;
        if(con[i] == 2) a = 0, b = 1;
        if(con[i] == 3) a = 1, b = 1;

        if(a && b) x.push({-t[i],i});
        else if(a) alice.push({-t[i],i}), con[i] = 1;
        else if(b) bob.push({-t[i],i}), con[i] = 2;
        else z.push({-t[i],i});
    }

    while(alice.size() && bob.size()){
        pii a = alice.top();
        pii b = bob.top();
        alice.pop();
        bob.pop();
        a.fi *= -1;
        b.fi *= -1;
        int val = a.fi + b.fi;
        y.push(mp(-val,mp(a.se,b.se)));
    }

    while(alice.size()) z.push(alice.top()) , alice.pop();
    while(bob.size()) z.push(bob.top()), bob.pop();

    int a = solver;
    int b = k - solver;
    int books = 2*solver + (k-solver);
    int rem = m - books;


    vi ans;
    while(a--){
        int p1 = y.top().sf;
        int p2 = y.top().ss;
        y.pop();
        ans.pb(p1);
        ans.pb(p2);
    }

    while(!y.empty()){
        int p1 = y.top().sf;
        int p2 = y.top().ss;
        y.pop();
        pii z1 = {-t[p1],p1};
        pii z2 = {-t[p2],p2};
        z.push(z1);
        z.push(z2);
    }
    while(b--){
        ans.pb(x.top().se);
        x.pop();
    }
    while(!x.empty()){
        z.push(x.top());
        x.pop();
    }

    while(rem--){
        ans.pb(z.top().se);
        z.pop();
    }

    for(auto i : ans) cout<<i<<" ";cout<<newl;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        int a,b;
        cin>>t[i]>>a>>b;

        if(a && b) sing.insert({t[i],i}), sc += t[i], con[i] = 3;
        else if(a) alice.push({-t[i],i}), con[i] = 1;
        else if(b) bob.push({-t[i],i}), con[i] = 2;
        else con[i] = 0, trash.insert({t[i],i}), tc += t[i];
    }

    while(alice.size() && bob.size()){
        pii a = alice.top(); a.fi *= -1;
        pii b = bob.top(); b.fi *= -1;
        alice.pop(); bob.pop();
        int val = a.fi + b.fi;
        doub.push(mp(-val,mp(a.se,b.se)));
        trash.insert(a); tc += a.fi;
        trash.insert(b); tc += b.fi;
    }

    while(alice.size()){
        pii p = alice.top();
        alice.pop();
        p.fi *= -1;

        trash.insert(p);
        tc += p.fi;
    }

    while(bob.size()){
        pii p = bob.top();
        bob.pop();
        p.fi *= -1;

        trash.insert(p);
        tc += p.fi;
    }
    ll ans = 1e18;
    int solver = -1;

    for(int i = 0; i <= k; ++i){
        int books = 2*i + (k-i);
        int rem = m - books;

        while(sing.size() > k - i){
            auto ritr = sing.rbegin();
            pii p = *ritr;
            sc -= p.fi;
            tc += p.fi;
            trash.insert(p);
            sing.erase(p);
        }

        while(trash.size() > max(rem,0)){
            auto ritr = trash.rbegin();
            pii p = *ritr;
            tc -= p.fi;
            trash.erase(p);
        }

        bool valid = true;
        if(trash.size() < rem) valid = false;
        if(sing.size() < k-i) valid = false;

        if(valid){
            ll temp = sc + tc + dc;
            if(temp < ans) ans = temp, solver = i;
        }
        if(doub.empty()) break;

        auto p = doub.top();
        doub.pop();
        p.fi *= -1;
        dc += p.fi;

        int idx = p.sf;
        pii z = {t[idx],idx};
        if(trash.count(z)){
            tc -= z.fi;
            trash.erase(z);
        }

        idx = p.ss;
        z = {t[idx],idx};
        if(trash.count(z)){
            tc -= z.fi;
            trash.erase(z);
        }
    }

    if(ans == 1e18) cout<<-1<<newl;
    else{
        cout<<ans<<newl;
        solve(solver);
    }
    return 0;
}
