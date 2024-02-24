#include <string>
#include <vector>

class Person
{
  std::string name;
  int age;
  int income;

public:
  Person(std::string name, int age, int income);
  std::string getName() const;
  int getAge() const;
  int getIncome() const;
};

class City
{
  std::string name;
  std::vector<Person *> citizens;

public:
  City(const std::string name, const std::vector<Person *> &citizens);
  ~City();
  std::string getName() const;
  const std::vector<Person *> &getCitizens() const;
};

typedef std::vector<City *> CityVector;
typedef std::vector<Person *> PersonVector;

const CityVector initData();
