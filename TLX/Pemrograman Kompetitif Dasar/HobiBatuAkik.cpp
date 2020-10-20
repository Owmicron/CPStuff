#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
vector<int>heap;
int parent(int x){return (x-1)/2;}
int left(int x){return 2*x+1;}
int right(int x){return 2*(x+1);}
void heap_push(int x){
    heap.push_back(x);
    int i = heap.size()-1;
    while((i>0)&&(heap.at(i)>heap.at(parent(i)))){
        swap(heap.at(i),heap.at(parent(i)));
        i = parent (i);
    }
}
void heapify(int x){
    int i = x;
    int mx = x;
    bool swapped = true;
    while(swapped){
        swapped=true;
        if((left(i)<heap.size())&&(heap.at(left(i)) > heap.at(mx))){mx = left(i);}
        if((right(i)<heap.size())&&(heap.at(right(i)) > heap.at(mx))){mx = right(i);}
        swap(heap.at(i),heap.at(mx));
        if(i==mx)swapped=false;
        i = mx;
    }
}
void heap_pop(){
    if(!heap.empty()){
        swap(heap.at(heap.size()-1),heap.at(0));
        heap.pop_back();
        if(!heap.empty()){heapify(0);}
    }

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int com,x;
        cin>>com;
        if(com!=1){
            if(com==2){
                cout<<heap.at(0)<<endl;
            }
            if(com==3){
                heap_pop();
            }
        }
        else{
            cin>>x;
            heap_push(x);
        }
    }
}
