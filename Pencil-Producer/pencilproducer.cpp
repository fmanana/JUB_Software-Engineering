/**
 *  @file     PencilProducer.cpp
 *  @brief    The logic of the calculator.
 *  @author   Ardit Shala
 *  @include  PencilProducer.h
 */

#include "pencilproducer.h"
#include "ui_pencilproducer.h"

PencilProducer::PencilProducer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PencilProducer)
{
    ui->setupUi(this);
    update();
    startTimer();
}

PencilProducer::~PencilProducer()
{
    delete ui;
}

/**
 * @brief PencilProducer::update
 * updates all values displayed on the UI and
 */
void PencilProducer::update()
{
    QString str;
    int pencilsProduced = pencilInventory.getTotalNumberOfPencilsProduced();
    float publicDemand = pencilInventory.getPublicDemand();
    int pencilsInInventory = pencilInventory.getAmount();
    float priceOfPencil = pencilInventory.getPrice();
    float woodLeft = woodInventory.getAmount();
    float graphiteLeft = graphiteInventory.getAmount();
    float bankBalance = wallet.getBankBalance();
    int autoPencil2000 = apm2000Inventory.getNumber();
    float priceOfWood = woodInventory.getPrice();
    float priceOfGraphite = graphiteInventory.getPrice();
    float priceOfAPM2000 = apm2000Inventory.getPrice();
    int rate = apm2000Inventory.getRate();

    // Update Values in order to show the changes occurred
    str.setNum(pencilsProduced);
    ui->pencilsProduced->setText("<html>Pencils Produced (to date): <b>" + str + "</b></html>");

    str.setNum(publicDemand, 'f', 2);
    ui->publicDemand->setText("<html>Public Demand: <b>" + str + "</b></html>");

    str.setNum(pencilsInInventory);
    ui->pencilsInInventory->setText("<html>Pencils in Inventory: <b>" + str + "</b></html>");

    str.setNum(priceOfPencil, 'f', 2);
    ui->priceOfPencil->setText("<html>Price of Pencil: <b>$" + str + "</b></html>");

    str.setNum(woodLeft, 'f', 2);
    ui->woodLeft->setText("<html>Wood Left: <b>" + str + " m</b></html>");

    str.setNum(graphiteLeft, 'f', 2);
    ui->graphiteLeft->setText("<html>Graphite Left: <b>" + str + " m</b></html>");

    str.setNum(bankBalance, 'f', 2);
    ui->bankBalance->setText("<html><b><p style=\"text-align: right; font-size: 30px\">$" + str + "</p></b></html>");

    str.setNum(autoPencil2000);
    ui->autoPencil2000->setText("<html><p style=\"text-align: right\">AutoPencil2000: <b>" + str + "</b></p></html>");

    str.setNum(priceOfWood, 'f', 2);
    ui->buyWood->setText("Buy Wood \n$" + str + " / 100.00 m");

    str.setNum(priceOfGraphite, 'f', 2);
    ui->buyGraphite->setText("Buy Graphite \n$" + str + " / 100.00 m");

    str.setNum(priceOfAPM2000, 'f', 2);
    ui->buyMore->setText("Buy More \n$" + str);

    str.setNum(rate);
    ui->rate->setText("<html><p style=\"text-align: right\">Rate: <b>" + str + "</b> pencils / minute</p></html>");

    //Disable a button when there is not enough money in the wallet.
    ui->makePencil->setEnabled(pencilInventory.canProducePencil(graphiteInventory, woodInventory));
    ui->buyWood->setEnabled(woodInventory.canBuy(wallet));
    ui->buyGraphite->setEnabled(graphiteInventory.canBuy(wallet));
    ui->buyMore->setEnabled(apm2000Inventory.canBuyAPM2000(wallet));
}

//Begin a timer which uses the function "updateAll".
void PencilProducer::startTimer()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PencilProducer::updateAll);
    timer->start(500);
}

void PencilProducer::on_minus_clicked()
{
    pencilInventory.decreasePrice();
    update();
}

void PencilProducer::on_plus_clicked()
{
    pencilInventory.increasePrice();
    update();
}

void PencilProducer::on_buyWood_clicked()
{
    woodInventory.buy(wallet);
    update();
}

void PencilProducer::on_buyGraphite_clicked()
{
    graphiteInventory.buy(wallet);
    update();
}

void PencilProducer::on_makePencil_clicked()
{
    pencilInventory.producePencil(graphiteInventory, woodInventory);
    update();
}

void PencilProducer::on_buyMore_clicked()
{
    apm2000Inventory.buyAPM2000(wallet);
    update();
}

void PencilProducer::updateAll()
{
    static int count = 1;
    static int counter = 0;

    //Produce and Sell a Pencil every one second.
    if (counter % 2 == 0) {
        apm2000Inventory.producePencil(pencilInventory, graphiteInventory, woodInventory);
        counter++;
    }
    else
    {
        pencilInventory.sellPencil(wallet, pencilInventory.getNumberOfPencilsToBeSold());
        counter = 0;
    }
    //Change the Price Of Wood/Graphite every five seconds. /10 * 500msec = 5sec/
    if (count % 10 == 0)
    {
        count = 1;
        woodInventory.setPrice();
        graphiteInventory.setPrice();
    }
    else
        count++;

    update();
}


