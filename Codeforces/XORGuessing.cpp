#include<bits/stdc++.h>

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
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
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
vll even,odd;
ll ans[30],verdict,dua[30],a;
void trans(ll x, int m){
    queue <ll> q;
    while(x>0){
        q.push(x);
        x/=2;
    }
    int idx=0;
    while(!q.empty()){
        idx ++;
        if(idx%2==m){
            ans[idx] = q.front()%2;
        }
        q.pop();
    }
}
bool valid_even(ll x){
    queue <ll> s;
    while(x>0){
        s.push(x);
        x/=2;
    }
    bool valid = true;
    int idx = 0;
    while(!s.empty()){
        idx++;
        if(idx%2==0 && s.front()%2!=0){valid=false;}
        s.pop();
    }
    return valid;
}
bool valid_odd(ll x){
    queue <ll> z;
    while(x>0){
        z.push(x);
        x/=2;
    }
    bool valid = true;
    int idx = 0;
    while(!z.empty()){
        idx++;
        if(idx%2==1 && z.front()%2!=0){valid=false;}
        z.pop();
    }
    return valid;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    dua[0] = 1;
    for(int i=1;i<=20;i++)dua[i] = dua[i-1]*2;
    for(int i=0;i<=20000;i++){
        if(valid_even(i))even.pb(i);
        if(even.size()==100)break;
    }
    for(int i=1;i<=20000;i++){
        if(valid_odd(i))odd.pb(i);
        if(odd.size()==100)break;
    }
    cout<<"? ";
    for(int i=0;i<even.size();i++)cout<<even[i]<<" ";cout<<newl;
    fflush(stdout);
    cin>>verdict;trans(verdict,0);

    cout<<"? ";
    for(int i=0;i<odd.size();i++)cout<<odd[i]<<" ";cout<<newl;
    fflush(stdout);
    cin>>verdict;trans(verdict,1);

    for(int i=1;i<=15;i++){
        a += dua[i-1] * ans[i];
    }
    cout<<"! "<<a<<newl;
    fflush(stdout);

}
