#include "Model.h"

const CityVector initData()
{
  std::vector<Person *> londonCitizens{new Person("John", 34, 10000),
                                       new Person("Peter", 54, 20000),
                                       new Person("Mary", 17, 3000)};

  std::vector<Person *> beijingCitizens{new Person("Wong Yin", 32, 10000),
                                        new Person("Xiu Ming", 52, 20000),
                                        new Person("Tai Man", 15, 3000)};

  std::vector<Person *> seoulCitizens{new Person("Mr. Pak", 32, 10000),
                                      new Person("Gilbin", 52, 20000),
                                      new Person("YoungSoo", 15, 3000)};

  return CityVector {new City("London", londonCitizens),
                    new City("Beijing", beijingCitizens),
                    new City("Seoul", seoulCitizens)};
}

Person::Person(std::string name, int age, int income) : name(name), age(age), income(income)
{
}
std::string Person::getName() const
{
  return name;
}

int Person::getAge() const
{
  return age;
}

int Person::getIncome() const
{
  return income;
}

City::City(const std::string name, const std::vector<Person *> &citizens) : name(name), citizens(citizens)
{
}

City::~City()
{
  citizens.clear();
}

std::string City::getName() const { return name; }

const std::vector<Person *> &City::getCitizens() const
{
  return citizens;
}