#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
  private:
  std::string *name;
  std::string *rating;
  int *watched;

  public:
  Movie(std::string name_val, std::string rating_val, int watched);
  Movie(const Movie &source);
  Movie(Movie &&source);
  ~Movie();
  std::string get_name() const;
  std::string get_rating() const;
  int get_watched() const;
  void set_name(std::string name_val);
  void increase_watched();
};

#endif
