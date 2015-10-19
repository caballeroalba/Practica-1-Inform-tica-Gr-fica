HEADERS = \ 
    file_ply_stl.h \
    vertex.h

SOURCES = \
    practica1.cc \
    file_ply_stl.cc

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

