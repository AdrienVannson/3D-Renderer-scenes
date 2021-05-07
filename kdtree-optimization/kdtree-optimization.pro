QT += core gui widgets

TARGET = KD-Tree-optimization
TEMPLATE = app
CONFIG += c++11

INCLUDEPATH += renderer/
include(renderer/3D-Renderer.pri)

SOURCES += main.cpp
