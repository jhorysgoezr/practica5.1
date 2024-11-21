#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 705, 495);

    // Crear laberinto desde archivo de texto
    miLaberinto = new laberinto();
    miLaberinto->cargarLaberintoDesdeTxt("C:\\Users\\lenovo\\Documents\\AppGUI\\build\\Desktop_Qt_6_5_3_MinGW_64_bit-Debug\\mapa.txt");
    miLaberinto->crearLaberintoDesdeMatriz(scene);

    miPersonaje = new personaje(0, 12, 19, 19);
    ui->graphicsView->setScene(scene);
    scene->addItem(miPersonaje);
}


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::verificarColisionesPersonaje(QPointF direccion)
{
    return miPersonaje->verificarColision(direccion);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event -> key()==Qt::Key_S )
        miPersonaje ->MoverArriba();
    else if (event -> key()==Qt::Key_Z )
        miPersonaje ->MoverAbajo();
    else if (event -> key()==Qt::Key_D )
        miPersonaje ->MoverDer();
    else if (event -> key()==Qt::Key_A )
        miPersonaje ->MoverIzq();
}



