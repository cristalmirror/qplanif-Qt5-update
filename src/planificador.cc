#include "planificador.hh"
#include <algorithm>
#include "SistemaCls.hh"
#include "EventosCls.hh"
#include "PlanifFCFS.hh"
#include "PlanifSJF.hh"
#include "PlanifSRTF.hh"
#include "PlanifPF.hh"
#include "PlanifRR.hh"
#include "PlanifPFRR.hh"

#include <QCheckBox>
#include <QPixmap>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QStatusBar>
#include <QMessageBox>
#include <QApplication>
#include <QTextStream>
#include <QPainter>
#include <QToolTip>
#include <QSpinBox>
#include <QLabel>
#include <QList>

extern "C" { int Parsea_fichero(char *); }

typedef QList<Planificador*> PlanificadorList;
static PlanificadorList *spawnedPlanificadores = 0;

Planificador::Planificador(int contador)
    : QMainWindow(0)
{
    int x;

    politica_planificador_actual = 0;
    politica_recurso_actual = 0;
    quantum_actual = 1;

    if (editor == 0)
        editor = new Editor(NULL, "Editor");

    if (num_tareas)
        Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                         Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);

    canvas = new Canvas(this, "Canvas");
    canvas->setFocus();
    setCentralWidget(canvas);

    connect(canvas, SIGNAL(hayQueRedibujar(bool)), this, SLOT(actualiza(bool)));

    // Toolbar paso a paso
    pasoTools = new QToolBar("Pasos", this);
    addToolBar(pasoTools);
    paso = new QCheckBox("Ejecucion paso a paso", pasoTools);
    pasoTools->addWidget(paso);
    paso->setChecked(true);
    pasoTools->addWidget(new QLabel("   Instante ", pasoTools));
    seleccion_paso = new QSpinBox(pasoTools);
    seleccion_paso->setRange(1, 10000);
    seleccion_paso->setSingleStep(1);
    pasoTools->addWidget(seleccion_paso);

    connect(seleccion_paso, SIGNAL(valueChanged(int)), this, SLOT(setPaso(int)));
    connect(paso, SIGNAL(toggled(bool)), seleccion_paso, SLOT(setEnabled(bool)));
    connect(paso, SIGNAL(toggled(bool)), this, SLOT(togglePaso(bool)));

    // Toolbar controles
    controlTools = new QToolBar("Herramientas", this);
    addToolBar(controlTools);

    QComboBox *seleccion_planificadores = new QComboBox(controlTools);
    controlTools->addWidget(seleccion_planificadores);
    char **NombrePlanificadores = Simulator.PlanifCPU();
    for (x = 0; NombrePlanificadores[x]; x++)
        seleccion_planificadores->addItem(NombrePlanificadores[x]);
    connect(seleccion_planificadores, SIGNAL(activated(int)), SLOT(planificador_elegido(int)));

    QComboBox *seleccion_recursos = new QComboBox(controlTools);
    controlTools->addWidget(seleccion_recursos);
    NombrePlanificadores = Simulator.PlanifRecursos();
    for (x = 0; NombrePlanificadores[x]; x++)
        seleccion_recursos->addItem(NombrePlanificadores[x]);
    connect(seleccion_recursos, SIGNAL(activated(int)), SLOT(recurso_elegido(int)));

    controlTools->addWidget(new QLabel("   Quantum ", controlTools));
    seleccion_quantum = new QSpinBox(controlTools);
    seleccion_quantum->setRange(1, 100);
    seleccion_quantum->setSingleStep(1);
    controlTools->addWidget(seleccion_quantum);
    connect(seleccion_quantum, SIGNAL(valueChanged(int)), this, SLOT(setQuantum(int)));
    seleccion_quantum->setEnabled(false);

    controlTools->addWidget(new QLabel("   Grid ", controlTools));
    QSpinBox *grid = new QSpinBox(controlTools);
    grid->setRange(0, 100);
    grid->setValue(1);
    grid->setSpecialValueText("No grid");
    controlTools->addWidget(grid);
    connect(grid, SIGNAL(valueChanged(int)), canvas, SLOT(setGrid(int)));

    controlTools->addWidget(new QLabel("   Zoom ", controlTools));
    QSpinBox *zoom = new QSpinBox(controlTools);
    zoom->setRange(0, 100);
    zoom->setValue(20);
    controlTools->addWidget(zoom);
    connect(zoom, SIGNAL(valueChanged(int)), canvas, SLOT(setZoom(int)));

    // Menu Archivos
    QMenu *file = new QMenu("&Archivos", this);
    menuBar()->addMenu(file);
    file->addAction("&Nueva ventana", this, SLOT(newDoc()), QKeySequence("Ctrl+N"));
    file->addAction("&Abrir",         this, SLOT(cargar()), QKeySequence("Ctrl+A"));
    file->addAction("&Editar",        editor, SLOT(show()), QKeySequence("Ctrl+E"));
    file->addSeparator();
    file->addAction("&Cerrar", this, SLOT(closeDoc()), QKeySequence("Ctrl+W"));
    file->addAction("&Salir",  qApp, SLOT(quit()),     QKeySequence("Ctrl+Q"));

    // Menu Controles
    controls = new QMenu("&Controles", this);
    menuBar()->addMenu(controls);
    thAction = controls->addAction("Barra de &Herramientas", this, SLOT(toggleHerrBar()), QKeySequence("Ctrl+H"));
    sbAction = controls->addAction("Barra de &Estado",       this, SLOT(toggleStatusBar()), QKeySequence("Ctrl+E"));
    thAction->setCheckable(true); thAction->setChecked(true);
    sbAction->setCheckable(true); sbAction->setChecked(true);

    menuBar()->addSeparator();

    QMenu *ayuda = new QMenu("&Ayuda", this);
    menuBar()->addMenu(ayuda);
    ayuda->addAction("&Autores",        this, SLOT(mostrarAutores()));
    ayuda->addAction("&Temas de Ayuda", this, SLOT(mostrarAyuda()), QKeySequence(Qt::Key_F1));
    ayuda->addSeparator();
    ayuda->addAction("Acerca de &Qt",   this, SLOT(aboutQt()));

    statusBar()->showMessage("Preparado");

    connect(this, SIGNAL(tareasNuevas(int)), this, SLOT(setTareasNuevas(int)));
    connect(this, SIGNAL(ParseErrorEn(int)), editor, SLOT(RemarcaLinea(int)));
    connect(editor, SIGNAL(re_carga(const char*)), this, SLOT(cargar(const char*)));

    num_lect = contador;
}

