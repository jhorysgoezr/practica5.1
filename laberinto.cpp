#include "laberinto.h"

laberinto::laberinto() {}

void laberinto::cargarLaberintoDesdeTxt(const QString& nombreArchivo) {
    QFile archivo(nombreArchivo);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return;
    }

    QTextStream in(&archivo);
    mapaLaberinto.clear();

    while (!in.atEnd()) {
        QString linea = in.readLine();
        mapaLaberinto.push_back(linea);
    }

    archivo.close();
}

void laberinto::crearLaberintoDesdeMatriz(QGraphicsScene *scene) {
    muros.clear();

    for (int y = 0; y < mapaLaberinto.size(); ++y) {
        QString linea = mapaLaberinto[y];
        for (int x = 0; x < linea.length(); ++x) {
            interpretarSimbolo(linea[x].toLatin1(), x * TAMANO_BLOQUE, y * TAMANO_BLOQUE, scene);
        }
    }
}

QVector<Pildora*> laberinto::getPildoras() const {
    return pildoras;
}


void laberinto::interpretarSimbolo(char simbolo, int x, int y, QGraphicsScene *scene) {
    muro* nuevaMuro = nullptr;
    Pildora* nuevaPildora = nullptr;

    switch (simbolo) {
    case 'v': // Muro vertical
    case 'h': // Muro horizontal
    case 'a': // Esquina superior izquierda
    case 'b': // Esquina superior derecha
    case 'c': // Esquina inferior izquierda
    case 'd': // Esquina inferior derecha
        nuevaMuro = new muro(x, y, TAMANO_BLOQUE, TAMANO_BLOQUE);
        break;

    case '@': // Píldora mágica
        nuevaPildora = new Pildora(x, y, TAMANO_BLOQUE, true);
        break;

    case '-': // Píldora normal
        nuevaPildora = new Pildora(x, y, TAMANO_BLOQUE, false);
        break;
    }

    if (nuevaMuro) {
        muros.push_back(nuevaMuro);
        scene->addItem(nuevaMuro);
    }

    if (nuevaPildora) {
        pildoras.push_back(nuevaPildora);
        scene->addItem(nuevaPildora);
    }
}

QVector<muro*> laberinto::getMuros() const {
    return muros;
}


