#include<iostream>
using namespace std;
template<class T>
class list{
private:
int mxArraySize=10;
int size=0;
T * arr=new T[mxArraySize];
void shiftRight(int index){
    for(int i=size;i>=index+1;i--){
        arr[i]=arr[i-1];
    }
}
void shiftLeft(int index){
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }

}
void getGreaterArray(){
    mxArraySize*=2;
    T * temp=new T[mxArraySize];
    T * curr=arr;
    arr=temp;
    for(int i=0;i<size;i++)arr[i]=curr[i];
    delete [] curr;
}
public:
void insertAtHead(T ob){
    if(size==mxArraySize)
        getGreaterArray();
    shiftRight(0);
    arr[0]=ob;
    size++;
}
void insertAtTail(T ob){
    if(size==mxArraySize)
        getGreaterArray();
    arr[size]=ob;
    size++;

}
void insertAt(T ob,int index){
    if(size==mxArraySize or index>=size)
        getGreaterArray();
    shiftRight(index);
    arr[index]=ob;
    size++;

}
void removeAtHead(){
    if(!size)return;
    shiftLeft(0);
    size--;
}
void removeAtTail(){
    if(!size)return;
    size--;
}
void removeAt(int index){
    if(!size)return;
    shiftLeft(index);
    size--;
}
T    retrieveAt(int index){
        return arr[index];

}
void replaceAt(T ob,int index){
    arr[index]=ob;
}
bool isExist(T ob){
    for(int i=0;i<size;i++){
        if(arr[i]==ob)return true;
    }
    return false;
}

bool isItemAtEqual(T ob, int index){
    return arr[index]==ob;
}
void swap(int firstIndex,int secondIndex){
    T temp=arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=arr[firstIndex];
}
bool isEmpty(){
    return size==0;
}
int  linkedListSize(){
    return size;
}
void clear(){
    size=0;

}
void print(){
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

};
int main(){


}

