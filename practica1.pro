HEADERS = \ 
    file_ply_stl.h \
    vertex.h \
    cubo.h

SOURCES = \
    practica1.cc \
    file_ply_stl.cc \
    cubo.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

