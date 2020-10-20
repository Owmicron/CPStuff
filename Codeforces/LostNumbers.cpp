#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int arr[10],a,b,c,d,ans[10],f[1000];
int verdict;
int main(){
    arr[1]=4;
    arr[2]=8;
    arr[3]=15;
    arr[4]=16;
    arr[5]=23;
    arr[6]=42;

    cout<<"? 1 2\n";
    fflush(stdout);
    cin>>verdict;
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=6;j++){
            if(arr[i]*arr[j]==verdict){
                a = arr[i];
                b = arr[j];
            }
        }
    }

    cout<<"? 2 3\n";fflush(stdout);
    cin>>verdict;
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=6;j++){
            if(arr[i]*arr[j]==verdict){
                c = arr[i];
                d = arr[j];
            }
        }
    }
    f[a]++;
    f[b]++;
    f[c]++;
    f[d]++;

    if(f[a]==1){
        ans[1] = a;
        ans[2] = b;
    }
    else{
        ans[1] = b;
        ans[2] = a;
    }
    if(f[c]==1){
        ans[3] = c;
    }
    else{
        ans[3] = d;
    }

    cout<<"? 4 5\n";fflush(stdout);
    cin>>verdict;
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=6;j++){
            if(arr[i]*arr[j]==verdict){
                a = arr[i];
                b = arr[j];
            }
        }
    }


    cout<<"? 5 6\n";fflush(stdout);
    cin>>verdict;
    for(int i=1;i<=5;i++){
        for(int j=i+1;j<=6;j++){
            if(arr[i]*arr[j]==verdict){
                c = arr[i];
                d = arr[j];
            }
        }
    }
    f[a]++;
    f[b]++;
    f[c]++;
    f[d]++;

    if(f[a]==1){
        ans[4] = a;
        ans[5] = b;
    }
    else{
        ans[4] = b;
        ans[5] = a;
    }
    if(f[c]==1){
        ans[6] = c;
    }
    else{
        ans[6] = d;
    }
    cout<<"!";
    fflush(stdout);
    for(int i=1;i<=6;i++){
        cout<<" "<<ans[i];
        fflush(stdout);
    }cout<<endl;
    fflush(stdout);

}
