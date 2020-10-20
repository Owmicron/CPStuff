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

int n;
vector<int> depth[200000],adj[200000];
bool vis[200000];
int num[200000],dx,verdict,ans;
void as(){
    int d = 1;
    queue <int> q;
    for(int i=0;i<adj[1].size();i++){
        q.push(adj[1][i]);
        num[adj[1][i]]=d;
    }
    vis[1]=true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node]=true;
            int dalam = num[node];
            depth[dalam].pb(node);
            for(int i=0;i<adj[node].size();i++){
                int nex = adj[node][i];
                if(!vis[nex]){
                    q.push(nex);
                    num[nex] = dalam+1;
                }
            }
        }
    }
}
bool found;
int main(){
	//IO();
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    as();
//
//    for(int i=1;i<=n;i++)cout<<num[i]<<newl;cout<<newl;
//    for(int i=1;i<=5;i++){
//        cout<<i<<" ";
//        for(int j=0;j<depth[i].size();j++)cout<<depth[i][j]<<" ";cout<<newl;
//    }

    cout<<"d "<<1<<newl;
    fflush(stdout);
    cin>>verdict;
    dx = verdict;
    if(dx == 0){
        ans = 1;
    }
    else if(dx==1){
        cout<<"s "<<1<<newl;
        fflush(stdout);
        cin>>verdict;
        ans = verdict;
    }
    else{
        int cur = 1;
        found=false;

        while(!found){
            int par = cur;
            for(int i=0;i<adj[par].size();i++){
                int now = adj[par][i];
//                cout<<"current "<<dx-1<<" "<<par<<" "<<num[now]<<newl;
                if(adj[cur].size()==2 && num[par]<dx-2){
                    for(int j=0;j<adj[cur].size();j++){

                        int nn = adj[cur][j];
//                        cout<<par<<" "<<nn<<" "<<"here"<<newl;
//                        cout<<num[par]<<" "<<num[nn]<<newl;

                        if(num[nn]<num[par]){continue;}
                        else {cur = nn; break;}
                    }
                    break;
                }

                if(num[now]<num[par])continue;
                int dn = num [now];
                int ex = dx-dn;
                cout<<"d "<<now<<newl;
                fflush(stdout);
                cin>>verdict;
                if(verdict==ex){
                    if(ex == 1){
                        cout<<"s "<<now<<newl;
                        fflush(stdout);
                        cin>>verdict;
                        ans=verdict;
                        found=true;
                        break;
                    }
                    else{
                        cur = now;
                        break;
                    }

                }
                else continue;


            }
        }
    }
    cout<<"! "<<ans<<newl;
    fflush(stdout);

}
