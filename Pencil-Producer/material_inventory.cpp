#include "material_inventory.h"

Material_Inventory::Material_Inventory(float minPrice, float change)
{
    srand(time(0));
    this->minPrice = minPrice;
    this->change = change;
    setPrice();
    amount = 1000.0f;
}

/**
 * @brief Material_Inventory::buy
 * if there are sufficient funds in bank balance, increase the amount of material
 * in inventory by 100.00m and debit bank balance.
 * @param wallet
 */
void Material_Inventory::buy(Wallet& wallet)
{
    if (canBuy(wallet))
    {
        amount += 100.0f;
        wallet.debitMoney(price);
    }
}

/// returns true if the bank balance is greater or equal to the price of the material,
/// false otherwise
bool Material_Inventory::canBuy(Wallet& wallet) const
{
    float bankBalance = wallet.getBankBalance();
    return (bankBalance >= price);
}

/// returns price of material
float Material_Inventory::getPrice() const
{
    return price;
}

/// randomly increases the price of the material within a certain value range
void Material_Inventory::setPrice()
{
    price = minPrice + rand() % 1001;
}

/// returns the amount of the material in inventory
float Material_Inventory::getAmount() const
{
    return amount;
}

/**
 * @brief Material_Inventory::consume
 * if there is sufficient material, reduces the amount of material in inventory
 * by the appropriate amount.
 * @param n
 */
void Material_Inventory::consume(int n)
{
    if (canConsume(n))
    {
        amount -= change * n;
    }
}

bool Material_Inventory::canConsume(int n) const
{
    return (amount >= change * n);
}
