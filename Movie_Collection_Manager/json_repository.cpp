#include "json_repository.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <algorithm>

JsonMovieRepository::JsonMovieRepository(const std::string& filename) : filename(filename) {
    loadFromFile();
}

void JsonMovieRepository::addMovie(const Movie& movie) {
    movies.push_back(movie);
    saveToFile();
}

void JsonMovieRepository::removeMovie(const std::string& title) {
    auto it = std::remove_if(movies.begin(), movies.end(),
                             [&title](const Movie& m) { return m.getTitle() == title; });

    if (it != movies.end()) {
        movies.erase(it, movies.end());
        saveToFile();
    }
}

void JsonMovieRepository::updateMovie(const std::string& title, const Movie& newMovie) {
    auto it = std::find_if(movies.begin(), movies.end(),
                           [&title](const Movie& m) { return m.getTitle() == title; });

    if (it != movies.end()) {
        *it = newMovie;
        saveToFile();
    }
}

std::vector<Movie> JsonMovieRepository::getAllMovies() const {
    return movies;
}

void JsonMovieRepository::loadFromFile() {
    QFile file(QString::fromStdString(filename));

    // If the file doesn't exist or can't be opened, just return (it will be created on first save)
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonArray jsonArray = doc.array();

    movies.clear();
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject obj = jsonArray[i].toObject();

        // Extract data and convert QString back to std::string
        std::string title = obj["title"].toString().toStdString();
        std::string genre = obj["genre"].toString().toStdString();
        int year = obj["year"].toInt();
        std::string trailerUrl = obj["trailerUrl"].toString().toStdString();

        movies.emplace_back(title, genre, year, trailerUrl);
    }
}

void JsonMovieRepository::saveToFile() const {
    QJsonArray jsonArray;

    for (const auto& movie : movies) {
        QJsonObject obj;
        // Convert std::string to QString for Qt JSON
        obj["title"] = QString::fromStdString(movie.getTitle());
        obj["genre"] = QString::fromStdString(movie.getGenre());
        obj["year"] = movie.getYear();
        obj["trailerUrl"] = QString::fromStdString(movie.getTrailerUrl());

        jsonArray.append(obj);
    }

    QJsonDocument doc(jsonArray);

    QFile file(QString::fromStdString(filename));
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}