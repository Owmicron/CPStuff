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

int prel[30][200010],n,fr[30],m;
str s;
bool valid (int idx){
    bool v = true;
    for(int i=1;i<=26;i++){
        if(prel[i][idx]>=fr[i]){continue;}
        else{v=false;break;}
    }
    return v;
}
int solve (){
    int l = 1;
    int r = n;
    int res = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(valid(mid)){
            res = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return res;


}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    for(int i = 0;i < s.size(); i++){
        int idx = i + 1;
        for(int j = 1; j <= 26; j++){
            prel[j][idx] = prel[j][idx-1];
        }
        int dig = numerize(s[i]);
        prel[dig][idx]++;
    }

    cin>>m;
    for(int cases=1;cases<=m;cases++){
        str t;
        cin>>t;
        for(int i=1;i<=26;i++)fr[i]=0;
        for(int i=0;i<t.size();i++){
            int dig = numerize(t[i]);
            fr[dig]++;
        }
        cout<<solve()<<newl;
    }




}