Planificador::~Planificador() {
    if (spawnedPlanificadores) {
        spawnedPlanificadores->removeAll(this);
        if (spawnedPlanificadores->count() == 0) {
            delete spawnedPlanificadores;
            spawnedPlanificadores = 0;
        }
    }
}

void Planificador::newDoc() {
    if (!spawnedPlanificadores)
        spawnedPlanificadores = new PlanificadorList;
    Planificador *ed = new Planificador(num_lect);
    spawnedPlanificadores->append(ed);
    connect(this, SIGNAL(tareasNuevas(int)), ed, SLOT(setTareasNuevas(int)));
    connect(ed,   SIGNAL(tareasNuevas(int)), this, SLOT(setTareasNuevas(int)));
    ed->show();
}

void Planificador::cargar(const char *nombre) {
    int linea_error = Parsea_fichero((char*)nombre);
    if (y_error != -1) {
        statusBar()->showMessage("Carga Abortada");
        canvas->Limpia();
        num_tareas = 0;
        QMessageBox::warning(editor, "Error de carga", y_mensaje);
        emit ParseErrorEn(linea_error);
    }
    emit tareasNuevas(num_lect+1);
}

void Planificador::cargar() {
    char nombre[1000];
    statusBar()->showMessage("Cargar fichero de especificacion de tareas.");

    QString fn = QFileDialog::getOpenFileName(0, "Abrir..", "", "*.def");
    if (!fn.isEmpty()) {
        if (fn.length() >= 1000) return;
        QByteArray ba = fn.toLocal8Bit();
        strncpy(nombre, ba.constData(), 999);
        nombre[999] = 0;

        Parsea_fichero(nombre);
        editor->load(nombre);

        if (y_error != -1) {
            statusBar()->showMessage("Carga Abortada");
            canvas->Limpia();
            num_tareas = 0;
            QMessageBox::warning(editor, "Error de carga", y_mensaje);
            return;
        }
        emit tareasNuevas(num_lect+1);
    } else {
        statusBar()->showMessage("Carga Abortada");
    }
}

