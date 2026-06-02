#pragma once
#include "repository.h"
#include <string>
#include <vector>

class CsvMovieRepository : public Repository {
private:
    std::vector<Movie> movies;
    std::string filename;

    void loadFromFile();
    void saveToFile() const;

public:
    explicit CsvMovieRepository(const std::string& filename);
    ~CsvMovieRepository() override = default;

    void addMovie(const Movie& movie) override;
    void removeMovie(const std::string& title) override;
    void updateMovie(const std::string& title, const Movie& newMovie) override;

    std::vector<Movie> getAllMovies() const override;
};