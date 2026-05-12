#include <stdlib.h>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include "ayuda.hh"

const char* ayuda_general      = "Ayuda general del simulador de planificacion.\n";
const char* ayuda_tareas        = "Descripcion de tareas.\n";
const char* ayuda_descripcion   = "Descripcion del sistema.\n";
const char* ayuda_FCFS          = "First Come First Served.\n";
const char* ayuda_RR            = "Round Robin.\n";
const char* ayuda_SJF           = "Shortest Job First.\n";
const char* ayuda_prioridades   = "Planificacion por prioridades.\n";
const char* ayuda_prioridades_expulsivas = "Prioridades expulsivas.\n";
const char* ayuda_prioridades_RR = "Prioridades con Round Robin.\n";
const char* ayuda_SRTF          = "Shortest Remaining Time First.\n";

typedef QList<AyudaCls*> AyudaClsList;
static AyudaClsList *spawnedAyudaClss = 0;

AyudaCls::AyudaCls(QWidget *parent, const char *name)
    : QWidget(parent)
{
    if (name) setObjectName(name);

    m = new QMenuBar(this);

    QMenu *files = new QMenu("Archivos", this);
    m->addMenu(files);
    files->addAction("Nueva ventana", this, SLOT(newDoc()));
    files->addAction("Cerrar",        this, SLOT(closeDoc()));

    temas = new QMenu("Temas de Ayuda", this);
    m->addMenu(temas);

    temas->addAction("General");         Ayudas["General"]                   = ayuda_general;
    temas->addAction("Tareas");          Ayudas["Tareas"]                    = ayuda_tareas;
    temas->addSeparator();
    temas->addAction("Descripcion");     Ayudas["Descripcion"]               = ayuda_descripcion;
    temas->addAction("FCFS");            Ayudas["FCFS"]                      = ayuda_FCFS;
    temas->addAction("SJF");             Ayudas["SJF"]                       = ayuda_SJF;
    temas->addAction("SRTF");            Ayudas["SRTF"]                      = ayuda_SRTF;
    temas->addAction("Round Robin");     Ayudas["Round Robin"]               = ayuda_RR;
    temas->addAction("Prioridades");     Ayudas["Prioridades"]               = ayuda_prioridades;
    temas->addAction("Prioridades Expulsivas"); Ayudas["Prioridades Expulsivas"] = ayuda_prioridades_expulsivas;
    temas->addAction("Prioridades + Round Robin"); Ayudas["Prioridades + Round Robin"] = ayuda_prioridades_RR;

    connect(temas, SIGNAL(triggered(QAction*)), this, SLOT(ayuda_elegida(int)));
    // Usamos índice vía triggered(QAction*)
    // Reconectamos con lambda-compatible slot
    disconnect(temas, SIGNAL(triggered(QAction*)), this, SLOT(ayuda_elegida(int)));
    connect(temas, &QMenu::triggered, [this](QAction *a){
        const char *key = a->text().toLocal8Bit().constData();
        // buscar en el mapa
        std::string k(a->text().toStdString());
        for (auto &p : Ayudas) {
            if (std::string(p.first) == k) {
                load(p.second);
                return;
            }
        }
    });

    e = new QTextEdit(this);
    e->setReadOnly(true);
    load(ayuda_general);
    e->setFocus();
    resize(400, 400);
    show();
}

AyudaCls::~AyudaCls() {
    if (spawnedAyudaClss) {
        spawnedAyudaClss->removeAll(this);
        if (spawnedAyudaClss->count() == 0) {
            delete spawnedAyudaClss;
            spawnedAyudaClss = 0;
        }
    }
}

void AyudaCls::newDoc() {
    if (!spawnedAyudaClss)
        spawnedAyudaClss = new AyudaClsList;
    AyudaCls *ed = new AyudaCls;
    spawnedAyudaClss->append(ed);
    ed->resize(400, 400);
    ed->show();
}

void AyudaCls::load(const char *help_name) {
    e->clear();
    e->setPlainText(QString::fromLocal8Bit(help_name));
}

void AyudaCls::closeDoc() {
    close();
}

void AyudaCls::resizeEvent(QResizeEvent *) {
    if (e && m)
        e->setGeometry(0, m->height(), width(), height() - m->height());
}

void AyudaCls::closeEvent(QCloseEvent *) {
    if (spawnedAyudaClss && spawnedAyudaClss->indexOf(this) != -1)
        delete this;
    else
        hide();
}

void AyudaCls::ayuda_elegida(int) {}
