#include "movie.h"
#include <iostream>

Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
{
  name = new std::string;
  *name = name_val;
  rating = new std::string;
  *rating = rating_val;
  watched = new int;
  *watched = watched_val;
  std::cout << "Movie " << *name << " created." << std::endl;
}

Movie::Movie(const Movie &source) : Movie::Movie(*source.name, *source.rating, *source.watched)
{
  std::cout << "Movie " << *name << " copied" << std::endl;
}

Movie::Movie(Movie &&source) : name{source.name}, rating{source.rating}, watched{source.watched}
{
  source.name = nullptr;
  source.rating = nullptr;
  source.watched = nullptr;
  std::cout << "Move" << std::endl;
}

Movie::~Movie()
{
  if (name == nullptr)
  {
    std::cout << "nullptr out of scope" << std::endl;
  }
  else
  {
    std::cout << *name << " out of scope." << std::endl;
  }
  delete name;
  delete rating;
  delete watched;
}

std::string Movie::get_name() const
{
  return *name;
}

std::string Movie::get_rating() const
{
  return *rating;
}

int Movie::get_watched() const
{
  return *watched;
}

void Movie::set_name(std::string name_val)
{
  *name = name_val;
}

void Movie::increase_watched()
{
  *watched = *watched + 1;
}
