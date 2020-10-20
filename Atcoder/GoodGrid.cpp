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

int n,c,ans;
int trans[5][40],d[40][40];
vi v[4];
void solve (){
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            if(j==i)continue;
            else{
                for(int k=1;k<=c;k++){
                    if(k==i || k==j){continue;}
                    else{
                        int res = 0;
                        res = trans[0][i] + trans[1][j] + trans[2][k];
                        ans = min(ans,res);

                    }
                }
            }
        }
    }

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            v[(i+j)%3].pb(temp);
        }
    }
    for(int i=0;i<3;i++){
        for(int color = 1; color <= c; color++){
            for(int j=0;j<v[i].size();j++){
                trans[i][color] += d[v[i][j]][color];
            }
        }
    }
    ans = INT_MAX;
    solve();
    cout<<ans<<newl;
}
