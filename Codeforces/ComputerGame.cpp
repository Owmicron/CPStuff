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

int q,n,k,a,b;
bool valid (int x){
    int r = k - (x*a);
    int turn = x;
    if(r>b){
        int temp = (r/b)-1;
        if(r%b!=0)temp++;
        turn += temp;
    }
    if(turn >= n){return true;}
    else return false;
}
int bins (int l, int r){
    int res = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(valid(mid)){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }

    }
    return res;
}
int solve(){
    int mt = (k/b)-1;
    if(k%b!=0)mt ++;
    if(mt>=n){
        int ma = k/a - 1;
        if(k%a!=0)ma++;
        ma = min(n,ma);
        return bins(0,ma);
    }
    else return -1;

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    for(int cases=1;cases<=q;cases++){
        cin>>k>>n>>a>>b;
        cout<<solve()<<newl;
    }
}
