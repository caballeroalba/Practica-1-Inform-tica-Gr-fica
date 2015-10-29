HEADERS = \ 
    file_ply_stl.h \
    vertex.h \
    cubo.h \
    tetraedro.h \
    objeto3d.h \
    edge.h \
    triangle.h \
    file_ply_stl.hpp \
    figuraply.h

SOURCES = \
    practica1.cc \
    file_ply_stl.cc \
    cubo.cpp \
    tetraedro.cpp \
    objeto3d.cpp \
    edge.cpp \
    triangle.cpp \
    figuraply.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

