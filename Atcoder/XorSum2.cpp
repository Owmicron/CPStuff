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

int n,a[200010];
int bit[25][200010];
ll ans;
bool valid (int l , int r){
    bool v = true;
    for(int i=1;i<=20;i++){
        if(bit[i][r]-bit[i][l-1]>1){v=false;break;}
    }
    return v;
}
void construct (int idx){
    int z = a[idx] ;
    queue <int> q;
    while(z>0){
        if(z%2==0)q.push(0);
        else q.push(1);
        z/=2;
    }
    int b = 1;
    for(int i=1;i<=20;i++){
        bit[i][idx] = bit[i][idx-1];
    }

    while(!q.empty()){
        bit[b][idx] += q.front();
        b++;
        q.pop();
    }
}
int binsearch (int start){
    int l = start;
    int r = n;
    int res=l;
    while(l<=r){
        int mid = (l+r)/2;
        if(valid(start,mid)){
            res = mid-start+1;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return res;

}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        construct(i);
    }

    for(int i=1;i<=n;i++){
        ans += binsearch(i);
    }
    cout<<ans<<newl;



}
