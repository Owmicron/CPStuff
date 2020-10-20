#include<bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
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
ll fexp (ll num1, ll num2, ll MOD){
    if(num2==0)return 1;
    else if(num2==1)return num1;
    else{
        ll temp = fexp (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return fexp (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/gcd(num1,num2))*num2;}
// end of Template

map <ll,ll> f;
int n;
ll a[8000],b[8000],score;
vll safe;
bool stronger(ll safer, ll x){
//    queue <ll> qs,q;
//    while(safer>0){
//        if(safer%2==1)qs.push(1);
//        else qs.push(0);
//        safer/=2;
//    }
//    while(x>0){
//        if(x%2==1)q.push(1);
//        else q.push(0);
//        x/=2;
//    }
//
//    int idx = 0;
//    bool valid=true;
//    while(idx<=60){
//        int aa,bb;
//        if(!qs.empty()){aa=qs.front();qs.pop();}
//        else aa=0;
//
//        if(!q.empty()){bb=q.front();q.pop();}
//        else bb=0;
//
//        if(bb==1 && aa==0){
//            valid = false;break;
//        }
//        idx++;
//
//        if(qs.empty() && q.empty())break;
//    }
//    return valid;

    ll c = safer ^ x;
    if(x+c == safer)return true;
    else return false;
}
bool aman[8000];
pll data[8000];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    data[0].fi = -1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        data[i] = mp(a[i],b[i]);
    }
    sort(data+1,data+1+n);

    for(int i=1;i<=n;i++){
        if(data[i].fi == data[i-1].fi){
            aman[i] = true;
            aman[i-1] = true;
        }
    }

//    for(int i=1;i<=n;i++){
//        f[a[i]]++;
//        if(f[a[i]]==2){
//            safe.pb(a[i]);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        if(f[a[i]]>1)score+=b[i];
//    }

    for(int i=1;i<=n;i++){
        if(aman[i]){
            score+=data[i].se;
            if(data[i].fi!=data[i-1].fi)safe.pb(data[i].fi);
        }
    }

    for(int i=1;i<=n;i++){
        if(!aman[i]){
            for(int j=0;j<safe.size();j++){
                if(stronger(safe[j],data[i].fi)){
                    score+=data[i].se;
                    break;
                }
            }
        }
    }
    cout<<score<<newl;
}
