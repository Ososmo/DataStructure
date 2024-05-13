#include<bits/stdc++.h>
#include "Item.h"
#include "HeapSort.h"
#include "avl.h"
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
        inputFile >> category>>price;
        inputFile.ignore();
        items.push_back(Item(name, price,category ));
        numStudents++;
    }
    inputFile.close();

}


void menu_avl() {

    avl objName(1) ,objPrice(2);
    for(auto&i:items)
        {   
            objName.Insert(i),
            objPrice.Insert(i);
        }
    int choice=9;
    while (choice) {

        cout << "1. Add item data\n"
             << "2. Remove item data\n"
             << "3. Display the item data normally\n"
             << "4. Display all the items sorted by their name (ascending)\n"
             << "5. Display all the items sorted by their name (descending)\n"
             << "6. Display all the items sorted by their prices (ascending)\n"
             << "7. Display all the items sorted by their prices (descending)\n";

        cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, cate;
                int price;
                cin >> name >> cate >> price;
                Item x(name, price, cate);
                objName.Insert(x);
                objPrice.Insert(x);
                break;
            }
            case 2:
                break;
            case 3:

                break;
            case 4:
                objName.displayInOrder();
                break;
            case 5:
                objName.displayPostOrder();
                break;
            case 6:
                objPrice.displayPostOrder();
                break;
            case 7:
                objPrice.displayInOrder();
                break;
            default:
                break;
        }
        cout<<"\n";
    }

}
void dispaly()
{
  cout<<"1-HEAP\n";
  cout<<"2-AVL\n";
  cout<<"3-Binary Search\n";
  int choice;  
  cin>>choice;
  if(choice==1)
     menu_Heap();  
  else if(choice==2)
      menu_avl();
 else
      menu_BinarySearch();

}
int main() {
    get_input();
    display();
    return 0;
}






