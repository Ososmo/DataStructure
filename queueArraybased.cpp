#include<bits/stdc++.h>
using namespace std;

template<class T>
class queue{
private:
    const int lastIndex=10000;
    T arr[lastIndex];
    int start=0;
    int end=0;
    int size=0;
    void handleQueue(){
        int pos=0;
        for(int i=start;i<=end;i++){
            arr[pos]=arr[i];
            arr[i]=NULL;
            pos++;
        }

    }
public:

    void enque(T ob){

        if(size==lastIndex){
            cout<<"Queue is full!"<<endl;
            return ;
        }
        arr[end++]=ob;
        size++;
        if(end==lastIndex-1)end=0;
    }
    T deque(){
        if(size==0){
            cout<<"Queue is already empty!"<<endl;
            return ;
        }
        arr[start++]=NULL;
        if(start==lastIndex-1)start=0;


    }
    T first(){

    }
    bool isEmpty(){
        return size==0;
    }
    int queueSize(){
        return size;
    }
    void clear(){
    start=end=0;
    size=0;

    }
    void print(){
    if(start>end){
        for(int i=start;i<lastIndex;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=end;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=start;i<=end;i++){
            cout<<arr[i]<<" ";
        }

    }
        cout<<endl;
    }
};
int main(){
    queue<int>q;
  
    return 0;
}
