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


    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;

    int balance = getBalance(r);
    if(order) {
        if (value.itemname < r->data.itemname) {
            r->left = insert(r->left, value);
        } else if (value.itemname > r->data.itemname) {
            r->right = insert(r->right, value);
        } else
            return r;
    }else
    {
        if (value.price < r->data.price) {
            r->left = insert(r->left, value);
        } else if (value.price > r->data.price) {
            r->right = insert(r->right, value);
        } else
            return r;
    }
     r =fix(r,value);

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

node* avl::remove(node*head, const Item &value) {

    if(head== NULL)
        return nullptr;

    if(order)
    {
        if(head->data.itemname > value.itemname)
        {
            head->left = remove(head->left,value);
        }
        else if(head->data.itemname > value.itemname)
        {
            head->right = remove(head->right,value);
        }

    }else
    {
        if(head->data.price > value.price)
        {
            head->left = remove(head->left,value);
        }
        else if(head->data.price > value.price)
        {
            head->right = remove(head->right,value);
        }
    }
        if(head->left== NULL)
        {
            node*tmp=head->right;
            delete head;
            return tmp;
        }
        if(head->right== NULL)
        {
            node*tmp = head->left;
            delete head ;
            return tmp;
        }
        node* prev = head;
        node* current = head->left;
        while(current!=NULL && current->right!=NULL)
        {
            prev=current;
            current=current->right;
        }
        head->data=current->data;
        if(head!=prev)
        {
            prev->right = current->left;
        }
        else
        {
            prev->left = current->left;
        }
        delete current;

       head = fix(head,value);
     return head;

}

node *avl::fix(node*head ,const Item &value) {

    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;
    int balance = getBalance(head);
    if(order)
    {
        // Left Left Case
        if (balance > 1 && value.itemname < head->left->data.itemname) {
            return rightRotation(head);
        }
        // Right Right Case
        if (balance < -1 && value.itemname > head->right->data.itemname) {
            return leftRotation(head);
        }
        // Left Right Case
        if (balance > 1 && value.itemname > head->left->data.itemname) {
            head->left = leftRotation(head->left);
            return rightRotation(head);
        }
        // Right Left Case
        if (balance < -1 && value.itemname < head->right->data.itemname) {
            head->right = rightRotation(head->right);
            return leftRotation(head);
        }
    }
    else
    {

        // Left Left Case
        if (balance > 1 && value.price < head->left->data.price) {
            return rightRotation(head);
        }
        // Right Right Case
        if (balance < -1 && value.price > head->right->data.price) {
            return leftRotation(head);
        }
        // Left Right Case
        if (balance > 1 && value.price > head->left->data.price) {
            head->left = leftRotation(head->left);
            return rightRotation(head);
        }
        // Right Left Case
        if (balance < -1 && value.price < head->right->data.price) {
            head->right = rightRotation(head->right);
            return leftRotation(head);
        }
    }
    return head;
}

void avl::Remove(const Item &value) {
    remove(root,value);
}



