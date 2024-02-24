#include <iostream>
#include "Model.h"

PersonVector getPeopleOldThan18(const CityVector &cityVector);
PersonVector getPeopleIncomeMoreThan15000(const CityVector &cityVector);

int main()
{
  const CityVector cities = initData();

  PersonVector personVector  = getPeopleOldThan18(cities);
  for(auto person: personVector)
  {
    std::cout << person->getName() << ", Age: " << person->getAge() << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  personVector = getPeopleIncomeMoreThan15000(cities);
  for(auto person: personVector)
  {
    std::cout << person->getName() << ", Income: " << person->getIncome() << std::endl;
  }
}

PersonVector getPeopleIncomeMoreThan15000(const CityVector &cityVector)
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