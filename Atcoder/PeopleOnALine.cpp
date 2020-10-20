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

vpii l[200000],r[200000];
int p[200000],n,m;
bool valid,vis[200000];
void bfs(int x){
    queue <int> q;
    q.push(x);
    p[x] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(!vis[cur]){
            vis[cur] = true;
            for(int i=0;i<r[cur].size();i++){
                int righ,d;
                righ = r[cur][i].fi;
                d = r[cur][i].se;
                if(p[righ]==NULL){
                    p[righ]=p[cur]+d;
                }
                else{
                    if(p[righ]!=p[cur]+d){valid=false;break;}
                }
                q.push(righ);
            }
            for(int i=0;i<l[cur].size();i++){
                int lef,d;
                lef = l[cur][i].fi;
                d = l[cur][i].se;
                if(p[lef]==NULL){
                    p[lef]=p[cur]-d;
                }
                else{
                    if(p[lef]!=p[cur]-d){valid=false;break;}
                }
                q.push(lef);
            }

        }
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int li,ri,d;
        cin>>li>>ri>>d;
        r[li].pb(mp(ri,d));
        l[ri].pb(mp(li,d));
    }
    valid = true;
    for(int i=1;i<=n;i++){
        if(p[i]==NULL){bfs(i);}
        if(!valid)break;
    }
    if(valid)cout<<"Yes\n";
    else cout<<"No\n";

}
