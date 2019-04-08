#ifndef WALLET_H
#define WALLET_H

/**
 * @brief The Wallet class
 * keeps track of bank balance and methods for crediting/debiting account
 */
class Wallet
{
public:
    Wallet();
    float getBankBalance() const;
    void creditMoney(float);
    void debitMoney(float);
    bool canCreditMoney(float) const;
    bool canDebitMoney(float) const;
private:
    /// bank balance. Default value set to $145.00
    float bankBalance;
};

#endif // WALLET_H
