#pragma once
//Bag.h
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class ItemBag
{
    vector<string>     items;

public:
    ItemBag();
    void add_item(const string & item);
    size_t num_items() const;
    const string & get_item(size_t n);
    void RemoveLast();
    void Print (const string & bagname) const;
};

