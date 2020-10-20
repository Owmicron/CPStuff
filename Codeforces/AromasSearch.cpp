#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define vanessa using
#define ratana namespace
#define yoe std
vanessa ratana yoe;
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
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 122)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
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
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template

typedef unsigned long long ull;
vector< pair<ull,ull> > v;
ull x,y,ax,ay,bx,by,t,xs,ys,ans;
ull eat(ull x1, ull y1, ull x2, ull y2){
    ull res = 0;
//    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<newl;
    for(int i=0;i<v.size();i++){
        ull X,Y;
        X = v[i].fi; Y = v[i].se;
//        cout<<X<<" "<<Y<<" --- ";
        if(x1 <= X && X <= x2 && y1 <= Y && Y <= y2) res++;
//        cout<<res<<newl;
    }
    return res;
}
ull subs(ull A, ull B){
    ull res;
    if(A >= B) return A-B;
    else return B-A;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>x>>y>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    v.pb(mp(x,y));

    x = x*ax + bx;
    y = y*ay + by;
    while(x<=2e16 && y<=2e16){
        v.pb(mp(x,y));
        x = x*ax + bx;
        y = y*ay + by;
    }

    for(int i=0;i<v.size();i++){
        ull temp = subs(v[i].fi, xs) + subs(v[i].se , ys);
        if(temp<=t){
            ans = max(ans , eat(min(v[i].fi,xs),min(v[i].se,ys),max(v[i].fi,xs),max(v[i].se,ys)));
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            ull d1 = subs(v[i].fi , xs) + subs(v[i].se , ys) + subs(v[i].fi , v[j].fi) + subs(v[i].se , v[j].se);
            ull d2 = subs(xs , v[j].fi) + subs(ys , v[j].se) + subs(v[j].fi , v[i].fi) + subs(v[j].se , v[i].se);
            ull d = min(d1 ,d2);

            if(d<=t){
                ull mx = xs; mx = min(mx, v[i].fi); mx = min(mx, v[j].fi);
                ull my = ys; my = min(my, v[i].se); my = min(my,v[j].se);
                ull MX = xs; MX = max(MX, v[i].fi); MX = max(MX, v[j].fi);
                ull MY = ys; MY = max(MY, v[i].se); MY = max(MY,v[j].se);
                ans = max(ans, eat(mx,my,MX,MY));

//                cout<<i<<" "<<j<<" "<<ans<<newl;
            }

        }
    }
    cout<<ans<<newl;
}
