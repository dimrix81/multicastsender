// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QCoreApplication>
#include "sender.h"
#include "QtXml"
#include "qfile.h"

bool load_settings(uint32_t &version_protocol, QString &ip, uint32_t &port, double &x)
{
    QFile xmlFile("settings.xml");
    if (!xmlFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error read file config";
        xmlFile.close();
        return false;
    }

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&xmlFile);
    xmlReader.readNext();
    uint8_t i = 0;

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name() == QString("host"))
            {
                ip = xmlReader.readElementText();
                qDebug() << "ip: " << ip;
                i++;
            }
            else if (xmlReader.name() == QString("port")){
                port = xmlReader.readElementText().toInt();
                qDebug() << "port: " << port;
                i++;
            }
            else if (xmlReader.name() == QString("value_x")){
                x = xmlReader.readElementText().toDouble();
                qDebug() << "x: " << x;
                i++;
            }
            else if (xmlReader.name() == QString("version")){
                version_protocol = xmlReader.readElementText().toInt();
                qDebug() << "version_protocol: " << version_protocol;
                i++;
            }
        }
        xmlReader.readNext(); // Go to the next file element
    }

    xmlFile.close();
    return (i == 4);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    uint32_t version_protocol;
    QString ip;
    uint32_t port;
    double x;
    if (!load_settings(version_protocol, ip, port, x))
    {
        QCoreApplication::quit();
    }
    Sender sender(version_protocol, ip, port, x);
    return app.exec();
}
