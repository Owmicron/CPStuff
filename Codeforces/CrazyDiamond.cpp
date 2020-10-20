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

int n,m,a[400000],pos[400000];
vpii ans;
void tukar (int idx1, int idx2){
    int x = a[idx1];
    int y = a[idx2];
    swap(a[idx1],a[idx2]);
    swap(pos[x],pos[y]);
    ans.pb( mp (idx1,idx2));
}
bool can (int cur, int nex){
    int temp = abs(cur-nex)*2;
    if(temp>=n)return true;
    else return false;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }

    for(int i=1;i<=n;i++){
        int now,dest;
        now = pos[i];
        dest = i;
        if(now==dest)continue;
        else if(can(now,dest)){tukar(now,dest);}
        else{
            if(now<dest){
                if(can(n,dest)){
                    tukar(now,n);
                    tukar(n,dest);
                }
                else{
                    if(can(1,now)){
                        tukar(now,1);
                        tukar(1,dest);
                        tukar(1,now);
                    }
                    else{
                        tukar(now,n);
                        tukar(n,1);
                        tukar(1,dest);
                        tukar(1,n);
                    }
                }
            }
            else{
                if(can(1,dest)){
                    tukar(now,1);
                    tukar(1,dest);
                    tukar(1,now);
                }
                else{
                    if(can(now,n)){
                        tukar(now,n);
                        tukar(n,dest);
                    }
                    else{
                        tukar(now,1);
                        tukar(1,n);
                        tukar(n,dest);
                        tukar(1,now);
                    }
                }
            }
        }

    }

    cout<<ans.size()<<newl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi<<" "<<ans[i].se<<newl;
    }
}
