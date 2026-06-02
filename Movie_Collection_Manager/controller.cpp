#include "controller.h"
#include "movie_commands.h"
#include <algorithm>

Controller::Controller(Repository& repo) : repo(repo) {}

void Controller::addMovie(const Movie& movie) {
    auto command = std::make_unique<AddCommand>(repo, movie);
    command->execute();
    undoStack.push_back(std::move(command));
    redoStack.clear();
}

void Controller::removeMovie(const std::string& title) {
    auto movies = repo.getAllMovies();
    auto it = std::find_if(movies.begin(), movies.end(),
                           [&title](const Movie& m){ return m.getTitle() == title; });

    if (it != movies.end()) {
        auto command = std::make_unique<RemoveCommand>(repo, *it);
        command->execute();
        undoStack.push_back(std::move(command));
        redoStack.clear();
    }
}

void Controller::updateMovie(const std::string& title, const Movie& newMovie) {
    auto movies = repo.getAllMovies();
    auto it = std::find_if(movies.begin(), movies.end(),
                           [&title](const Movie& m){ return m.getTitle() == title; });

    if (it != movies.end()) {
        auto command = std::make_unique<UpdateCommand>(repo, title, *it, newMovie);
        command->execute();
        undoStack.push_back(std::move(command));
        redoStack.clear();
    }
}

void Controller::undo() {
    if (!undoStack.empty()) {
        auto command = std::move(undoStack.back());
        undoStack.pop_back();
        command->undo();
        redoStack.push_back(std::move(command));
    }
}

void Controller::redo() {
    if (!redoStack.empty()) {
        auto command = std::move(redoStack.back());
        redoStack.pop_back();
        command->execute();
        undoStack.push_back(std::move(command));
    }
}

std::vector<Movie> Controller::getAllMovies() const {
    return repo.getAllMovies();
}