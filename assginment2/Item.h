//
// Created by Osos on 13/05/2024.
//

#ifndef CODEFORCES_ITEM_H
#define CODEFORCES_ITEM_H
#include <iostream>
using namespace std;
class Item {
    public:
        string itemname;
        string category;
        int price ;
        Item(string itemname,int price,string category){
            this->itemname=itemname;
            this->category=category;
            this->price=price;
        }
};


#endif //CODEFORCES_ITEM_H
