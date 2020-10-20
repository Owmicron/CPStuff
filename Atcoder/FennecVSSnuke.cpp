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
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll fexp (ll num1, ll num2, ll MOD){
    if(num2==0)return 1;
    else if(num2==1)return num1;
    else{
        ll temp = fexp (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return fexp (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/gcd(num1,num2))*num2;}


// end of Template
int n,b,w,bw;
vi adj[100010];
bool visb[100010];
bool visw[100010];
void bfs(){
    queue <pii> qb,qw;
    qb.push(mp(1,0));
    qw.push(mp(n,0));

    bool moving = true;
    while(moving){
        moving = false;

        int cur = qb.front().se;
        while(!qb.empty()){
            moving = true;
            int node = qb.front().fi;
            int steps = qb.front().se;

            //cout<<"BLAC "<<node<<" "<<steps<<newl;
            if(steps>cur)break;
            else{
                qb.pop();

                visb[node]=true;
                for(int i=0;i<adj[node].size();i++){
                    int nex = adj[node][i];
                    //cout<<"blacknex : "<<node<<" "<<nex<<newl;
                    if(!visb[nex] && !visw[nex] && nex != n){
                        //cout<<"OK\n";
                        visb[nex]=true;
                        qb.push(mp(nex,steps+1));
                    }
                }
            }
        }

        cur = qw.front().se;
        while(!qw.empty()){
            moving = true;
            int node = qw.front().fi;
            int steps = qw.front().se;

            //cout<<"WHIT "<<node<<" "<<steps<<newl;
            if(steps>cur)break;
            else{
                qw.pop();

                visw[node]=true;
                for(int i=0;i<adj[node].size();i++){
                    int nex = adj[node][i];
                    if(!visb[nex] && !visw[nex] && nex != 1){
                        qw.push(mp(nex,steps+1));
                        visw[nex]=true;
                    }
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
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bfs();
    for(int i=1;i<=n;i++){
        if(visb[i]){b++;}
        else if(visw[i]){w++;}
    }
    if(b>w)cout<<"Fennec\n";
    else cout<<"Snuke\n";
}
