//
// Created by Osos on 13/05/2024.
//

#ifndef CODEFORCES_HEAPSORT_H
#define CODEFORCES_HEAPSORT_H

#include "Item.h"
#include <vector>

class SortBy {
public:
    int order;

    virtual bool sortByFunction(Item a, Item b, int orderBy) = 0;

};

class SortByName : public SortBy {
public:
    SortByName(int order);

    bool sortByFunction(Item a, Item b, int orderBy);
};

class SortByPrice : public SortBy {
public:
    SortByPrice(int order);

    bool sortByFunction(Item a, Item b, int orderBy) override;
};

class Build_Heap {
    vector<Item> arr;
    // orderBy -> 1 for Max  2 -> for Min
public:
    SortBy *method;

    Build_Heap(vector<Item> &v, SortBy *method);

    void shiftdown(int i);

    void build();

    void display();

    void heapSort();

    void heapify(int sz, int i);

};


#endif //CODEFORCES_HEAPSORT_H
