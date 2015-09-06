#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QString>
#include <QFile>
#include <QObject>
enum eRequestType
{
    e_Login=0,
    e_Regist=1,
    e_Upload=2,
    e_Download=3
};
typedef struct Requeststring
{
    QString url;
    eRequestType type;
}Requeststring;

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    explicit HttpRequest(QObject *parent = 0);
    ~HttpRequest();
signals:

public slots:
    void addLogin(QString str_url);
    void addRegist(QString str_url);
    void addUpload(QString str_url);

    void startRequest();
    void replyFinished(QNetworkReply *reply,eRequestType type);

private slots:
    bool _parseLogin(QNetworkReply *reply);
//    bool _parseRegist();
//    bool _parseUpload();

    bool _composeLogin(const QString &usrname,const QString &password);
//    bool _composeRegist();
//    bool _composeUpload();
private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    QList<Requeststring> requestlist;
};

#endif // HTTPREQUEST_H
