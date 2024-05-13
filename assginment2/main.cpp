#include<bits/stdc++.h>
#include "Item.h"
#include "HeapSort.h"
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
void dispaly()
{
  cout<<"1-Heap sort with name Asec\n";
  cout<<"2-Heap sort with name Desc\n";
  cout<<"3-Heap sort with price Asec\n";
  cout<<"4-Heap sort with price Desc\n";
  cout<<"2-AVL\n";
  cout<<"3-Binary Search\n";


}
int main() {
    get_input();
    int choice;
    while(choice)
    {
        dispaly();
        cin>>choice;

        switch (choice) {
            case 1:
            {

                SortByName *sort_by_name_Asec=new SortByName(2);
                Build_Heap hp(items,sort_by_name_Asec);
                hp.build();
                hp.display();
                break;
            }
            case 2:
            {

                SortByName *sort_by_name_Desc=new SortByName(1);
                Build_Heap hp(items,sort_by_name_Desc);
                hp.build();
                hp.display();
                break;
            }
            case 3:
            {

                SortByPrice *sort_by_price_Asec=new SortByPrice(2);
                Build_Heap hp(items,sort_by_price_Asec);
                hp.build();
                hp.display();
                break;
            }
            case 4:
            {

                SortByPrice *sort_by_price_Desc=new SortByPrice(1);
                Build_Heap hp(items,sort_by_price_Desc);
                hp.build();
                hp.display();
                break;
            }
            default:
                break;

        }
        system("PAUSE");
    }
    return 0;
}






