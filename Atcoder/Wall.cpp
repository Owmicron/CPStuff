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

int h,w,c[20][20],a[300][300];
bool vis[20];
ll dist[20][20],ans;
void dijkstra(int start){
    for(int i=0;i<=9;i++)vis[i]=false;
    for(int i=0;i<=9;i++){
        dist[start][i] = INT_MAX;
    }
    dist[start][start] = 0;
    priority_queue < pii > q;
    q.push (mp (0,start) );

    while(!q.empty()){
        int node = q.top().se;
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            for(int nex = 0; nex < 10 ; nex ++){
                if(dist[start][nex] > dist[start][node] + c[node][nex]){
                    dist[start][nex] = dist[start][node] + c[node][nex];
                    q.push (mp (-1 * dist[start][nex],nex) );
                }

            }
        }

    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0; i<=9; i++){
        dijkstra(i);
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
            if(a[i][j]>=0)ans += dist[a[i][j]][1];
        }
    }
    cout<<ans<<newl;

}
