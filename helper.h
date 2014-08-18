#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper: public QObject
{
    Q_OBJECT

public:

    Q_INVOKABLE void launch() const;

    Q_INVOKABLE void close() const;

    Q_INVOKABLE void note() const;

    Q_INVOKABLE void icon(const QString &mif) const;

    Q_INVOKABLE void del() const;

    Q_INVOKABLE void reboot() const;

    Q_INVOKABLE void clear();

private:

    TAny kill(const TDesC &process) const;

    TBool remove() const;

    TAny error() const;
};

#endif // HELPER_H
