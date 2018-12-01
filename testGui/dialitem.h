#ifndef DIALITEM_H
#define DIALITEM_H

#include <QObject>

class DialItem
{
    Q_PROPERTY(QString loaderSource READ loaderSource WRITE setLoaderSource NOTIFY loaderSourceChanged)
    Q_PROPERTY(QString barIcon READ barIcon WRITE setBarIcon NOTIFY barIconChanged)
public:
    DialItem() {

    }

    QString barIcon() const {
        return _barIcon;
    }

    QString loaderSource() const {
        return _loaderSource;
    }

    void setBarIcon(const QString &image) {
        if(_barIcon == image)
            return;

        _barIcon = image;
    }

    void setLoaderSource(const QString &source) {
        if(_loaderSource == source)
            return;

        _loaderSource = source;
    }

signals:
    void loaderSourceChanged(const QString &source);
    void barIconChanged(const QString &image);

private:
    QString _barIcon;
    QString _loaderSource;
};

#endif // DIALITEM_H
