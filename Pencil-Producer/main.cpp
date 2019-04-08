/**
  * @mainpage Pencil Producer
  * @section intro_sec Introduction
  * This project implements a pencil producer game where the player can produce
  * and sell pencils to the public. In order to produce pencils the player must
  * buy materials (wood, graphite). The player can increase and decrease the
  * price of pencils at any point, which decreases and increases the demand for
  * pencils respectively.
  * @section compile_sec Compilation
  * \code
  * $ cd se-02-team/Pencil-Producer/
  *
  * $ mkdir build
  *
  * $ cd build/
  *
  * $ cmake .. & make
  *
  * $ ./pencilproducer
  * \endcode
  */
#include "pencilproducer.h"
#include <QApplication>

/**
 * @param argc
 * @param argv
 * @return app.exec()
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PencilProducer pencilproducer;
    pencilproducer.show();

    return a.exec();
}
