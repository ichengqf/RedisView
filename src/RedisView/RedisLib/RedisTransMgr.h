/**
* @file      RedisTransMgr.h
* @brief     REDIS客户端传输类
* @author    wangcc3
* @date      2018-11-24
* @version   001
* @copyright Copyright (c) 2018
*/

#ifndef REDISTRANSMGR_H
#define REDISTRANSMGR_H

#include <RedisLib/RedisRespParser.h>

/**
 * Redis内存数据库TCP通信类
 */
class RedisTransMgr : public QObject, public RedisRespParser
{
    Q_OBJECT

public:

    RedisTransMgr(const QString &hostAddress, quint16 port, QObject *parent = nullptr);
    RedisTransMgr(QObject *parent = nullptr);
    ~RedisTransMgr();

    void write(const QByteArray &data);
    void write(const QString &str);
    bool isOpen();
    void open();
    void open(const QString &hostAddress, quint16 port);
    void open(const QHostAddress &hostAddress, quint16 port);
    void close();

    QString getHostAddress() { return _hostAddress.toString(); }
    void setHostAddress(const QString &hostAddress);

    int getPort() { return _nPort; }
    void setPort(quint16 port);

private:

    int _length;
    quint16 _nPort;
    QTcpSocket *_socket;
    QByteArray _msg;
    QHostAddress _hostAddress;

private:

    void initTransMgr();

signals:

    void sigConnected();
    void sigDisconnected();
    void sigError(const QString &sError);
    void sigReply(const QByteArray &msg, const int &length);
};

#endif // REDISTRANSMGR_H
