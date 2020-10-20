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

vi v;
int n,ans;
bool calc[200000];
int memo[200000];
int dp (int x){
    if(x < 0){return 200000;}
    else if(x==0)return 0;
    else if(calc[x])return memo[x];
    else{
        int mn = 200000;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>x){continue;}
            else{
                mn = min (mn, 1 + dp(x-v[i]));
            }
        }
        calc[x]=true;
        memo[x]=mn;
        return mn;
    }
}
int main(){
	//IO();
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int temp = 6;
    v.pb(1);
    while(temp<=100000){
        v.pb(temp);
        temp *= 6;
    }
    temp = 9;
    while(temp<=100000){
        v.pb(temp);
        temp *= 9;
    }

    sort(v.begin(),v.end());
    cin>>n;
    cout<<dp(n)<<newl;

}
