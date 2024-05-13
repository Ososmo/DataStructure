//
// Created by Osos on 13/05/2024.
//

#include "HeapSort.h"
#include <iostream>

using namespace std;

SortByName::SortByName(int order) {
    this->order = order;
}

bool SortByName::sortByFunction(Item a, Item b, int orderBy) {
    if (orderBy == 1) {


        while (a.itemname.size() < b.itemname.size())
            a.itemname += 'z';

        while (a.itemname.size() > b.itemname.size())
            b.itemname += 'z';
        return a.itemname < b.itemname;

    } else {
        while (a.itemname.size() < b.itemname.size())
            a.itemname += 'a';

        while (a.itemname.size() > b.itemname.size())
            b.itemname += 'a';
        return a.itemname > b.itemname;
    }
}

SortByPrice::SortByPrice(int order) {
    this->order = order;
}

bool SortByPrice::sortByFunction(Item a, Item b, int orderBy) {
    if (orderBy == 1)
        return a.price < b.price;
    else
        return a.price > b.price;
}

void Build_Heap::shiftdown(int i) {
    int largest = i;
    if (i * 2 <= arr.size()) {
        if (method->sortByFunction(arr[i - 1], arr[i * 2 - 1], method->order))
            largest = i * 2;
    }
    if (i * 2 + 1 <= arr.size()) {
        if (method->sortByFunction(arr[i - 1], arr[i * 2], method->order) and
            method->sortByFunction(arr[largest - 1], arr[i * 2], method->order))
            largest = i * 2 + 1;
    }
    if (largest != i) {
        swap(arr[largest - 1], arr[i - 1]);
        shiftdown(largest);
    } else return;

}

void Build_Heap::build() {
    int sz = (arr.size()) / 2;
    for (int i = sz; i; i--)
        shiftdown(i);
}

void Build_Heap::display() {

    heapSort();
    int sz = arr.size();
    for (int i = 0; i < sz; i++) {
        cout << arr[i].itemname << "\n";
    }

}

Build_Heap::Build_Heap(vector<Item> &v, SortBy *method) {

    arr = v;
    this->method = method;
}

void Build_Heap::heapSort() {

    int sz = arr.size();
    for (int i = sz / 2 - 1; ~i; i--)
        heapify(i, sz);
    for (int i = sz - 1; ~i; i--) {
        swap(arr[0], arr[i]);
        heapify(0, i);
    }
}

void Build_Heap::heapify(int i, int sz) {
    int tmp = i;
    int lft = 2 * i + 1;
    int rt = 2 * i + 2;
    if (rt < sz && method->sortByFunction(arr[rt], arr[tmp], method->order))
        tmp = rt;
    if (lft < sz && method->sortByFunction(arr[lft], arr[tmp], method->order))
        tmp = lft;
    if (tmp != i) {
        swap(arr[tmp], arr[i]);
        heapify(sz, tmp);
    }
}




