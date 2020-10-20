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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

str s;
ll md = 1000000007;
ll dp[100010][5];
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    s = " "+s;
    dp[0][0] = 1;

    for(int i=1;i<s.size();i++){
        if(s[i]=='?'){
            for(int j=0;j<=3;j++) dp[i][j] = ((dp[i-1][j] % md) * (3 % md)) % md;

        }
        else{
            for(int j=0;j<=3;j++) dp[i][j]=dp[i-1][j];
        }

        if(s[i]=='A' || s[i]=='?'){
            dp[i][1] = ((dp[i][1]%md) + (dp[i-1][0]%md)) % md;
        }
        if(s[i]=='B' || s[i]=='?'){
            dp[i][2] = ((dp[i][2]%md) + (dp[i-1][1]%md)) % md;
        }
        if(s[i]=='C' || s[i]=='?'){
            dp[i][3] = ((dp[i][3]%md) + (dp[i-1][2]%md)) % md;
        }
    }
    cout<<dp[s.size()-1][3]<<newl;

}

