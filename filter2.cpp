#include <iostream>
#include "Model.h"

PersonVector getPeopleOldThan18(const CityVector &cityVector);
PersonVector getPeopleEarnMoreThan15000(const CityVector &cityVector);

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
  PersonVector outputPersonVector;
  for (auto city : cityVector)
  {
    for (auto pPerson : city->getCitizens())
    {
      if (pPerson->getIncome() > 15000)
      {
        outputPersonVector.push_back(pPerson);
      }
    }
  }
  return outputPersonVector;
}

PersonVector getPeopleOldThan18(const CityVector &cityVector)
{
  PersonVector outputPersonVector;
  for (auto city : cityVector)
  {
    for (auto pPerson : city->getCitizens())
    {
      if (pPerson->getAge() > 18)
      {
        outputPersonVector.push_back(pPerson);
      }
    }
  }
  return outputPersonVector;
}