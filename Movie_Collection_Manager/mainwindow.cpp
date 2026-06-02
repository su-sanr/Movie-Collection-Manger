#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(Controller& controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(controller) {

    ui->setupUi(this);

    // 1. Connect the UI Signals to your C++ Slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddMovieClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onRemoveMovieClicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateMovieClicked);
    connect(ui->undoButton, &QPushButton::clicked, this, &MainWindow::onUndoClicked);
    connect(ui->redoButton, &QPushButton::clicked, this, &MainWindow::onRedoClicked);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::onFilterClicked);
    connect(ui->clearFilterButton, &QPushButton::clicked, this, &MainWindow::onClearFilterClicked);

    // Change the initial load to use our new helper
    refreshFullList();

    // Connect clicking a list item to filling out the form
    connect(ui->movieListWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::onMovieSelectionChanged);

    // 2. Load the initial data onto the screen
    refreshFullList();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateList(const std::vector<Movie>& movies) {
    ui->movieListWidget->clear();
    for (const auto& movie : movies) {
        QString displayText = QString::fromStdString(movie.getTitle() + " (" + std::to_string(movie.getYear()) + ") - " + movie.getGenre());
        ui->movieListWidget->addItem(displayText);
    }
}

void MainWindow::refreshFullList() {
    populateList(controller.getAllMovies());
}

void MainWindow::onAddMovieClicked() {
    // Grab text from the UI forms
    std::string title = ui->titleInput->text().toStdString();
    std::string genre = ui->genreInput->text().toStdString();
    int year = ui->yearInput->text().toInt();
    std::string trailer = ui->trailerInput->text().toStdString();

    // Basic validation
    if (title.empty() || year == 0) {
        QMessageBox::warning(this, "Error", "Title and Year cannot be empty!");
        return;
    }

    controller.addMovie(Movie(title, genre, year, trailer));
    refreshFullList();

    // Clear inputs after adding
    ui->titleInput->clear();
    ui->genreInput->clear();
    ui->yearInput->clear();
    ui->trailerInput->clear();
}

void MainWindow::onRemoveMovieClicked() {
    std::string title = ui->titleInput->text().toStdString();
    if (title.empty()) return;

    controller.removeMovie(title);
    refreshFullList();
    ui->titleInput->clear();
}

void MainWindow::onUpdateMovieClicked() {
    std::string title = ui->titleInput->text().toStdString();
    std::string genre = ui->genreInput->text().toStdString();
    int year = ui->yearInput->text().toInt();
    std::string trailer = ui->trailerInput->text().toStdString();

    if (title.empty()) return;

    controller.updateMovie(title, Movie(title, genre, year, trailer));
    refreshFullList();
}

void MainWindow::onUndoClicked() {
    controller.undo();
    refreshFullList();
}

void MainWindow::onRedoClicked() {
    controller.redo();
    refreshFullList();
}

void MainWindow::onMovieSelectionChanged() {
    // When the user clicks a movie in the list, auto-fill the form so they can update/delete it easily
    int selectedIndex = ui->movieListWidget->currentRow();
    if (selectedIndex < 0) return;

    auto movies = controller.getAllMovies();
    if (selectedIndex < movies.size()) {
        const Movie& selectedMovie = movies[selectedIndex];
        ui->titleInput->setText(QString::fromStdString(selectedMovie.getTitle()));
        ui->genreInput->setText(QString::fromStdString(selectedMovie.getGenre()));
        ui->yearInput->setText(QString::number(selectedMovie.getYear()));
        ui->trailerInput->setText(QString::fromStdString(selectedMovie.getTrailerUrl()));
    }
}

void MainWindow::onFilterClicked() {
    std::string genre = ui->filterGenreInput->text().toStdString();
    QString yearText = ui->filterYearInput->text();

    if (genre.empty() && yearText.isEmpty()) return;

    // If both fields have text, combine them with the AND logic!
    if (!genre.empty() && !yearText.isEmpty()) {
        GenreFilter gf(genre);
        YearFilter yf(yearText.toInt());
        AndFilter combo(gf, yf);
        populateList(controller.filterMovies(combo));
    }
    // If only genre is filled
    else if (!genre.empty()) {
        GenreFilter gf(genre);
        populateList(controller.filterMovies(gf));
    }
    // If only year is filled
    else {
        YearFilter yf(yearText.toInt());
        populateList(controller.filterMovies(yf));
    }
}

void MainWindow::onClearFilterClicked() {
    ui->filterGenreInput->clear();
    ui->filterYearInput->clear();
    refreshFullList();
}