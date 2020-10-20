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

int n;
vector < pair <int , pii> > incr,decr;
deque < pii > q;
deque <int> ansi,ansd;
map < pii , int > m;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a<b)incr.pb(mp( b-a , (mp(a,b))));
        else decr.pb(mp (a-b, (mp(a,b))));
        m [mp(a,b)]=i;
    }
    sort(incr.begin(),incr.end());
    sort(decr.begin(),decr.end());

    for(int i=incr.size()-1;i>=0;i--){
        if(q.empty()){
            q.push_back(incr[i].se);
            ansi.pb(m[incr[i].se]);
        }
        else{
            int a = incr[i].sf;
            int b = incr[i].ss;

            int qf = q.front().se;
            int qb = q.back().fi;

            if(a<qb){q.pb(mp(a,b));ansi.pb(m[incr[i].se]);}
            else if(b>qf){q.push_front(mp(a,b));ansi.push_front(m[incr[i].se]);}
        }
    }

    for(int i=decr.size()-1;i>=0;i--){
        if(q.empty()){
            q.push_back(decr[i].se);
            ansd.pb(m[decr[i].se]);
        }
        else{
            int a = decr[i].sf;
            int b = decr[i].ss;

            int qf = q.front().se;
            int qb = q.back().fi;

            if(a>qb){q.pb(mp(a,b));ansd.pb(m[decr[i].se]);}
            else if(b<qf){q.push_front(mp(a,b));ansd.push_front(m[decr[i].se]);}
        }
    }

    if(ansi.size()>=ansd.size()){
        cout<<ansi.size()<<newl;
        while(!ansi.empty()){
            cout<<ansi.front()<<" ";
            ansi.pop_front();
        }
    }
    else{
        cout<<ansd.size()<<newl;
        while(!ansd.empty()){
            cout<<ansd.front()<<" ";
            ansd.pop_front();
        }
    }

}
