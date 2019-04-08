#include <QtTest>

// add necessary includes here
#include "../Pencil-Producer/material_inventory.h"
#include "../Pencil-Producer/wood_inventory.h"
#include "../Pencil-Producer/graphite_inventory.h"
#include "../Pencil-Producer/wallet.h"
#include "../Pencil-Producer/pencil_inventory.h"
#include "../Pencil-Producer/apm2000_inventory.h"

/**
 * @brief The _Test class
 * main testing class
 */
class _Test : public QObject
{
    Q_OBJECT

public:
    _Test();
    ~_Test();

private slots:
    // function tests
    void changingPencilPrice();
    void sellPencils();
    void testWallet();
    void testAPM();
    void testMaterials();
};

_Test::_Test(){}
_Test::~_Test(){}

void _Test::changingPencilPrice()
{
    Pencil_Inventory p;
    for (int i = 0; i < 100; i++) {
        p.increasePrice();
        //qDebug("Price : %.2f", p.getPrice());
    }
    for (int i = 0; i < 219; i++) {
        p.decreasePrice();
       // qDebug("Price : %f, Bool: %d", p.getPrice(), p.canDecreasePrice());
    }

    // Price should not be negative after attempting to decrement below zero
    QVERIFY(p.getPrice() >= 0.0f);
}

/**
 * @brief _TestPencilInvetory::sellPencils
 * test case for producing and selling pencils
 */
void _Test::sellPencils()
{
    Pencil_Inventory p;
    Graphite_Inventory graphite;
    Wood_Inventory wood;
    Wallet w;
    // Produce 5 pencils
    p.producePencil(graphite, wood, 5);
    int pencilsProduced = p.getTotalNumberOfPencilsProduced();
    QCOMPARE(pencilsProduced, p.getTotalNumberOfPencilsProduced());

    for(int i = 0; i < 3; i++)
    {
        p.sellPencil(w);
    }
    QCOMPARE(p.getAmount(), 2);
}

/**
 * @brief _Test::testWallet
 * tests the functionality of the wallet class
 */
void _Test::testWallet()
{
    Wallet w;
    // check default value of bank balance
    QCOMPARE(w.getBankBalance(), 145.00);

    w.creditMoney(5.0);
    // should not be able to credit negative amount
    w.creditMoney(-10.0);
    QCOMPARE(w.getBankBalance(), 150.00);

    // try to debit a negative amount
    w.debitMoney(-5.0);
    QCOMPARE(w.getBankBalance(), 150.00);
    w.debitMoney(10.0);
    QCOMPARE(w.getBankBalance(), 140.00);

    // should not be able to debit more than bank balance
    w.debitMoney(200.0);
    QCOMPARE(w.getBankBalance(), 140.00);
}

/**
 * @brief _Test::testAPM
 * tests the functionality of the APM2000_Inventory class
 */
void _Test::testAPM()
{
   APM2000_Inventory apm;
   Wallet w;
   Pencil_Inventory p;
   Graphite_Inventory graphite;
   Wood_Inventory wood;


   w.debitMoney(145.00);
   // try to buy apm with no money
   apm.buyAPM2000(w);
   QCOMPARE(apm.getNumber(), 0);

   w.creditMoney(8000.0);
   float price = apm.getPrice();
   price *= 1.1f;
   apm.buyAPM2000(w);

   // price should be 10% higher after purchase
   QCOMPARE(price, apm.getPrice());
   // should have 1 APM after purchase
   QCOMPARE(apm.getNumber(), 1);

   // try to buy more than 10 APMs
   for(int i = 0; i < 12; i++)
   {
        apm.buyAPM2000(w);
   }
   QCOMPARE(apm.getNumber(), 10);

}

/**
 * @brief _Test::testMaterials
 * tests the functionality of the material_inventory superclass
 */
void _Test::testMaterials()
{
    Pencil_Inventory p;
    Graphite_Inventory graphite;
    Wood_Inventory wood;
    Wallet w;

    for(int i = 0; i < 1000; i++)
    {
        graphite.setPrice();
        wood.setPrice();

        // check if the prices go out of their range
        QVERIFY(graphite.getPrice() >= 1500.0f);
        QVERIFY(graphite.getPrice() <= 2500.0f);

        QVERIFY(wood.getPrice() >= 1000.0f);
        QVERIFY(wood.getPrice() <= 2000.0f);
    }

    // try to buy materials with no money
    w.debitMoney(145.00);
    graphite.buy(w);
    wood.buy(w);
    // amount should be default 1000
    QCOMPARE(graphite.getAmount(), 1000);
    QCOMPARE(wood.getAmount(), 1000);

    w.creditMoney(20000.00);
    graphite.buy(w);
    wood.buy(w);

    QCOMPARE(graphite.getAmount(), 1100.0);
    QCOMPARE(wood.getAmount(), 1100.0);
}

QTEST_APPLESS_MAIN(_Test)

#include "tst_test.moc"
