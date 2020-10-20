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
// end of Template

ll memo[2000][2000][6];
bool calc[2000][2000][6];
int w,h;
ll md = 998244353 ;

ll dp (ll r, ll c, ll type){
    if(calc[r][c][type])return memo[r][c][type];
    else{
        ll ka,ba;
        if(c == w){ka=1;}
        else{
            if(type==1 || type == 2){
                ll x = dp(r,c+1,1);
                ll y = dp(r,c+1,2);
                ka = ((x%md) * (y%md))%md;
            }
            else if(type==3 || type==4){
                ll x = dp(r,c+1,3);
                ll y = dp(r,c+1,4);
                ka = ((x%md) * (y%md))%md;
            }
        }

        if(r == h){ba=1;}
        else{
            if(type==1 || type==4){
                ll x = dp(r+1,c,1);
                ll y = dp(r+1,c,4);
                ba = ((x%md) * (y%md))%md;
            }
            else if(type==3 || type==2){
                ll x = dp(r+1,c,2);
                ll y = dp(r+1,c,3);
                ba = ((x%md) * (y%md))%md;
            }
        }

        ll res = ((ka%md)*(ba%md))%md;
        calc[r][c][type]=true;
        memo[r][c][type]=res;
        return res;

    }


}

int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    swap(h,w);

    ll ans = 0;
    for(int i=1;i<=4;i++){
        ans = ((ans%md) + ((dp(1,1,i))%md))%md;
    }
    cout<<ans<<newl;

}
