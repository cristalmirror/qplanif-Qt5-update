#include "editor.hh"
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QMenu>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextBlock>

Editor::Editor(QWidget *parent, const char *name)
    : QWidget(parent)
{
    if (name) setObjectName(name);

    m = new QMenuBar(this);
    s = new QStatusBar(this);

    QMenu *file = new QMenu("&Archivo", this);
    m->addMenu(file);

    file->addAction("&Nuevo",  this, SLOT(newFile()),  QKeySequence("Ctrl+N"));
    file->addAction("&Guardar", this, SLOT(save()),    QKeySequence("Ctrl+G"));
    file->addAction("Guardar Como", this, SLOT(saveAs()), QKeySequence("Ctrl+C"));
    file->addSeparator();
    file->addAction("Cerrar", this, SLOT(close()),     QKeySequence("Ctrl+W"));

    e = new Papel_t(this);
    e->setFocus();

    connect(e, SIGNAL(cursor_Changed()), this, SLOT(update_status()));

    hide();
}

Editor::~Editor() {
    delete m;
    delete s;
    delete e;
}

void Editor::load() {
    QString fn = QFileDialog::getOpenFileName(this);
    if (!fn.isEmpty()) {
        Nombre_fichero = fn;
        load(fn.toLocal8Bit().constData());
    }
}

void Editor::newFile() {
    Nombre_fichero = "Nuevo.def";
    e->setText("");
    setWindowTitle(Nombre_fichero);
    emit re_carga("");
}

void Editor::load(const char *fileName) {
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly))
        return;

    Nombre_fichero = fileName;
    e->clear();

    QTextStream t(&f);
    e->setPlainText(t.readAll());
    f.close();

    setWindowTitle(Nombre_fichero);
    update_status();
}

void Editor::save() {
    if (Nombre_fichero.isEmpty()) {
        saveAs();
    } else {
        QFile f(Nombre_fichero);
        if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
        QTextStream t(&f);
        t << e->toPlainText();
        f.close();
    }
    emit re_carga(Nombre_fichero.toLocal8Bit().constData());
}

void Editor::saveAs() {
    QString fn = QFileDialog::getSaveFileName(this, "Guardar Como..", "", "*.def");
    if (!fn.isEmpty()) {
        Nombre_fichero = fn;
        save();
        setWindowTitle(Nombre_fichero);
    }
}

void Editor::close() {
    hide();
}

void Editor::resizeEvent(QResizeEvent *) {
    e->setGeometry(0, m->height(), width(), height() - m->height() - s->height());
    s->setGeometry(0, height() - s->height(), width(), s->height());
}

void Editor::closeEvent(QCloseEvent *) {
    hide();
}

void Editor::RemarcaLinea(int posicion) {
    QTextCursor cursor(e->document()->findBlockByLineNumber(posicion));
    e->setTextCursor(cursor);
    update_status();
}

void Editor::update_status() {
    char cadena[200];
    QTextCursor cursor = e->textCursor();
    int l = cursor.blockNumber();
    int c = cursor.columnNumber();
    QByteArray nf = Nombre_fichero.toLocal8Bit();
    sprintf(cadena, " Fila:%3d  Columna:%3d | %s", l, c, nf.constData());
    s->showMessage(cadena);
}
