TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        customer.cpp \
        file.cpp \
        main.cpp \
        order.cpp \
        product.cpp \
        shop.cpp

HEADERS += \
    customer.h \
    file.h \
    order.h \
    product.h \
    shop.h
