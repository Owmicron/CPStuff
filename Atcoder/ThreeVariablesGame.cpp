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
int n;
str s[100100];
ll a[100010],b[100001],c[100010];
char ans[100010];
vector <int> save;
bool tried[100010];
bool valid = true;
void solve(){
    for(int i=1;i<=n;i++){
        a[i] = a[i-1];
        b[i] = b[i-1];
        c[i] = c[i-1];
        if(s[i] == "AB"){
            if(a[i] < b[i]) a[i]++, b[i]--, ans[i] = 'A';
            else if(a[i] > b[i]) a[i] --, b[i]++, ans[i] = 'B';
            else{
                if(a[i] == 0 && b[i] == 0){
                    valid = false; break;
                }
                int cnt = 1;
                bool found = false;
                int idx = -1;
                for(int j=i+1;j<=n;j++){
                    if(s[j] != s[i]){
                        found = true;
                        idx = j;
                        break;
                    }
                    else cnt++;
                }
                if(cnt%2 == 0 || !found){
                    if(idx == -1) idx = n+1;
                    for(int j=i;j<idx;j++){
                        a[j] = a[j-1];
                        b[j] = b[j-1];
                        c[j] = c[j-1];
                        if(a[j] <= b[j]) a[j]++, b[j]--, ans[j] = 'A';
                        else a[j]--,b[j]++,ans[j] = 'B';
                    }
                    i = idx-1;
                }
                else{
                    for(int j=i;j<idx;j++){
                        a[j] = a[j-1];
                        b[j] = b[j-1];
                        c[j] = c[j-1];
                        if(a[j] < b[j]) a[j]++, b[j]--, ans[j] = 'A';
                        else if(a[j] > b[j])a[j]--,b[j]++,ans[j] = 'B';
                        else if(s[idx] == "AC") a[j]++, b[j]--, ans[j] = 'A';
                        else a[j]--,b[j]++,ans[j] = 'B';
                    }
                    i = idx-1;
                }
            }
        }
        else if(s[i] == "AC"){
            if(a[i] < c[i]) a[i]++, c[i]--, ans[i] = 'A';
            else if(a[i] > c[i]) a[i] --, c[i]++, ans[i] = 'C';
            else{
                if(a[i] == 0 && c[i] == 0){
                    valid = false; break;
                }
                int cnt = 1;
                bool found = false;
                int idx = -1;
                for(int j=i+1;j<=n;j++){
                    if(s[j] != s[i]){
                        found = true;
                        idx = j;
                        break;
                    }
                    else cnt++;
                }
                if(cnt%2 == 0 || !found){
                    if(idx == -1) idx = n+1;
                    for(int j=i;j<idx;j++){
                        a[j] = a[j-1];
                        c[j] = b[j-1];
                        c[j] = c[j-1];
                        if(a[j] <= c[j]) a[j]++, c[j]--, ans[j] = 'A';
                        else a[j]--,c[j]++,ans[j] = 'C';
                    }
                    i = idx-1;
                }
                else{
                    for(int j=i;j<idx;j++){
                        a[j] = a[j-1];
                        c[j] = b[j-1];
                        c[j] = c[j-1];
                        if(a[j] < c[j]) a[j]++, c[j]--, ans[j] = 'A';
                        else if(a[j] > c[j])a[j]--,c[j]++,ans[j] = 'C';
                        else if(s[idx] == "AB") a[j]++, c[j]--, ans[j] = 'A';
                        else a[j]--,c[j]++,ans[j] = 'C';
                    }
                    i = idx-1;
                }
            }
        }
        else if(s[i] == "BC"){
            if(b[i] < c[i]) b[i]++, c[i]--, ans[i] = 'B';
            else if(b[i] > c[i]) b[i] --, c[i]++, ans[i] = 'C';
            else{
                if(b[i] == 0 && c[i] == 0){
                    valid = false; break;
                }
                int cnt = 1;
                bool found = false;
                int idx = -1;
                for(int j=i+1;j<=n;j++){
                    if(s[j] != s[i]){
                        found = true;
                        idx = j;
                        break;
                    }
                    else cnt++;
                }
                if(cnt%2 == 0 || !found){
                    if(idx == -1) idx = n+1;
                    for(int j=i;j<idx;j++){
                        b[j] = a[j-1];
                        c[j] = b[j-1];
                        c[j] = c[j-1];
                        if(b[j] <= c[j]) b[j]++, c[j]--, ans[j] = 'B';
                        else b[j]--,c[j]++,ans[j] = 'C';
                    }
                    i = idx-1;
                }
                else{
                    for(int j=i;j<idx;j++){
                        b[j] = a[j-1];
                        c[j] = b[j-1];
                        c[j] = c[j-1];
                        if(b[j] < c[j]) b[j]++, c[j]--, ans[j] = 'B';
                        else if(b[j] > c[j])b[j]--,c[j]++,ans[j] = 'C';
                        else if(s[idx] == "AB") b[j]++, c[j]--, ans[j] = 'B';
                        else b[j]--,c[j]++,ans[j] = 'C';
                    }
                    i = idx-1;
                }
            }
        }




    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>a[0]>>b[0]>>c[0];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }

    solve();
    if(valid){
        cout<<"Yes\n";
        for(int i=1;i<=n;i++) cout<<ans[i]<<newl;
    }
    else cout<<"No\n";
    return 0;
}
