#ifndef CANVAS_H
#define CANVAS_H

#include <QColor>
#include <QFrame>
#include <QMatrix>
#include <QScrollBar>
#include "EventosCls.hh"

#define ESPACIO_REGLA 40

class Pizarra_Cls : public QFrame {
    Q_OBJECT
signals:
    void hayQueRedibujar();
public:
    Pizarra_Cls(QWidget *parent=0, const char *name=0)
        : QFrame(parent) { if(name) setObjectName(name); }

protected:
    void paintEvent(QPaintEvent *p) {
        QFrame::paintEvent(p);
        emit hayQueRedibujar();
    }
};

class Canvas : public QWidget {
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);

public slots:
    void Dibuja(const evento_c &);
    void Dibuja(int, const char *, const char *tip=0);
    void Limpia();
    void setZoom(int);
    void setGrid(int);
    void setScroll(int);
    void reenvia();

public:
    Canvas(QWidget *parent=0, const char *name=0);
    void finalizado_dibujo();

private:
    void Dibuja();

    QMatrix mat_escalado;
    int grid;
    int zoom;
    float scroll;
    Pizarra_Cls *area_de_nombres;
    Pizarra_Cls *area_de_cronograma;
    QScrollBar  *hscroll;
    int final_simulacion;

signals:
    void hayQueRedibujar(bool);
};

#endif
