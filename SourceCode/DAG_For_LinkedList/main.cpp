#include "mainwindow.h"
#include <QApplication>

#include "graph.h"

LISTGRAPH_T LG_u = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LG_u = ListGraph_Init(LG_u);

    w.show();

    return a.exec();
}
