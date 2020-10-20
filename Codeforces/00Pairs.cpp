#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <iostream>

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
str add (str a, str b){
    int x = a.size()-1;
    int y = b.size()-1;
    int sis = 0;
    stack<int> s;
    while(x>=0 || y>=0 || sis){
        int d1,d2;
        d1 = 0; d2 = 0;
        if(x>=0){
            d1 = numerize(a[x]);
        }
        if(y>=0){
            d2 = numerize(b[y]);
        }
        int temp = d1+d2+sis;
        s.push(temp%10);
        sis = temp/10;

        x--;y--;
    }
    str res = "";
    while(!s.empty()){
        char c = char(s.top()+48);
        res += c; s.pop();
    }
    return res;
}
str mult (str x, int y){
    if(y==0)return "0";
    stack<int> s;
    int idx = x.size()-1;
    int sis = 0;
    while(idx>=0){
        int d = numerize(x[idx]);
        d *= y; d += sis;
        s.push(d%10);
        sis = d/10;
        idx--;
    }
    if(sis)s.push(sis);

    str res = "";
    while(!s.empty()){
        char c = char(s.top()+48);
        res += c;
        s.pop();
    }
    return res;
}
str multiply (str x, str y){
    str res = "";
    int zer = 0;
    for(int i=y.size()-1;i>=0;i--){
        int d = numerize(y[i]);
        str tmp = mult(x,d);
        if(tmp!="0") for(int j=1;j<=zer;j++)tmp+="0";
        zer++;
        res = add(res,tmp);
    }

    return res;
}
str subtract1(str s){
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] != '0'){
            int d = numerize(s[i]);
            d--; s[i] = (char) (d+48);
            for(int j=i+1;j<s.size();++j) s[j] = '9';
            break;
        }
    }
    str res = "";
    bool ok = false;
    for(int i=0;i<s.size();++i){
        if(s[i] != '0') ok = true;
        if(ok) res += s[i];
    }
    return res;
}
str dp[1010];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = "0";
    for(int i=1;i<=998;++i){
        if(i%2) dp[i+1] = add(multiply(dp[i],"2"),"1");
        else dp[i+1] = subtract1(multiply(dp[i],"2"));
    }

    int n; while(cin>>n) cout<<dp[n]<<newl;
    return 0;
}
