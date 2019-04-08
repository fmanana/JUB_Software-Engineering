/**
 *  @file     PencilProducer.h
 *  @brief    Class and method declarations.
 *  @author   Ardit Shala
 *  @include  ui_PencilProducer.h
 */

#ifndef PENCILPRODUCER_H
#define PENCILPRODUCER_H

#include <QMainWindow>
#include "apm2000_inventory.h"
#include <QTimer>

namespace Ui {
class PencilProducer;
}

/**
 *  @class  PencilProducer
 *  @brief  Class to implement the Pencil Producer game
 *  @detail In this class we will define the constructor/descructor and all the other methods we need to make it run. As for the first Spring, we are in need of a cons/dest only.
 */

class PencilProducer : public QMainWindow
{
    Q_OBJECT

public:
    /**
     *   Default constructor.
     */
    explicit PencilProducer(QWidget *parent = nullptr);
    /**
     * Default desctructor.
     */
    ~PencilProducer();

private slots:
    void on_minus_clicked();

    void on_plus_clicked();

    void on_buyWood_clicked();

    void on_buyGraphite_clicked();

    void on_makePencil_clicked();

    void on_buyMore_clicked();

    void updateAll();

private:
    /** Create the UI widget for the window
         */
    Ui::PencilProducer *ui;
    Wallet wallet;
    Graphite_Inventory graphiteInventory;
    Wood_Inventory woodInventory;
    Pencil_Inventory pencilInventory;
    APM2000_Inventory apm2000Inventory;
    void update();
    void startTimer();
};

#endif // PENCILPRODUCER_H
