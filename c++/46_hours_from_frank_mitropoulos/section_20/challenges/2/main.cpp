// Section 20
// Challenge 2
//  Lists

#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>

class Song
{
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  friend std::ofstream &operator<<(std::ofstream &ofs, const Song &s);
  std::string name;
  std::string artist;
  int rating;

  public:
  Song() = default;
  Song(std::string name, std::string artist, int rating) : name{name}, artist{artist}, rating{rating}
  {
  }
  std::string get_name() const
  {
    return name;
  }
  std::string get_artist() const
  {
    return artist;
  }
  int get_rating() const
  {
    return rating;
  }

  bool operator<(const Song &rhs) const
  {
    return this->name < rhs.name;
  }

  bool operator==(const Song &rhs) const
  {
    return this->name == rhs.name;
  }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
  os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left
     << s.rating;
  return os;
}

std::ofstream &operator<<(std::ofstream &ofs, const Song &s)
{
  ofs << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left
      << s.rating;
  return ofs;
}

std::array<char, 9> options{'F', 'E', 'N', 'P', 'A', 'L', 'S', 'R', 'Q'};
void display_menu()
{
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "E - Play Last Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "D - Delete the current song and play the next song" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "S - Save playlist to a file" << std::endl;
  std::cout << "R - Read playlist from a file" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
  std::cout << "Playing:" << std::endl;
  std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
  for (const auto &song : playlist)
  {
    std::cout << song << std::endl;
  }
  std::cout << "Current song:" << std::endl;
  std::cout << current_song << std::endl;
}

void add_a_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
  std::string name{};
  std::string artist{};
  int rating{};

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Please enter the name of the song: ";
  std::getline(std::cin, name);
  std::cout << "Please enter the artist of the song: ";
  std::getline(std::cin, artist);
  std::cout << "Please enter the rating of the song: ";
  std::cin >> rating;

  if (current_song != playlist.end())
  {
    playlist.emplace(current_song, name, artist, rating);
  }
  current_song--;
}

bool save_to_file(const std::list<Song> &playlist, const std::string file_name)
{
  std::ofstream file{};
  file.open(file_name);
  if (!file)
  {
    std::cerr << "Failed creating file." << std::endl;
    return false;
  }
  for (const auto &song : playlist)
  {
    file << song << std::endl;
  }
  file.close();
  return true;
}

bool read_from_file(std::list<Song> &playlist, const std::string file_name)
{
  std::ifstream file{};
  file.open(file_name);
  if (!file)
  {
    std::cerr << "Failed opening file" << std::endl;
    return false;
  }
  std::string name;
  std::string artist;
  int rating;

  while (file >> name >> artist >> rating)
  {
    playlist.emplace_back(name, artist, rating);
  }
  file.close();
  return true;
}

int main()
{
  std::list<Song> playlist{{"Song1", "Artist1", 5}, {"Song2", "Artist2", 5}, {"Song3", "Artist3", 4},
                           {"Song4", "Artist4", 5}, {"Song5", "Artist5", 4}, {"Song6", "Artist6", 3}};

  std::list<Song>::iterator current_song = playlist.begin();

  std::array<char, 10> options{'F', 'E', 'N', 'P', 'A', 'D', 'L', 'S', 'R', 'Q'};
  char user_input{};
  do
  {
    display_menu();
    std::cin >> user_input;
    if (std::find(options.begin(), options.end(), std::toupper(user_input)) == options.end())
    {
      std::cout << std::endl << "Selection is not an option in the menu, please select again: " << std::endl;
      continue;
    }

    switch (std::toupper(user_input))
    {
    case 'F': {
      std::cout << "Playing first song" << std::endl;
      current_song = playlist.begin();
      play_current_song(*current_song);
      break;
    }
    case 'E': {
      std::cout << "Playing last song" << std::endl;
      current_song = playlist.end();
      std::advance(current_song, -1);
      play_current_song(*current_song);
      break;
    }
    case 'N': {
      std::cout << "Playing next song" << std::endl;
      current_song++;
      if (current_song == playlist.end())
      {
        current_song = playlist.begin();
      }
      play_current_song(*current_song);
      break;
    }
    case 'P': {
      std::cout << "Playing previous song" << std::endl;
      if (current_song == playlist.begin())
      {
        current_song = playlist.end();
        std::advance(current_song, -1);
      }
      else
      {
        current_song--;
      }
      play_current_song(*current_song);
      break;
    }
    case 'A': {
      std::cout << "Adding and playing new song" << std::endl;
      add_a_song(playlist, current_song);
      play_current_song(*current_song);
      break;
    }
    case 'D': {
      std::cout << "Are you sure you want to delete the current song, Y/N? ";
      char user_input{};
      std::cin >> user_input;

      if (std::toupper(user_input) == 'Y')
      {
        std::cout << "Removing current song" << std::endl;
        std::list<Song>::iterator song_to_be_removed = current_song;
        current_song++;
        if (current_song == playlist.end())
        {
          current_song = playlist.begin();
        }
        playlist.erase(song_to_be_removed);
        play_current_song(*current_song);
      }
      break;
    }
    case 'L': {
      display_playlist(playlist, *current_song);
      break;
    }
    case 'S': {
      std::string file_name{};
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please enter the file name: ";
      std::getline(std::cin, file_name);
      std::cout << "Saving playlist to file" << std::endl;
      if (save_to_file(playlist, file_name))
      {
        std::cout << "Playlist saved successfully" << std::endl;
      }
      break;
    }
    case 'R': {
      std::cout << "Reading from a file will erase the current playlist, do you want to continue, Y/N? ";
      char user_input{};
      std::cin >> user_input;

      if (std::toupper(user_input) == 'Y')
      {
        std::string file_name{};
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter the file name: ";
        std::getline(std::cin, file_name);
        std::cout << "Reading playlist from file" << std::endl;

        playlist.clear();
        if (read_from_file(playlist, file_name))
        {
          std::cout << "Reading complete, here's the playlist" << std::endl;
          current_song = playlist.begin();
          display_playlist(playlist, *current_song);
        }
      }
      break;
    }
    }
  } while (std::toupper(user_input) != 'Q');

  std::cout << "Thanks for listening!" << std::endl;

  return 0;
}
