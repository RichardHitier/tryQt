
TEMPLATE = app
TARGET = signalsNslots
INCLUDEPATH += .

QT+=widgets

# Input
SOURCES  = signalsNslots.cpp \
           emitter.cpp \ 
           receiver.cpp

HEADERS  = emitter.h \
           receiver.h
