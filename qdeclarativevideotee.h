#ifndef QDECLARATIVEVIDEOTEE_H
#define QDECLARATIVEVIDEOTEE_H

#include <QObject>

class QVideoRendererControl;
class TeeSurface;
class QMediaObject;
class QMediaService;

class QDeclarativeVideoTee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QObject* videoSurface READ videoSurface WRITE addVideoOutput)
public:
    explicit QDeclarativeVideoTee(QObject *parent = 0);
    ~QDeclarativeVideoTee();

    QObject *source() const;
    void setSource(QObject *source);

    QObject *videoSurface() const { return 0; } // unused
    void addVideoOutput(QObject *output);

signals:
    void sourceChanged();

private slots:
    void updateMediaObject();
    void removeVideoOutput(QObject *output);

private:
    QObject *m_source;
    QMediaObject *m_mediaObject;
    QMediaService *m_mediaService;
    QVideoRendererControl *m_sourceRendererControl;
    TeeSurface *m_tee;
};

#endif // QDECLARATIVEVIDEOTEE_H
