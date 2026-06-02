#pragma once
#include "movie.h"

class Filter {
public:
    virtual ~Filter() = default;

    virtual bool isSatisfiedBy(const Movie& movie) const = 0;
};