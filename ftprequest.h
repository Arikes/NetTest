#ifndef FTPREQUEST_H
#define FTPREQUEST_H

#include <QObject>

class FtpRequest : public QObject
{
    Q_OBJECT
public:
    explicit FtpRequest(QObject *parent = 0);

signals:

public slots:
};

#endif // FTPREQUEST_H
