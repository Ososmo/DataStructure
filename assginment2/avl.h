//
// Created by Osos on 13/05/2024.
//

#ifndef CODEFORCES_AVL_H
#define CODEFORCES_AVL_H
#include "Item.h"

#ifndef AVL_H
#define AVL_H

#include "Item.h"

class node {
public:
    Item data;
    node* left;
    node* right;
    int height;

    node(const Item& x);
};

class avl {
private:
     node* root;
    int order;

public:
    avl(int order);
    void Insert(const Item& value);
    void displayInOrder( );
    void displayPostOrder();

private:
    int getHeight(node* r);
    int getBalance(node* r);
    node* rightRotation(node* r);
    node* leftRotation(node* r);
    node* insert(node* r, const Item& value);
    void displayInOrder(node* head);
    void displayPostOrder(node*head);

};


#endif // AVL_H




#endif //CODEFORCES_AVL_H
