#include "mainwindow.h"
#include <QApplication>
#include "json_repository.h"
#include "controller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 1. Boot up the backend
    JsonMovieRepository repo("movies.json");
    Controller controller(repo);

    // 2. Pass the backend to the visual window
    MainWindow w(controller);
    w.show();

    return a.exec();
}