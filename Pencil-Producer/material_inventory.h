#ifndef MATERIAL_INVENTORY_H
#define MATERIAL_INVENTORY_H

#include "wallet.h"
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief The Material_Inventory class
 * superclass of other material classes.
 */
class Material_Inventory
{
public:
    Material_Inventory(float, float);
    void buy(Wallet&);
    bool canBuy(Wallet&) const;
    float getPrice() const;
    void setPrice();
    float getAmount() const;
    void consume(int n = 1);
    bool canConsume(int n = 1) const;
private:
    /// price of 100.00m of material
    float price;
    /// amount of material in inventory
    float amount;
    /// the minimum price of the material
    float minPrice;
    float change;
};

#endif // MATERIAL_INVENTORY_H
