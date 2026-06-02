#include "mainwindow.h"
#include <QApplication>
#include "json_repository.h"
#include "controller.h"
#include "tests.h" // <--- Include the test header

int main(int argc, char *argv[]) {
    runAllTests();

    QApplication a(argc, argv);
    JsonMovieRepository repo("movies.json");
    Controller controller(repo);
    MainWindow w(controller);
    w.show();
    return a.exec();
}