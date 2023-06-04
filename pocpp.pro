TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        customer.cpp \
        main.cpp \
        order.cpp \
        product.cpp

HEADERS += \
    customer.h \
    order.h \
    product.h
