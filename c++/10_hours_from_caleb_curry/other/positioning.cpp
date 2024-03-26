#include <iostream>

class Position
{
  public:
  int x = 10;
  int y = 20;

  Position operator+(Position pos)
  {
    Position new_pos;
    new_pos.x = this->x + pos.x;
    new_pos.y = this->y + pos.y;
    return new_pos;
  }

  bool operator==(Position pos)
  {
    return (x == pos.x && this->y == pos.y);
  }
};

int main()
{
  Position pos1, pos2;
  Position pos3 = pos1 + pos2;
  std::cout << pos3.x << "\t" << pos3.y << "\n";

  pos2.x = 30;

  if (pos1 == pos2)
  {
    std::cout << "They are the same!\n";
  }
}
