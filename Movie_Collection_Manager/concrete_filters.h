#pragma once
#include "filter.h"
#include <string>

class GenreFilter : public Filter {
private:
    std::string targetGenre;
public:
    explicit GenreFilter(const std::string& genre) : targetGenre(genre) {}

    bool isSatisfiedBy(const Movie& movie) const override {
        return movie.getGenre() == targetGenre;
    }
};

class YearFilter : public Filter {
private:
    int targetYear;
public:
    explicit YearFilter(int year) : targetYear(year) {}

    bool isSatisfiedBy(const Movie& movie) const override {
        return movie.getYear() == targetYear;
    }
};