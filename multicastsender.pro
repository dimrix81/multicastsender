QT = core

CONFIG += c++17 cmdline

QT += network
requires(qtConfig(udpsocket))

HEADERS       = sender.h
SOURCES       = sender.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/multicastsender
INSTALLS += target

