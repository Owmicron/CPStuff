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
ll n,k,p[300000],disc[300000],x,a,y,b;
priority_queue <ll> temp;
ll can (ll z){
    priority_queue <ll> q;
    q = temp;
    ll A,B,C;
    A = 0;
    B = 0;
    C = 0;

    for(int i=1;i<=z;i++){
        if(disc[i]==(x+y)) A++;
        else if(disc[i]==(y))B++;
        else if(disc[i]==(x))C++;

    }

    ll res = 0;
    while(A>0 && !q.empty()){
        A--;
        res += (q.top()/100) * (x+y);
        q.pop();
    }

    while(B>0 && !q.empty()){
        B--;
        res += (q.top()/100) * y;
        q.pop();
    }

    while(C>0 && !q.empty()){
        C--;
        res += (q.top()/100) * x;
        q.pop();
    }

    if(res>=k) return true;
    else return false;

}

ll bins(){
    ll l = 1;
    ll r = n;
    ll res = -1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(can(mid)){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>n;
        for(int i=1;i<=n;i++) disc[i] = 0;
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            temp.push(p[i]);
        }
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;

        if(x>y){
            swap(x,y);
            swap(a,b);
        }

        for(int i=a;i<=n;i+=a) disc[i]+=x;
        for(int i=b;i<=n;i+=b) disc[i]+=y;

        cout<<bins()<<newl;

        while(!temp.empty()) temp.pop();


    }

}
