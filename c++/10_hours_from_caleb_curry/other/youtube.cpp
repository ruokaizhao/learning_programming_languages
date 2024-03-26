#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void play_game();
void save_score(std::vector<int>, bool &, bool &);
// void save_score(std::vector<int>, bool *, bool *);
void print_guesses(std::vector<int>, bool, bool);

int main()
{
  srand(time(NULL));
  int choice;

  do
  {
    std::cout << "0. Quit\n"
              << "1. Play Game\n";
    std::cin >> choice;
    switch (choice)
    {
    case 0:
      std::cout << "Thanks for playing!\n";
      break;
    case 1:
      play_game();
      break;
    }
  } while (choice != 0);
}

void play_game()
{
  std::vector<int> guesses;
  int random = rand() % 251;

  while (true)
  {
    int guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    guesses.push_back(guess);

    if (guess == random)
    {
      std::cout << "You Won!\n";
      break;
    }
    else if (guess < random)
    {
      std::cout << "Too low\n";
    }
    else
    {
      std::cout << "Too high\n";
    }
  }
  bool is_first_score = false;
  bool is_better_score = false;

  save_score(guesses, is_first_score, is_better_score);
  // save_score(guesses, &is_first_score, &is_better_score);

  print_guesses(guesses, is_first_score, is_better_score);
}

void save_score(std::vector<int> guesses, bool &is_first_score, bool &is_better_score)
// void save_score(std::vector<int> guesses, bool *is_first_score, bool *is_better_score)
{
  int prev_score;
  std::ifstream read_score("score.txt");
  if (read_score.is_open())
  {
    read_score >> prev_score;
    if (guesses.size() < prev_score)
    {
      is_better_score = true;
      // *is_better_score = true;
      std::ofstream write_score("score.txt");
      write_score << guesses.size();
      write_score.close();
    }
  }
  else
  {
    is_first_score = true;
    // *is_first_score = true;
    std::ofstream first_score("score.txt");
    first_score << guesses.size();
    first_score.close();
  }
  read_score.close();
}

void print_guesses(std::vector<int> guesses, bool is_first_score, bool is_better_score)
{
  std::cout << "Congrats! It took you " << guesses.size() << (guesses.size() > 1 ? " tries" : " try") << " to win. "
            << (!is_first_score ? (is_better_score ? "You have set a new record!"
                                                   : "You didn't break the previous record, please try again.")
                                : "You are the first one played this game!")
            << " Here are all your guesses: \n";
  for (int guess : guesses)
  {
    std::cout << guess << "\t";
  }
  std::cout << "\n";
}
