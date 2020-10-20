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

char p[600][600];
int h,w;
bool ans;
bool tam[600][600];
void trueplus(int y, int x){

    for(int i=x;i<=w;i++){
        if(p[y][i]=='*'){tam[y][i]=true;}
        else break;
    }
    for(int i=x;i>=1;i--){
        if(p[y][i]=='*'){tam[y][i]=true;}
        else break;
    }
    for(int i=y;i<=h;i++){
        if(p[i][x]=='*'){tam[i][x]=true;}
        else break;
    }
    for(int i=y;i>=1;i--){
        if(p[i][x]=='*'){tam[i][x]=true;}
        else break;
    }

    ans = true;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(!tam[i][j] && p[i][j]=='*'){ans=false;break;}
        }
    }
}
bool u;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(p[i][j]=='*' && p[i+1][j]=='*'&& p[i-1][j]=='*' && p[i][j+1]=='*' && p[i][j-1]=='*' ){
                trueplus(i,j);
                u = true;
                break;
            }
        }
        if (u)break;
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";

}
