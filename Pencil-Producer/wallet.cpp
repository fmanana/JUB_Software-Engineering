#include "wallet.h"

/**
 * @brief Wallet::Wallet
 * wallet constructor. Default balance $145.00.
 */
Wallet::Wallet() {
    bankBalance = 145.00;
}

/**
 * @brief Wallet::getBankBalance
 * @return float bankBalance
 */
float Wallet::getBankBalance() const
{
    return bankBalance;
}

/**
 * @brief Wallet::creditMoney
 * credits bank balance
 * @param money amount to credit bank balance
 */
void Wallet::creditMoney(float money)
{
    if (canCreditMoney(money))
    {
        bankBalance += money;
    }
}
/**
 * @brief Wallet::debitMoney
 * debits bank balance
 * @param money amount to debit bank balance
 */
void Wallet::debitMoney(float money)
{
    if (canDebitMoney(money))
    {
        bankBalance -= money;
    }
}

/**
 * @brief Wallet::canCreditMoney
 * @param money amount to credit
 * @return true if amount to credit is positive, false otherwise
 */
bool Wallet::canCreditMoney(float money) const
{
    return (money >= 0);
}

/**
 * @brief Wallet::canDebitMoney
 * @param money amount to debit
 * @return true if amount to debit is not greater than bank balance
 * and amount to debit is positive, false otherwise
 */
bool Wallet::canDebitMoney(float money) const
{
    return (bankBalance >= money && money >= 0);
}

