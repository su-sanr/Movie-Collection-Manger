#pragma once
#include <QMainWindow>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Controller& controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots: // <--- These are your Slots
    void onAddMovieClicked();
    void onRemoveMovieClicked();
    void onUpdateMovieClicked();
    void onUndoClicked();
    void onRedoClicked();
    void onMovieSelectionChanged(); // When a user clicks a movie in the list

private:
    Ui::MainWindow *ui;
    Controller& controller;

    void populateList(); // Helper to refresh the UI
};