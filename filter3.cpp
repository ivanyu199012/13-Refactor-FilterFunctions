#include <iostream>
#include "Model.h"
#include <functional>

PersonVector getPeopleOldThan18(const CityVector &cityVector);
PersonVector getPeopleEarnMoreThan15000(const CityVector &cityVector);
PersonVector getPeopleWithFilter(const CityVector &cityVector, const std::function<bool(Person *)> &);

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

  personVector = getPeopleEarnMoreThan15000(cities);
  std::cout << "People has income greather than 15000:" << std::endl;
  for (auto person : personVector)
  {
    std::cout << person->getName() << ", Income: " << person->getIncome() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
}

PersonVector getPeopleEarnMoreThan15000(const CityVector &cityVector)
{
  std::function<bool(Person *)>
      personFilter = [](const Person *pPerson) -> bool
  {
    return pPerson->getIncome() > 15000;
  };
  // Call the above function
  return getPeopleWithFilter(cityVector, personFilter);
}

PersonVector getPeopleOldThan18(const CityVector &cityVector)
{
  std::function<bool(Person *)>
      personFilter = [](const Person *pPerson) -> bool
  {
    return pPerson->getAge() > 18;
  };
  // Call the above function
  return getPeopleWithFilter(cityVector, personFilter);
}

PersonVector getPeopleWithFilter(const CityVector &cityVector,
                                 // function parameter
                                 const std::function<bool(Person *)> &personFilter)
{
  PersonVector outputPersonVector;
  for (auto city : cityVector)
  {
    for (auto pPerson : city->getCitizens())
    {
      // Call the filter function
      if (personFilter(pPerson))
      {
        outputPersonVector.push_back(pPerson);
      }
    }
  }
  return outputPersonVector;
}