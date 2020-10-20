#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[250000],sum_o[250000],sum_e[250000],sum,tot;
ll range_o (int l, int r){
    if(l%2==0){l++;}
    if(r%2==0){r--;}
    if(l>r){return 0;}
    return sum_o[r]-sum_o[l-1];
}
ll range_e (int l, int r){
    if(l%2==1){l++;}
    if(r%2==1){r--;}
    if(l>r){return 0;}
    return sum_e[r]-sum_e[l-1];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(i%2==0){sum_e[i]=sum_e[i-1]+a[i];sum_o[i]=sum_o[i-1];}
        else{sum_o[i]+=sum_o[i-1]+a[i];sum_e[i]=sum_e[i-1];}
        //cout<<sum<<endl<<sum_o[i]<<endl<<sum_e[i]<<endl<<endl;
    }
    for(int i=1;i<=n;i++){
        int ans;
        ans = range_o (1,i-1) + range_e (i+1,n);
        //cout<<range_o (1,i-1)<<" "<<range_e (i+1,n)<<endl;
        //cout<<ans<<endl;
        int temp = sum-a[i];
        if(temp%2==0){
            if(temp/2 == ans){tot++;}
        }
    }
    cout<<tot<<endl;

}

