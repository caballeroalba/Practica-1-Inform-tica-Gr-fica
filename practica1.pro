HEADERS = \ 
    file_ply_stl.h \
    vertex.h \
    cubo.h \
    tetraedro.h

SOURCES = \
    practica1.cc \
    file_ply_stl.cc \
    cubo.cpp \
    tetraedro.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

