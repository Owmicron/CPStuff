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
int n;
deque<char> d;
str s,t;
map <char,int> f;
bool valid1 (str x){
    bool can = true;
    str temp;
    temp = x[0]; temp+= x[1]; if(temp==s || temp==t)return false;
    temp = x[1]; temp+= x[2]; if(temp==s || temp==t)return false;
    if(n>1){
        temp = x[2]; temp+= x[0];
        if(temp==s || temp==t)return false;
    }
    return true;
}
bool valid2(str x){
    if(n<2)return false;
    str temp;
    temp = x[0]; temp+= x[0]; if(temp==s || temp==t)return false;
    temp = x[0]; temp+= x[1]; if(temp==s || temp==t)return false;
    temp = x[1]; temp+= x[1]; if(temp==s || temp==t)return false;
    temp = x[1]; temp+= x[2]; if(temp==s || temp==t)return false;
    temp = x[2]; temp+= x[2]; if(temp==s || temp==t)return false;
    return true;
}
str t1 (str x){
    str res = "";
    for(int i=1;i<=n;i++)res+=x;
    return res;
}
str t2 (str x){
    str res = "";
    for(int i=1;i<=n;i++)res+=x[0];
    for(int i=1;i<=n;i++)res+=x[1];
    for(int i=1;i<=n;i++)res+=x[2];
    return res;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    cin>>n;
    cin>>s>>t;
    cout<<"YES\n";
    if(valid1 ("abc") ){cout<<t1("abc");}
    else if(valid2 ("abc") ){cout<<t2("abc");}
    else if(valid1 ("acb") ){cout<<t1("acb");}
    else if(valid2 ("acb") ){cout<<t2("acb");}
    else if(valid1 ("bac") ){cout<<t1("bac");}
    else if(valid2 ("bac") ){cout<<t2("bac");}
    else if(valid1 ("bca") ){cout<<t1("bca");}
    else if(valid2 ("bca") ){cout<<t2("bca");}
    else if(valid1 ("cab") ){cout<<t1("cab");}
    else if(valid2 ("cab") ){cout<<t2("cab");}
    else if(valid1 ("cba") ){cout<<t1("cba");}
    else if(valid2 ("cba") ){cout<<t2("cba");}

}
