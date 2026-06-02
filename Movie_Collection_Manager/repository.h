#pragma once
#include "movie.h"
#include <vector>
#include <string>

class Repository {
public:
    virtual ~Repository() = default;

    virtual void addMovie(const Movie& movie) = 0;
    virtual void removeMovie(const std::string& title) = 0;
    virtual void updateMovie(const std::string& title, const Movie& newMovie) = 0;

    virtual std::vector<Movie> getAllMovies() const = 0;
};