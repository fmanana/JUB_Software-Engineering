#ifndef APM2000_INVENTORY_H
#define APM2000_INVENTORY_H

#include "wallet.h"
#include "pencil_inventory.h"
#include "graphite_inventory.h"
#include "wood_inventory.h"
/**
 * @brief The APM2000_Inventory class
 * Automatic Pencil Machine(APM)\n
 * Suffix "2000" indicates 2000-series. Every 2000-series produces 2 pencils per
 * second, which are automatically added into the inventory. APM stops automatically
 * when there are insufficient materials and resumes when materials are available.
 */
class APM2000_Inventory
{
public:
    APM2000_Inventory();
    void buyAPM2000(Wallet&);
    bool canBuyAPM2000(Wallet&);
    void producePencil(Pencil_Inventory&, Graphite_Inventory&, Wood_Inventory&);
    bool canProducePencil(Pencil_Inventory&, Graphite_Inventory&, Wood_Inventory&);
    int getNumber() const;
    float getPrice() const;
    int getRate() const;

private:
    /// maximum number of APMs allowed
    const int max = 10;
    /// number of APMs in your inventory
    int number;
    /// price of APM
    float price;
};

#endif // APM2000_INVENTORY_H
