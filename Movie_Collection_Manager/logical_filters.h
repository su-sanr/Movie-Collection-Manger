#pragma once
#include "filter.h"

// Combines two filters with AND
class AndFilter : public Filter {
private:
    const Filter& first;
    const Filter& second;
public:
    AndFilter(const Filter& f1, const Filter& f2) : first(f1), second(f2) {}

    bool isSatisfiedBy(const Movie& movie) const override {
        return first.isSatisfiedBy(movie) && second.isSatisfiedBy(movie);
    }
};

// Combines two filters with OR
class OrFilter : public Filter {
private:
    const Filter& first;
    const Filter& second;
public:
    OrFilter(const Filter& f1, const Filter& f2) : first(f1), second(f2) {}

    bool isSatisfiedBy(const Movie& movie) const override {
        return first.isSatisfiedBy(movie) || second.isSatisfiedBy(movie);
    }
};