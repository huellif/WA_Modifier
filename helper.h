#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper: public QObject
{
    Q_OBJECT

public:

    Q_INVOKABLE void launch() const;

    Q_INVOKABLE void close(/*bool hidden*/);

    Q_INVOKABLE void hide();

    Q_INVOKABLE void reset() const;

    Q_INVOKABLE void resetNote();

    Q_INVOKABLE void note() const;

    Q_INVOKABLE void icon(QString mif) const;

    Q_INVOKABLE void del() const;

    Q_INVOKABLE void reboot() const;

    Q_INVOKABLE void clear();

private:

    void kill(const int &a) const;
};

#endif // HELPER_H
