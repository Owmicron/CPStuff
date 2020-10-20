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

int n,m,num[20],p[20],sw[20][20];
vector <int> adj[20];
int f;
int deep[20],bulb[20];
void choose (int start, int d, int k){
    if(d<=k){
        for(int i=start;i<=n-(k-d);i++){
            deep[d]=i;
            if(d<k){choose(i+1,d+1,k);}
            else{
                for(int j=1;j<=n;j++){
                    bulb[j]=0;
                }
                for(int j=1;j<=k;j++){
                    for(int l=0;l<adj[deep[j]].size();l++){
                        int idx = adj[deep[j]][l];
                        bulb[idx]++;
                    }
                }
                int m2=0;
                for(int j=1;j<=n;j++){
                    if(bulb[j]%2==p[j]%2){m2++;}
                }
                if(m2==n){f++;}
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
        cin>>num[i];
        for(int j=1;j<=num[i];j++){
            cin>>sw[i][j];
            adj[sw[i][j]].pb(i);
        }
    }
    for(int i=1;i<=m;i++)cin>>p[i];
    bool zero = true;
    for(int i=1;i<=m;i++){
        if(p[i]==1){zero=false;break;}
    }
    if(zero)f++;

//    for(int i=1;i<=n;i++){
//        cout<<i<<newl;
//        for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<newl;
//    }


    for(int i=1;i<=n;i++){
        choose(1,1,i);
    }
    cout<<f<<newl;

}
