TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    list.cpp \
    main.cpp \
    my_queue.cpp \
    my_stack.cpp \
    stack_unittest.cpp

HEADERS += \
    list.h \
    my_queue.h \
    my_stack.h \
    stack_unittest.h
