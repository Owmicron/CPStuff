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
ll score[20],prob[20],bonus[20];
ll n,p[20],c[20];
ll g,pre[20],ans;
ll mn (){
    ll steps = 0;
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + bonus[i];
        if(pre[i-1]<g && g<=pre[i]){
            ll need = g - pre[i-1];
            ll point = score[i];
            ll x = need/score[i];
            if(point * x >= need){}
            else{x++;}

            if(x>prob[i]){x=prob[i];}
            steps += x;
            break;
        }
        else{
            steps += prob[i];
        }
    }
    return steps;
}
int arr [20];
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>g;
    for(int i=1;i<=n;i++)arr[i]=i;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        c[i] += p[i]*i*100;
    }

    for(int i=1;i<=n;i++){
        score[i] = arr[i] * 100;
        prob[i] = p[arr[i]];
        bonus[i] = c[arr[i]];
    }
    ans = LONG_LONG_MAX;
    ans = min(ans,mn());
    while(next_permutation(arr+1,arr+1+n)){
        for(int i=1;i<=n;i++){
            score[i] = arr[i] * 100;
            prob[i] = p[arr[i]];
            bonus[i] = c[arr[i]];
        }
        ans = min(ans,mn());
    }
    cout<<ans<<newl;

}
