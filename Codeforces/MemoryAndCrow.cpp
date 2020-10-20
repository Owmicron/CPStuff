#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
long n,c;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=n;i>=1;i--){
        b[i]=a[i];
        c=0;
        for(int j=i+1;j<=n;j++){
            c++;
            if(c%2==0){b[i]-=b[j];}
            else{b[i]+=b[j];}

        }


    }
    for(int i=1;i<=n;i++){
        cout<<b[i];
        if (i<n)cout<<" ";

    }

}
