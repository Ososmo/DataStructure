#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class queue{
private:
     long long lastIndex=10000;
    T *arr=new T[lastIndex];
    int start=0;
    int end=0;
    int size=0;
    void handleQueue(){
        lastIndex=2*lastIndex;
        T *temp=new T[lastIndex];
        int pos=0;
        for(int i=start;i<=end;i++){
            temp[pos]=arr[i];
            pos++;
        }
        T *exTemp=arr;
        arr=temp;
        delete []exTemp;

    }
public:

    void enque(T ob){

        if(size==lastIndex){
            handleQueue();
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
        return arr[start];
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
