#pragma once
#include "command.h"
#include "repository.h"
#include "movie.h"

// --- ADD COMMAND ---
class AddCommand : public Command {
private:
    Repository& repo;
    Movie movie;
public:
    AddCommand(Repository& r, const Movie& m) : repo(r), movie(m) {}
    void execute() override { repo.addMovie(movie); }
    void undo() override { repo.removeMovie(movie.getTitle()); }
};

// --- REMOVE COMMAND ---
class RemoveCommand : public Command {
private:
    Repository& repo;
    Movie movie; // We need to store the whole movie so we can put it back!
public:
    RemoveCommand(Repository& r, const Movie& m) : repo(r), movie(m) {}
    void execute() override { repo.removeMovie(movie.getTitle()); }
    void undo() override { repo.addMovie(movie); }
};

// --- UPDATE COMMAND ---
class UpdateCommand : public Command {
private:
    Repository& repo;
    std::string oldTitle;
    Movie oldMovie;
    Movie newMovie;
public:
    UpdateCommand(Repository& r, const std::string& oldT, const Movie& oldM, const Movie& newM)
        : repo(r), oldTitle(oldT), oldMovie(oldM), newMovie(newM) {}

    void execute() override { repo.updateMovie(oldTitle, newMovie); }
    // To undo an update, we just update it back using the old data
    void undo() override { repo.updateMovie(newMovie.getTitle(), oldMovie); }
};