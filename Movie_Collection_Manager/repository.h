#pragma once
#include "movie.h"
#include <vector>
#include <string>

// This is an abstract base class (Interface)
class Repository {
public:
    virtual ~Repository() = default;

    // Core functionality required by the assignment
    virtual void addMovie(const Movie& movie) = 0;
    virtual void removeMovie(const std::string& title) = 0;
    virtual void updateMovie(const std::string& title, const Movie& newMovie) = 0;

    // To retrieve data for the UI later
    virtual std::vector<Movie> getAllMovies() const = 0;
};