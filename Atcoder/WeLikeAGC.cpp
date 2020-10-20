#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,md=1000000007;
char choice[5];
vector <str> query;
bool calc[200][5000];
ll memo[200][5000];
ll conv(str y){
    ll a,b,c;
    a=0;
    b=0;
    c=0;
    for(int i=1;i<=4;i++){
        if(y[0]==choice[i]){a=i;break;}
    }
    for(int i=1;i<=4;i++){
        if(y[1]==choice[i]){b=i;break;}
    }
    for(int i=1;i<=4;i++){
        if(y[2]==choice[i]){c=i;break;}
    }
    return 16*(a-1) + 4*(b-1) + c;
}
ll dp (ll x, str z){
    ll num = conv(z);
    if(x==n){return 1;}
    else if(calc[x][num]){return memo[x][num];}
    else{
        bool notc,notg;
        notc=false;notg=false;
        if(z[1]=='A' && z[2]=='G'){notc=true;}
        if(z[1]=='A' && z[2]=='C'){notg=true;}
        if(z[1]=='G' && z[2]=='A'){notc=true;}
        if(z[0]=='A' && z[2]=='G'){notc=true;}
        if(z[0]=='A' && z[1]=='G'){notc=true;}

        str t="";
        t+=z[1];
        t+=z[2];
        ll ans = 0;
        for(int i=1;i<=4;i++){
            str temp = t;
            if(notc && i==2)continue;
            if(notg && i==3)continue;

            temp += choice[i];
            ans = ( (ans%md) + (dp(x+1,temp)%md) ) % md ;
        }
        memo[x][num]=ans;
        calc[x][num]=true;
        return ans;
    }
}
int main(){
    cin>>n;
    choice[1]='A';
    choice[2]='C';
    choice[3]='G';
    choice[4]='T';
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=4;k++){
                str temp = "";
                temp+=choice[i];
                temp+=choice[j];
                temp+=choice[k];
                if(temp=="AGC" || temp=="ACG" || temp=="GAC")continue;
                query.push_back(temp);
            }
        }
    }

    ll tot = 0;
    for(int i=0;i<query.size();i++){
        tot = ((tot % md) + (dp(3,query[i]) % md) )%md ;
    }
    cout<<tot<<endl;
}
