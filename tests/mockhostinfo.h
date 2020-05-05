#ifndef MOCKHOSTINFO_H
#define MOCKHOSTINFO_H

#include "../src/abstracthostinfo.h"

class MockHostInfo : public AbstractHostInfo
{
    Q_OBJECT
public:
    MockHostInfo(QObject *parent = nullptr);
    virtual void lookupHost(QString);
public slots:
    void setErrorString(QString);

private:
    QString m_errorStr;
};

#endif // MOCKHOSTINFO_H
