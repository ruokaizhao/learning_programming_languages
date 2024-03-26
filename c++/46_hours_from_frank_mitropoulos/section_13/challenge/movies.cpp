#include "movies.h"
#include <iostream>

void Movies::display_movies()
{
  if (movies.size() == 0)
  {
    std::cout << "There is no movies in the collection." << std::endl;
  }
  else
  {
    for (Movie m : movies)
    {
      std::cout << m.get_name() << "\t" << m.get_rating() << "\t" << m.get_watched() << std::endl;
    }
  }
}

void Movies::add_movie(Movie movie)
{
  for (Movie m : movies)
  {
    if (m.get_name() == movie.get_name())
    {
      std::cout << movie.get_name() << " already added." << std::endl;
      return;
    }
  }

  std::cout << movie.get_name() << " added to the collection." << std::endl;
  movies.push_back(std::move(movie));
}

void Movies::increase_watched(Movie movie)
{
  for (Movie &m : movies)
  {
    if (m.get_name() == movie.get_name())
    {
      m.increase_watched();
      std::cout << m.get_name() << "'s watched has been increased by 1" << std::endl;
      return;
    }
  }
  std::cout << movie.get_name() << " not found" << std::endl;
  return;
}
