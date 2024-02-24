#include <iostream>
#include "Model.h"

PersonVector getPeopleOldThan18(const CityVector &cityVector);

int main()
{
  const CityVector cities = initData();
  std::cout << "----------------------------" << std::endl;
  std::cout << "People larger than 18:" << std::endl;
  PersonVector personVector = getPeopleOldThan18(cities);
  for (auto person : personVector)
  {
    std::cout << person->getName() << ", Age: " << person->getAge() << std::endl;
  }
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