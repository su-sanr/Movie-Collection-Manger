#pragma once
#include "repository.h"
#include <string>
#include <vector>

class JsonMovieRepository : public Repository {
private:
    std::vector<Movie> movies;
    std::string filename;

    // Helper functions for Qt JSON serialization
    void loadFromFile();
    void saveToFile() const;

public:
    explicit JsonMovieRepository(const std::string& filename);
    ~JsonMovieRepository() override = default;

    void addMovie(const Movie& movie) override;
    void removeMovie(const std::string& title) override;
    void updateMovie(const std::string& title, const Movie& newMovie) override;

    std::vector<Movie> getAllMovies() const override;
};