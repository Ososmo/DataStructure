//
// Created by Osos on 13/05/2024.
//

#include "avl.h"
#include "avl.h"
#include <iostream>

node::node(const Item& x) {
    this->data = x;
    left = right = NULL;
    height = 1;
}

avl::avl(int order) {
    root = nullptr;
    this->order = order;
}



int avl::getHeight(node* r) {
    if (r == nullptr) return 0;
    return r->height;
}

int avl::getBalance(node* r) {
    if (r == nullptr) return 0;
    return getHeight(r->left) - getHeight(r->right);
}

node* avl::rightRotation(node* r) {
    node* x = r->left;
    node* y = x->right;

    x->right = r;
    r->left = y;

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

node* avl::leftRotation(node* r) {
    node* x = r->right;
    node* y = x->left;

    x->left = r;
    r->right = y;

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

node* avl::insert(node* r, const Item& value) {
    if (r == nullptr) {
        return (new node(value));
    }

    if (r == nullptr) {
        return (new node(value));
    }

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;

    int balance = getBalance(r);
    if(order)
    {
        if (value.itemname < r->data.itemname) {
            r->left = insert(r->left, value);
        } else if (value.itemname > r->data.itemname) {
            r->right = insert(r->right, value);
        }
        else
            return r;
        // Left Left Case
        if (balance > 1 && value.itemname < r->left->data.itemname) {
            return rightRotation(r);
        }
        // Right Right Case
        if (balance < -1 && value.itemname > r->right->data.itemname) {
            return leftRotation(r);
        }
        // Left Right Case
        if (balance > 1 && value.itemname > r->left->data.itemname) {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }
        // Right Left Case
        if (balance < -1 && value.itemname < r->right->data.itemname) {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }
    }
    else
    {
        if (value.price < r->data.price) {
            r->left = insert(r->left, value);
        } else if (value.price > r->data.price) {
            r->right = insert(r->right, value);
        }
        else
            return r;
        // Left Left Case
        if (balance > 1 && value.price < r->left->data.price) {
            return rightRotation(r);
        }
        // Right Right Case
        if (balance < -1 && value.price > r->right->data.price) {
            return leftRotation(r);
        }
        // Left Right Case
        if (balance > 1 && value.price > r->left->data.price) {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }
        // Right Left Case
        if (balance < -1 && value.price < r->right->data.price) {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }
    }

    return r;
}

void avl::displayInOrder(node* head) {

    if (head) {
        displayInOrder(head->left);
        cout << head->data.itemname << " ";
        displayInOrder(head->right);
    }
}

void avl::displayPostOrder(node* head) {

    if (head) {
        displayPostOrder(head->right);
       cout << head->data.itemname << " ";
        displayPostOrder(head->left);
    }
}

void avl::Insert(const Item& value) {
    root = insert(root, value);
}

void avl::displayInOrder() {

    displayInOrder(root);
}

void avl::displayPostOrder() {

    displayPostOrder(root);
}



