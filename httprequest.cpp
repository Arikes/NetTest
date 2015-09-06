#include "httprequest.h"

HttpRequest::HttpRequest(QObject *parent) : QObject(parent)
{
    manager=NULL;
}
HttpRequest::~HttpRequest()
{
    requestlist.clear();
    if(manager)
        delete manager;
}
void HttpRequest::addLogin(QString str_url)
{
    Requeststring temp;
    temp.url=str_url;
    temp.type=e_Login;
    requestlist.push_back(temp);
}
void HttpRequest::addRegist(QString str_url)
{
    Requeststring temp;
    temp.url=str_url;
    temp.type=e_Regist;
    requestlist.push_back(temp);
}
void HttpRequest::addUpload(QString str_url)
{
    Requeststring temp;
    temp.url=str_url;
    temp.type=e_Upload;
    requestlist.push_back(temp);
}
void HttpRequest::startRequest()
{
    _composeLogin("dsa","123456");
//    QList<Requeststring>::iterator it=requestlist.begin();
//    while(it!=requestlist.end())
//    {
//        switch((*it).type)
//        {
//        case e_Login:
//            _composeLogin("dsa","123456");
//            break;
//        case e_Regist:
//            break;
//        case e_Upload:
//            break;
//        }
//    }
}
void HttpRequest::replyFinished(QNetworkReply *reply,eRequestType type)
{
    switch(type)
    {
    case e_Login:
        _parseLogin(reply);
        break;
    case e_Regist:
//        _parseRegist();
        break;
    case e_Upload:
//        _parseUpload();
        break;
    }
}
bool HttpRequest::_composeLogin(const QString &usrname,const QString &password)
{
    QJsonObject json;
    json.insert("type", usrname);
    json.insert("loginname", usrname);
    json.insert("password",password);
    json.insert("source",QString("movdo"));
    json.insert("regip",QString("172.16.137.9"));

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Indented);
//    QString json_str(byte_array);
//    qDebug("Json Result is :\n%s\n",json_str.toStdString().c_str());

    manager=new QNetworkAccessManager;
    request.setUrl(QUrl("http://passport.vboss.sobey.com/api/login"));
    QNetworkReply *reply=manager->put(request,byte_array);
    _parseLogin(reply);
//    connect(reply, SIGNAL(readyRead()),
//            this, SLOT(replyFinished(QNetworkReply *reply,eRequestType type)));
}
bool HttpRequest::_parseLogin(QNetworkReply *reply)
{
    QByteArray recData=reply->readAll();

        QJsonParseError json_error;
        QJsonDocument parse_doucment = QJsonDocument::fromJson(recData, &json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
            if(parse_doucment.isObject())
            {
                QJsonObject obj = parse_doucment.object();
                if(obj.contains("code"))
                {
                    QJsonValue code_value = obj.take("code");
                    double dcode;QString str_mess;
                    if(code_value.isDouble())
                    {
                        dcode=code_value.toDouble();
                        str_mess.setNum(dcode,'g');
//                         QString("delta: %1").arg(d, 0, 'E', 3);
                    }
                    else if(code_value.isString())
                    {
                        str_mess=code_value.toString();
                    }
                    if(!str_mess.compare("0"))
                    {
                        qDebug("success login");
//                        genelogfile(m_usrname,m_password);
//                        m_bLogined=true;
//                        emit bLoginedChanged(m_bLogined);
                        return true;
                    }
                    else
                    {
                        if(!str_mess.compare("10001"))
                            qDebug("password and user are error");
                        else if(!str_mess.compare("10003"))
                            qDebug("Don't have this user");
                        else if(!str_mess.compare("10004"))
                            qDebug("password is error");
//                        m_bLogined = false;
                        return false;
//                        emit bLoginedChanged(m_bLogined);
                    }
                }
            }
        }
}
