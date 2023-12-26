// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QCoreApplication>
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Sender sender(1, "192.168.0.122", 200);
    return app.exec();
}
