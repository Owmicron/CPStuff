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

int lef[2010][2010],righ[2010][2010],up[2010][2010],down[2010][2010];
char s[2010][2010];
int h,w;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>s[i][j];
        }
    }
    // left
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(s[i][j]=='.'){
                if(s[i][j-1]!='.'){lef[i][j]=1;}
                else{lef[i][j]=lef[i][j-1]+1;}
            }
        }
    }
    // right
    for(int i=1;i<=h;i++){
        for(int j=w;j>=1;j--){
            if(s[i][j]=='.'){
                if(s[i][j+1]!='.'){righ[i][j]=1;}
                else{righ[i][j]=righ[i][j+1]+1;}
            }
        }
    }
    // up
    for(int j=1;j<=w;j++){
        for(int i=1;i<=h;i++){
            if(s[i][j]=='.'){
                if(s[i-1][j]!='.'){up[i][j]=1;}
                else{up[i][j]=up[i-1][j]+1;}
            }
        }
    }
    //down
    for(int j=1;j<=w;j++){
        for(int i=h;i>=1;i--){
            if(s[i][j]=='.'){
                if(s[i+1][j]!='.'){down[i][j]=1;}
                else{down[i][j]=down[i+1][j]+1;}
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(s[i][j]=='.'){
                int res = 1 + lef[i][j-1] + righ[i][j+1] + up[i-1][j] + down[i+1][j];
                ans = max(ans,res);
            }
        }
    }
    cout<<ans<<newl;
}
