#ifndef GRAVITYSIM_H
#define GRAVITYSIM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GravitySim; }
QT_END_NAMESPACE

class GravitySim : public QMainWindow
{
    Q_OBJECT

public:
    GravitySim(QWidget *parent = nullptr);
    ~GravitySim();

private:
    Ui::GravitySim *ui;
protected:
    //void paintEvent(QPaintEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *ev);
};
#endif // GRAVITYSIM_H
