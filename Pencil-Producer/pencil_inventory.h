#ifndef PENCIL_INVENTORY_H
#define PENCIL_INVENTORY_H

#include "wallet.h"
#include "graphite_inventory.h"
#include "wood_inventory.h"
#include <cmath>
#include <iostream>
#include <algorithm>

/**
 * @brief The Pencil_Inventory class
 * main class for managing pencil prices and production.
 */
class Pencil_Inventory
{
public:
    Pencil_Inventory();

    // getter methods
    float getPrice() const;
    int getAmount() const;
    float getPublicDemand() const;
    int getTotalNumberOfPencilsProduced() const;
    int getNumberOfPencilsToBeSold() const;

    //change price
    void increasePrice();
    void decreasePrice();
    bool canDecreasePrice() const;

    //sell and produce pencils
    void sellPencil(Wallet&, int n = 1);
    bool canSellPencil(int n = 1) const;
    void producePencil(Graphite_Inventory&, Wood_Inventory&, int n = 1);
    bool canProducePencil(Graphite_Inventory&, Wood_Inventory&, int n = 1) const;
private:
    /**
     * steps to increase/decrease the price of a pencil.
     * Default value set to $0.05
     */
    const float change = 0.05f;
    /// the price of a pencil
    float price;
    /// the number of pencils in the inventory
    int amount;
    /// the total number fo pencils produced
    int totalNumberOfPencilsProduced;
};

#endif // PENCIL_INVENTORY_H
