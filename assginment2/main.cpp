#include<bits/stdc++.h>
#include "Item.h"
using namespace std;
vector<Item>items;
void get_input()
{
    ifstream inputFile("in.txt");
    int numberOfStudents;
    inputFile >> numberOfStudents;
    inputFile.ignore();
    int numStudents = 0;
    string line, name;
    string category;
    int price;
    int sz=numberOfStudents;
    while (sz--) {
        getline(inputFile, name);
        inputFile >> price >> category;
        inputFile.ignore();
        items.push_back(Item(name, price,category ));
        numStudents++;
    }
    inputFile.close();

}
void dispaly()
{
  cout<<"1-Heap sort\n";
  cout<<"2-AVL\n";
  cout<<"3-Binary Search\n";
  

}
int main() {
    get_input();
    while(true)
    {
        dispaly();
        int choice;cin>>choice;
        if(choice)
        {
            // do something
        }
        else
            break;
    }
    return 0;
}






