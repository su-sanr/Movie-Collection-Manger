#pragma once
#include <QMainWindow>
#include "controller.h"
#include "concrete_filters.h" // Add these!
#include "logical_filters.h"  // Add these!

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Controller& controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddMovieClicked();
    void onRemoveMovieClicked();
    void onUpdateMovieClicked();
    void onUndoClicked();
    void onRedoClicked();
    void onMovieSelectionChanged();

    // Add the new filter slots
    void onFilterClicked();
    void onClearFilterClicked();

private:
    Ui::MainWindow *ui;
    Controller& controller;

    // Modify this to accept a specific list of movies, defaulting to an empty list
    void populateList(const std::vector<Movie>& movies = {});
    void refreshFullList(); // Helper to just load everything
};