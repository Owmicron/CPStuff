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

ll dp[100010][14],sep;
ll md = 1e9+7;
str s;
int n;
int main(){

//    freopen("input.txt", "r", stdin);0
//    freopen("output.txt", "w", stdout);

    cin>>s; n = s.size();
    s = " "+s;

    if(s[n]=='?'){for(int i=0;i<=9;i++)dp[n][i]=1;}
    else dp[n][numerize(s[n])]=1;

    sep = 1;
    for(int i=n-1;i>0;i--){
        int st,en;
        if(s[i]=='?'){st=0;en=9;}
        else{st=numerize(s[i]);en=numerize(s[i]);}
        sep = (sep*10)%13;
        for(int j=st;j<=en;j++){
            ll temp = (sep*j)%13;
            for(int k=0;k<13;k++){
                ll res = (temp+k)%13;
                dp[i][res] = ((dp[i][res]%md) + (dp[i+1][k]%md))%md;
            }
        }
    }
    cout<<dp[1][5]<<newl;

}
