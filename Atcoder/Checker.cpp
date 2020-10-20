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

int n,k,pre[3000][3000],c[3000][3000],mx;
void add (int x, int y1, int y2){
    if(x<0){
        x += k; y1 += k; y2 += k;
    }
    else if(x>=k){
        x -= k; y1 += k; y2 += k;
    }
    //cout<<x<<" "<<y1<<" "<<y2<<newl;
    y1 %= (2*k);
    y2 %= (2*k);
    if(y1<0)y1+=(2*k);
//    cout<<x<<" "<<y1<<" "<<y2<<newl;
    if(y1>y2){
        pre[x][0]++;pre[x][y2+1]--;
        pre[x][y1]++;pre[x][2*k]--;
    }
    else{
        pre[x][y1]++;pre[x][y2+1]--;
    }

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ll x,y;char z;
        cin>>x>>y>>z;
        if(z=='W')x+=k;
        x%= (2*k); y %= (2*k);
        ll lx,rx,ry,ly;
        rx = x;
        lx = x-k+1;
        ry = y;
        ly = y-k+1;
        for(int i=rx;i>=lx;i--){
            add(i,ly,ry);
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<2*k;j++){
            if(j==0){c[i][j]=0;}
            else{c[i][j]=c[i][j-1];}

            c[i][j]+=pre[i][j];
            mx = max(mx,c[i][j]);
        }
    }
    cout<<mx<<newl;

}
