#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "movie.h"
#include <vector>

class Movies
{
  private:
  std::vector<Movie> movies;

  public:
  void display_movies();
  void add_movie(Movie movie);
  void increase_watched(Movie movie);
};

#endif
