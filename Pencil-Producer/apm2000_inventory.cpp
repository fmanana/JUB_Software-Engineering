#include "apm2000_inventory.h"

/**
 * @brief APM2000_Inventory::APM2000_Inventory
 * APM2000_Inventory constructor.\n
 * Default values:\n
 * number = 0\n
 * price = $150.00
 */
APM2000_Inventory::APM2000_Inventory()
{
    number = 0;
    price = 150.0f;
}

/**
 * @brief APM2000_Inventory::buyAPM2000
 * If canBuyAPM2000 evaluates to true, bank balance is debited, the number
 * of APMs in inventory increases by 1 and the APM price is updated.
 * @param wallet
 */
void APM2000_Inventory::buyAPM2000(Wallet& wallet)
{
    if (canBuyAPM2000(wallet))
    {
        wallet.debitMoney(price);
        number++;
        price *= 1.1f;
    }
}

/**
 * @brief APM2000_Inventory::canBuyAPM2000
 * checks if wallet balance has enough for new APM and if the number of APMs in
 * inventory is less than the max (10).
 * @param wallet
 * @return true conditions are met, false otherwise
 */
bool APM2000_Inventory::canBuyAPM2000(Wallet& wallet)
{
    return (number < 10 && wallet.canDebitMoney(price));
}

void APM2000_Inventory::producePencil(Pencil_Inventory& pencilInventory,
                                      Graphite_Inventory& graphiteInventory,
                                      Wood_Inventory& woodInventory)
{
    for (int i= 0; i < number; i++) {
        if (canProducePencil(pencilInventory, graphiteInventory, woodInventory))
        {
            pencilInventory.producePencil(graphiteInventory, woodInventory, 2);
        }
        else
        {
            break;
        }
    }

}

bool APM2000_Inventory::canProducePencil(Pencil_Inventory& pencilInventory,
                                         Graphite_Inventory& graphiteInventory,
                                         Wood_Inventory& woodInventory)
{
    return pencilInventory.canProducePencil(graphiteInventory, woodInventory, 2);
}

/// returns number of APMs in inventory
int APM2000_Inventory::getNumber() const
{
    return number;
}

/// returns price of APM
float APM2000_Inventory::getPrice() const
{
    return price;
}

int APM2000_Inventory::getRate() const
{
    return number * 120;
}
