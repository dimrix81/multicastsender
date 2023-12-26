// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef SENDER_H
#define SENDER_H

#include <QHostAddress>
#include <QUdpSocket>
#include <QVector>
#include <QObject>
#include <QTimer>

class Sender : public QObject
{
    Q_OBJECT

public:
    explicit Sender(const uint32_t version_protocol, const QString &ip, const uint32_t port, double x, QObject *parent = nullptr);
    ~Sender();

private slots:
    void TimerOn();
    void TimerOn1();
    void sendDatagram(QByteArray *answer);
    void connectToServer();

    void readyRead();
    void saveFile();

private:
    QUdpSocket udpSocket4;
    QTimer timer_start;
    QTimer timer_timeout;
    QHostAddress groupAddress4;
    const uint32_t port;
    double *datagram_from_server = nullptr;
    uint32_t size_array;
    uint32_t link;
    const uint32_t version_protocol;
    bool is_connected = false;
    uint8_t calc_resend = 0;
    double x;
};

#endif
