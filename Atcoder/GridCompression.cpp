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
typedef set <int> si;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newline '\n'
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
int h,w;
char grid[200][200];
bool invr[200],invc[200];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     cin>>h>>w;
     for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
             cin>>grid[i][j];
         }
     }

     for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
             if(grid[i][j]=='#'){
                invr[i]=true;
                invc[j]=true;
             }
         }
     }

     for(int i=1;i<=h;i++){
        bool have = false;
        for(int j=1;j<=w;j++){
            if(invr[i]&&invc[j]){cout<<grid[i][j];have=true;}
            else continue;
        }
        if(have)cout<<newline;
     }
}
