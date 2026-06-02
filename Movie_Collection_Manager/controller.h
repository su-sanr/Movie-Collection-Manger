#pragma once
#include "repository.h"
#include "command.h"
#include <memory>
#include <vector>

class Controller {
private:
    Repository& repo;

    std::vector<std::unique_ptr<Command>> undoStack;
    std::vector<std::unique_ptr<Command>> redoStack;

public:
    explicit Controller(Repository& repo);

    void addMovie(const Movie& movie);
    void removeMovie(const std::string& title);
    void updateMovie(const std::string& title, const Movie& newMovie);

    void undo();
    void redo();

    std::vector<Movie> getAllMovies() const;
};