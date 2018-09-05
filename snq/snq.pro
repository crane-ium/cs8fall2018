TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    snq_unittest.cpp

HEADERS += \
    my_queue.h \
    my_stack.h \
    my_list.h \
    snq_unittest.h
