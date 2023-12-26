// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef SENDER_H
#define SENDER_H

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>

class Sender : public QDialog
{
    Q_OBJECT

public:
    explicit Sender(const uint32_t version_protocol, const QString &ip, double x, QWidget *parent = nullptr);
    ~Sender();

private slots:
    void ttlChanged(int newTtl);
    // void startSending();
    void TimerOn();
    void TimerOn1();
    void sendDatagram(QByteArray *answer);
    void connectToServer();

    void readyRead();
    void saveFile();

private:
    QLabel *statusLabelMy = nullptr;
    QLabel *statusLabel = nullptr;
    // QPushButton *startButton = nullptr;
    QUdpSocket udpSocket4;
    // QUdpSocket udpSocket6;
    QTimer timer;
    QTimer timer_timeout;
    QHostAddress groupAddress4;
    // QHostAddress groupAddress6;
    int messageNo = 1;
    double *datagram_from_server = nullptr;
    uint32_t size_array;
    uint32_t link;
    const uint32_t version_protocol;
    bool is_connected = false;
    uint8_t calc_resend = 0;
    double x;
};

#endif
