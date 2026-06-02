#pragma once
#include <string>

class Movie {
private:
    std::string title;
    std::string genre;
    int year;
    std::string trailerUrl;

public:
    // Constructors
    Movie();
    Movie(const std::string& title, const std::string& genre, int year, const std::string& trailerUrl);

    // Getters
    std::string getTitle() const;
    std::string getGenre() const;
    int getYear() const;
    std::string getTrailerUrl() const;

    // Setters
    void setTitle(const std::string& title);
    void setGenre(const std::string& genre);
    void setYear(int year);
    void setTrailerUrl(const std::string& url);

    // Equality operator (useful for finding/removing movies later)
    bool operator==(const Movie& other) const;
};