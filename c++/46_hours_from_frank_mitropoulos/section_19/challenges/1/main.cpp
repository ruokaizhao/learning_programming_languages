// Section 19
// Challenge 1
// Formatting output
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct City
{
  std::string name;
  long population;
  double cost;
};

// Assume each country has at least 1 city
struct Country
{
  std::string name;
  std::vector<City> cities;
};

struct Tours
{
  std::string title;
  std::vector<Country> countries;
};

const int field_total{70};
const int field_1{20};
const int field_2{20};
const int field_3{15};
const int field_4{15};

void ruler()
{
  std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl << std::endl;
}

int main()
{
  Tours tours{
      "Tour Ticket Prices from Miami",
      {
          {
              "Colombia",
              {{"Bogota", 8778000, 400.98},
               {"Cali", 2401000, 424.12},
               {"Medellin", 2464000, 350.98},
               {"Cartagena", 972000, 345.34}},
          },
          {
              "Brazil",
              {{"Rio De Janiero", 13500000, 567.45}, {"Sao Paulo", 11310000, 975.45}, {"Salvador", 18234000, 855.99}},
          },
          {
              "Chile",
              {{"Valdivia", 260000, 569.12}, {"Santiago", 7040000, 520.00}},
          },
          {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
      }};

  // Unformatted display so you can see how to access the vector elements
  ruler();
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << std::setw((field_total - tours.title.size()) / 2) << std::left << "" << tours.title << std::endl
            << std::endl;
  std::cout << std::setw(field_1) << std::left << "Country" << std::setw(field_2) << std::left << "City"
            << std::setw(field_3) << std::right << "Population" << std::setw(field_4) << std::right << "Price"
            << std::endl;
  std::cout << std::setw(field_total) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');

  for (auto country : tours.countries)
  {
    int counter = 0;
    for (auto city : country.cities)
    {
      std::cout << std::setw(field_1) << std::left << (counter == 0 ? country.name : "") << std::setw(field_2)
                << std::left << city.name << std::setw(field_3) << std::right << city.population << std::setw(field_4)
                << std::right << city.cost << std::endl;

      ++counter;
    }
  }

  std::cout << std::endl << std::endl;
  return 0;
}
