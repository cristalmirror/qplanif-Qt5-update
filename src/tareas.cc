#include "tipos.h"
#include "tareas.hh"
#include <QTreeWidgetItem>
#include <QColor>

Tareas_ventana::Tareas_ventana() : QTreeWidget(NULL) {
    setColumnCount(2);
    QStringList headers;
    headers << "Atributo" << "Valor";
    setHeaderLabels(headers);
    setColumnWidth(0, 200);
    setColumnWidth(1, 50);
    setFixedWidth(250);

    for (int x = 0; x < num_tareas; x++) {
        QTreeWidgetItem *tmp = new QTreeWidgetItem(this);
        tmp->setText(0, Tareas[x].nombre);

        char cade[100];
        sprintf(cade, "%d", Tareas[x].prioridad);
        QTreeWidgetItem *it1 = new QTreeWidgetItem(tmp);
        it1->setText(0, "Prioridad"); it1->setText(1, cade);

        sprintf(cade, "%d", Tareas[x].periodo);
        QTreeWidgetItem *it2 = new QTreeWidgetItem(tmp);
        it2->setText(0, "Periodo"); it2->setText(1, cade);

        sprintf(cade, "%d", (int)Tareas[x].llegada);
        QTreeWidgetItem *it3 = new QTreeWidgetItem(tmp);
        it3->setText(0, "Llegada"); it3->setText(1, cade);

        QTreeWidgetItem *sub = new QTreeWidgetItem(tmp);
        sub->setText(0, "Secuencia de Ejecucion");

        for (int y = 0; y < Tareas[x].Nsubtareas; y++) {
            char str_computo[100];
            sprintf(str_computo, "%d", (int)Tareas[x].subtarea[y].tiempo);
            QTreeWidgetItem *si = new QTreeWidgetItem(sub);
            if (Tareas[x].subtarea[y].recurso == 0)
                si->setText(0, "CPU");
            else
                si->setText(0, Recursos[Tareas[x].subtarea[y].recurso].nombre);
            si->setText(1, str_computo);
        }
    }
    show();
}

Tareas_ventana::~Tareas_ventana() {}
