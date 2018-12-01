#ifndef LISTITEM_H
#define LISTITEM_H

#include <QObject>

class ListItem
{
//    Q_PROPERTY(QString source READ source WRITE setSource)
public:
    ListItem() {}
    QString imgSource() const { return _imgSource; }
    void setImgSource(const QString &source) { _imgSource = source; }
    QString loaderSource() const { return _loaderSource; }
    void setLoaderSource(const QString &source) { _loaderSource = source; }
private:
    QString _imgSource;
    QString _loaderSource;
};

#endif // LISTITEM_H
