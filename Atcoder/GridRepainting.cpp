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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

int h,w,cwhite;
char square[100][100];
bool vis[100][100];
bool connected(){
    queue < pii > q;
    q.push(mp(1,1));
    while(!q.empty()){
        int r,c;
        r = q.front().fi;
        c = q.front().se;
        q.pop();
        if(!vis[r][c]){
            vis[r][c]=true;
            if(square[r+1][c]=='.'){q.push(mp(r+1,c));}
            if(square[r-1][c]=='.'){q.push(mp(r-1,c));}
            if(square[r][c+1]=='.'){q.push(mp(r,c+1));}
            if(square[r][c-1]=='.'){q.push(mp(r,c-1));}
        }
    }
    if(vis[h][w])return true;
    else return false;
}
int bfs(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            vis[i][j]=false;
        }
    }

    queue < pair < int , pii > > q;
    q.push(mp(0,mp(1,1)));

    int res;
    while(!q.empty()){
        int r = q.front().sf;
        int c = q.front().ss;
        int steps = q.front().fi;
        if(r==h && c==w){res=steps;break;}
        q.pop();
        if(!vis[r][c]){
            vis[r][c]=true;
            if(square[r+1][c]=='.'){q.push(mp(steps+1,mp(r+1,c)));}
            if(square[r-1][c]=='.'){q.push(mp(steps+1,mp(r-1,c)));}
            if(square[r][c+1]=='.'){q.push(mp(steps+1,mp(r,c+1)));}
            if(square[r][c-1]=='.'){q.push(mp(steps+1,mp(r,c-1)));}
        }
    }
    return res-1;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>square[i][j];
            if(square[i][j]=='.')cwhite++;
        }
    }
    cwhite-=2;
    if(connected()){
        int sp = bfs();
        int ans = cwhite-sp;
        ans = max(ans,0);
        cout<<ans<<newl;
    }
    else{cout<<-1<<newl;}
}
