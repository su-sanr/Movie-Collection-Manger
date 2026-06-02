#include "csv_repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

CsvMovieRepository::CsvMovieRepository(const std::string& filename) : filename(filename) {
    loadFromFile();
}

void CsvMovieRepository::addMovie(const Movie& movie) {
    movies.push_back(movie);
    saveToFile();
}

void CsvMovieRepository::removeMovie(const std::string& title) {
    auto it = std::remove_if(movies.begin(), movies.end(),
                             [&title](const Movie& m) { return m.getTitle() == title; });

    if (it != movies.end()) {
        movies.erase(it, movies.end());
        saveToFile();
    }
}

void CsvMovieRepository::updateMovie(const std::string& title, const Movie& newMovie) {
    auto it = std::find_if(movies.begin(), movies.end(),
                           [&title](const Movie& m) { return m.getTitle() == title; });

    if (it != movies.end()) {
        *it = newMovie;
        saveToFile();
    }
}

std::vector<Movie> CsvMovieRepository::getAllMovies() const {
    return movies;
}

void CsvMovieRepository::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, genre, yearStr, trailerUrl;

        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, trailerUrl, ',');

        if (!title.empty() && !yearStr.empty()) {
            movies.emplace_back(title, genre, std::stoi(yearStr), trailerUrl);
        }
    }
    file.close();
}

void CsvMovieRepository::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& movie : movies) {
        file << movie.getTitle() << ","
             << movie.getGenre() << ","
             << movie.getYear() << ","
             << movie.getTrailerUrl() << "\n";
    }
    file.close();
}