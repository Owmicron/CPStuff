#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,nex[500000],f1,f2;
bool isprime[500000];
vector <int> prime,ans;
void sieve (int x){
    for(int i=2;i<=x;i++)isprime[i]=true;
    for(int i=2;i<=x;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    sieve(450000);
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;cin>>temp;
        if(temp==1){f1++;}
        else{f2++;}
    }
    for(int i=0;i<prime.size();i++){
        int t;
        if(i==0){t=0;}
        else{t=prime[i-1];}

        for(int j=prime[i]-1;j>=t;j--){
            nex[j]=prime[i];
        }
    }
    int sum=0;
    while(f1+f2>0){
        int dist = abs(sum-nex[sum]);
        if(f1==0){
            for(int i=0;i<f2;i++)ans.push_back(2);
            f2=0;
        }
        else if(f2==0){
            for(int i=0;i<f1;i++)ans.push_back(1);
            f1=0;
        }
        else{
            if(dist>1){ans.push_back(2);f2--;sum+=2;}
            else{ans.push_back(1);f1--;sum++;}
        }
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";

}
