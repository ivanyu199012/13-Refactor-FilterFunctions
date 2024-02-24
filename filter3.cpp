#include <iostream>
#include "Model.h"
#include <functional>

typedef std::function<bool(Person *)> PersonFilter;
PersonVector getPeopleOldThan18(const CityVector &cityVector);
PersonVector getPeopleIncomeMoreThan15000(const CityVector &cityVector);
PersonVector getPeopleWithFilter(const CityVector &cityVector, const PersonFilter &personFilter);

int main()
{
  const CityVector cities = initData();

  PersonVector personVector = getPeopleOldThan18(cities);
  std::cout << "----------------------------" << std::endl;
  std::cout << "People larger than 18:" << std::endl;
  for (auto person : personVector)
  {
    std::cout << person->getName() << ", Age: " << person->getAge() << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  personVector = getPeopleIncomeMoreThan15000(cities);
  std::cout << "People has income greather than 15000:" << std::endl;
  for (auto person : personVector)
  {
    std::cout << person->getName() << ", Income: " << person->getIncome() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
}

PersonVector getPeopleIncomeMoreThan15000(const CityVector &cityVector)
{
  PersonFilter personFilter = [](const Person *pPerson) -> bool
  {
    return pPerson->getIncome() > 15000;
  };
  return getPeopleWithFilter(cityVector, personFilter);
}

PersonVector getPeopleOldThan18(const CityVector &cityVector)
{
  PersonFilter personFilter = [](const Person *pPerson) -> bool
  {
    return pPerson->getAge() > 18;
  };
  return getPeopleWithFilter(cityVector, personFilter);
}

PersonVector getPeopleWithFilter(const CityVector &cityVector, const PersonFilter &personFilter)
{
  PersonVector outputPersonVector;
  for (auto city : cityVector)
  {
    for (auto pPerson : city->getCitizens())
    {
      if (personFilter(pPerson))
      {
        outputPersonVector.push_back(pPerson);
      }
    }
  }
  return outputPersonVector;
}