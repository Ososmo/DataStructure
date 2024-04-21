#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node{
    T value;
    Node *next;
    Node(){
    next=NULL;
    }
    Node(T ob){
        value=ob;
        next=NULL;
    }
};
template<class T>
class queue{
private:
    Node<T> * header;
    Node<T> * tail;
    int size=0;
public:
    queue(){
        header=NULL;
        tail=NULL;
    }
    void enque(T ob){
        if(header==NULL){
            Node<T> * temp=new Node(ob);
            header=temp;
            tail=header;
        }
        else{
            tail->next=new Node(ob);

        }
        size++;
    }
    T deque(){
        if(size==0)return NULL;
        T temp=header.value;
        Node<T> * current=header;
        header=header->next;
        delete current;
        return temp;
    }
    T first(){
        return header.value;
    }
    bool isEmpty(){
        return size==0;
    }
    int queueSize(){
        return size;
    }
    void clear(){

        while(header!=NULL){
            Node <T>* current=header;
            header=header->next;
            delete current;
        }
    }
    void print(){
        Node<T> * current=header;
        while(current!=NULL){
            cout<<current.value<<" ";
            current=header->next;
        }
        cout<<endl;
    }
};
int main(){
    queue<int>q;
    return 0;
}
