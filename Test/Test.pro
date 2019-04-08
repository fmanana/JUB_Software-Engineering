QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  ../Pencil-Producer/material_inventory.cpp ../Pencil-Producer/wallet.cpp ../Pencil-Producer/wood_inventory.cpp ../Pencil-Producer/graphite_inventory.cpp ../Pencil-Producer/pencil_inventory.cpp ../Pencil-Producer/apm2000_inventory.cpp \
    tst_test.cpp
