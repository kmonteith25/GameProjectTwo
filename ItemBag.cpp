#include "ItemBag.h"

ItemBag::ItemBag()
{}

void ItemBag::add_item(const string& item)
{
    items.push_back(item);
}

const string& ItemBag::get_item(size_t n)
{
    return items[n];
}

size_t ItemBag::num_items() const
{
    return items.size();
}

void ItemBag::RemoveLast()
{
    items.pop_back();
}

void ItemBag::Print(const string& bagname) const
{
    if (items.size() == 0)
    {
        cout << bagname << " is empty." << endl;
        return;
    }
    cout << bagname << " has " << items.size() << "items. These are: " << endl;
    for (size_t x = 0; x < items.size(); ++x) {
        cout << items[x] << endl;
    }
}

/*
*/

