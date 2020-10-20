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

str s;
bool tx,ans,ty;
int x,y,t,f,sum;
int n,z[10000];
vi sx,sy;
bool calc[8010][8010];
int memo[8010][8010];
bool iss (int x, int y){
    if(y==0)return true;
    else if(x<1)return false;
    else if(y<0)return false;
    else if(calc[x][y])return memo[x][y];
    else{
        bool a,b;
        a = iss(x-1,y);
        b = iss(x-1,y-z[x]);
        bool res = a | b;
        calc[x][y]=true;
        memo[x][y]=res;
        return res;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    cin>>x>>y;
    tx = false;
    ty = false;
    s+='T';
    for(int i=0;i<s.size();i++){
        if(s[i]=='T'){
            t++;
            if(t%2==1)sx.pb(f);
            else{sy.pb(f);}
            f=0;
        }
        else{
            f++;
        }
    }

    for(int i=0;i<sx.size();i++){
        int idx = i+1;
        z[idx] = sx[i];
        sum += sx[i];
    }
    n = sx.size();
    z[1] = 0;
    if(x>sum){tx=false;}
    else{
        int need = sum-x;
        if(need%2!=0)tx=false;
        else{
            need/=2;
            tx = iss(n , need);
            for(int i=0;i<=n;i++){
                for(int j=0;j<=need;j++){
                    calc[i][j]=false;
                }
            }
        }
    }

    if(tx){
        sum = 0;
        for(int i=0;i<sy.size();i++){
            int idx = i+1;
            z[idx] = sy[i];
            sum+=sy[i];
        }
        n = sy.size();

        if(y>sum){ty=false;}
        else{
            int need = sum - y;
            if(need%2!=0)ty=false;
            else{
                need/=2;
                ty = iss(n, need);
            }
        }
    }
    ans = tx & ty;
    if(ans)cout<<"Yes\n";
    else{cout<<"No\n";}
}
