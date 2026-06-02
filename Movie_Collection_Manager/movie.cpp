#include "movie.h"


Movie::Movie() : title(""), genre(""), year(0), trailerUrl("") {}


Movie::Movie(const std::string& title, const std::string& genre, int year, const std::string& trailerUrl)
    : title(title), genre(genre), year(year), trailerUrl(trailerUrl) {}


std::string Movie::getTitle() const { return title; }
std::string Movie::getGenre() const { return genre; }
int Movie::getYear() const { return year; }
std::string Movie::getTrailerUrl() const { return trailerUrl; }


void Movie::setTitle(const std::string& title) { this->title = title; }
void Movie::setGenre(const std::string& genre) { this->genre = genre; }
void Movie::setYear(int year) { this->year = year; }
void Movie::setTrailerUrl(const std::string& url) { this->trailerUrl = url; }


bool Movie::operator==(const Movie& other) const {
    return this->title == other.title && this->year == other.year;
}