#ifndef DIRVIEW_H
#define DIRVIEW_H

#include <QString>
#include <stdio.h>
#include "tipos.h"
#include <QTreeWidget>

class Tareas_ventana : public QTreeWidget {
    Q_OBJECT
public:
    Tareas_ventana();
    ~Tareas_ventana();
};

#endif