void Planificador::setTareasNuevas(int lecturas) {
    if (num_lect != lecturas) {
        num_lect = lecturas;
        Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                         Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
        actualiza(true);
        emit tareasNuevas(lecturas);
    }
}

struct dibuja_canvas : public std::unary_function<evento_c, void>
{
    dibuja_canvas(Canvas &canvas, bool paso_a_paso=false, int pos=0)
        : cv(canvas), pap(paso_a_paso), fin(pos) {}
    void operator()(const evento_c &ev) const {
        if (!pap || ev.Inicio() < (tiempo_t)fin)
            cv.Dibuja(ev);
    }
    bool pap;
    int fin;
    Canvas &cv;
};

void Planificador::actualiza(bool hay_que_limpiar) {
    char cade[1000];
    tiempo_t computo;

    if (!num_tareas) return;

    if (hay_que_limpiar)
        canvas->Limpia();

    for (int x = 0; x < num_tareas; x++) {
        computo = 0;
        for (int y = 0; y < Tareas[x].Nsubtareas; y++)
            computo += Tareas[x].subtarea[y].recurso ? 0 : Tareas[x].subtarea[y].tiempo;
        sprintf(cade, "Prio:\t%d\nLlegada:\t%d\nPerid:\t%d\nComputo:\t%d",
                Tareas[x].prioridad, (int)Tareas[x].llegada,
                (int)Tareas[x].periodo, (int)computo);
        canvas->Dibuja(x, Tareas[x].nombre, cade);
    }

    if (paso->isChecked()) {
        for_each(lst_eventos.begin(), lst_eventos.end(),
                 trocea_eventos(lst_ord_eventos));
        for_each(lst_ord_eventos.begin(), lst_ord_eventos.end(),
                 dibuja_canvas(*canvas, paso->isChecked(), seleccion_paso->value()));
    } else {
        for_each(lst_eventos.begin(), lst_eventos.end(),
                 dibuja_canvas(*canvas));
    }
    canvas->finalizado_dibujo();
}

void Planificador::setPaso(int) {
    Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                     Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
    actualiza(true);
}

void Planificador::togglePaso(bool) {
    Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                     Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
    actualiza(true);
}

void Planificador::setQuantum(int quant) {
    quantum_actual = quant;
    Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                     Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
    actualiza(true);
}

void Planificador::closeDoc() { close(); }

void Planificador::closeEvent(QCloseEvent *) {
    if (spawnedPlanificadores && spawnedPlanificadores->indexOf(this) != -1)
        delete this;
    else
        hide();
}

void Planificador::toggleHerrBar() {
    if (controlTools->isVisible()) {
        controlTools->hide();
        pasoTools->hide();
        thAction->setChecked(false);
    } else {
        controlTools->show();
        pasoTools->show();
        thAction->setChecked(true);
    }
}

void Planificador::toggleStatusBar() {
    if (statusBar()->isVisible()) {
        statusBar()->hide();
        sbAction->setChecked(false);
    } else {
        statusBar()->show();
        sbAction->setChecked(true);
    }
}

void Planificador::planificador_elegido(int plan) {
    politica_planificador_actual = plan;
    seleccion_quantum->setEnabled((plan==4) || (plan==7));
    Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                     Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
    actualiza(true);
}

void Planificador::recurso_elegido(int rec) {
    politica_recurso_actual = rec;
    Simulator.Simula(politica_planificador_actual, politica_recurso_actual,
                     Tareas, num_tareas, num_recursos, 500, quantum_actual, lst_eventos);
    actualiza(true);
}

void Planificador::aboutQt() {
    QMessageBox::aboutQt(this, "Planificador desarrollado con:");
}

void Planificador::mostrarAutores() {
    QMessageBox::about(this, "Planificador",
                       "Desarrollado por:\nIsmael Ripoll y Sergio Saez\nDISCA, UPV");
}

void Planificador::mostrarAyuda() {
    new AyudaCls(NULL, "Ayuda");
}
