#include "pencil_inventory.h"

/**
 * @brief Pencil_Inventory::Pencil_Inventory
 * constructor for Pencil_Inventory class.
 * @note starts with default values:\n
 *  price = $1.00\n
 *  number of pencils = 0\n
 *  number of pencils produced = 0\n
 */
Pencil_Inventory::Pencil_Inventory()
{
    price = 1.0f;
    amount = 0;
    totalNumberOfPencilsProduced = 0;
}

/// returns the price of a pencil
float Pencil_Inventory::getPrice() const
{
    return price;
}

/// returns the number of pencils in inventory
int Pencil_Inventory::getAmount() const
{
    return amount;
}

/// returns the public demand of pencils
float Pencil_Inventory::getPublicDemand() const
{
    return (round(100 / price)) / 100.0f;
}

/// returns the total number of pencils produced
int Pencil_Inventory::getTotalNumberOfPencilsProduced() const
{
    return totalNumberOfPencilsProduced;
}

int Pencil_Inventory::getNumberOfPencilsToBeSold() const
{
    return std::min(static_cast<int>(floor(5 * getPublicDemand())), amount);
}

/**
 * @brief Pencil_Inventory::increasePrice
 * increase the price of pencils.
 */
void Pencil_Inventory::increasePrice()
{
    price += change;
}

/**
 * @brief Pencil_Inventory::decreasePrice
 * decrease the price of pencils.
 */
void Pencil_Inventory::decreasePrice()
{
    if (canDecreasePrice())
    {
        price -= change;
    }
}

/**
 * @brief Pencil_Inventory::canDecreasePrice
 * checks if the price can be decreased without resulting in a negative price.
 * @return true if new price is positive, false otherwise.
 */
bool Pencil_Inventory::canDecreasePrice() const
{
    return (static_cast<int>(price * 100) / 100.0f > change);
}

/**
 * @brief Pencil_Inventory::sellPencil
 * the function checks if there are pencils to sell and then
 * decrements the number of pencils in the inventory by n.
 * Wallet is then credited by the price of n pencils
 * @param w wallet
 * @param n the number of pencils to sell. Default value is 1.
 */
void Pencil_Inventory::sellPencil(Wallet& w, int n)
{
    if (canSellPencil(n))
    {
        amount -= n;
        w.creditMoney(price * n);
    }
}

/// returns true if there are pencils to sell, false otherwise
bool Pencil_Inventory::canSellPencil(int n) const
{
    return (amount >= n);
}

/**
 * @brief Pencil_Inventory::producePencil
 * checks if there is enough material to produce n pencils. If true
 * consumes graphite and wood for n pencils and increments the number
 * of pencils in the inventory and totalNumberOfPencilsProduced by n.
 * @param graphiteInventory the amount of graphite in the inverntory
 * @param woodInventory the amount of wood in the inventory
 * @param n the number of pencils to produce
 */
void Pencil_Inventory::producePencil(Graphite_Inventory& graphiteInventory, Wood_Inventory& woodInventory, int n)
{
    if (canProducePencil(graphiteInventory, woodInventory, n))
    {
        graphiteInventory.consume(n);
        woodInventory.consume(n);
        amount += n;
        totalNumberOfPencilsProduced += n;
    }
}

/// returns true if there is enough material to produce n pencils, false otherwise
bool Pencil_Inventory::canProducePencil(Graphite_Inventory& graphiteInventory, Wood_Inventory& woodInventory, int n) const
{
    return (graphiteInventory.canConsume(n) && woodInventory.canConsume(n));
}
