﻿#include "TestData/TestClasses/ManagerTestClass.h"

namespace ApiExamples {

namespace TestData {

namespace TestClasses {

System::String ManagerTestClass::get_Name()
{
    return pr_Name;
}

void ManagerTestClass::set_Name(System::String value)
{
    pr_Name = value;
}

int32_t ManagerTestClass::get_Age()
{
    return pr_Age;
}

void ManagerTestClass::set_Age(int32_t value)
{
    pr_Age = value;
}

System::SharedPtr<System::Collections::Generic::IEnumerable<System::SharedPtr<ContractTestClass>>> ManagerTestClass::get_Contracts()
{
    return pr_Contracts;
}

void ManagerTestClass::set_Contracts(System::SharedPtr<System::Collections::Generic::IEnumerable<System::SharedPtr<ContractTestClass>>> value)
{
    pr_Contracts = value;
}

ManagerTestClass::ManagerTestClass() : pr_Age(0)
{
}

} // namespace TestClasses
} // namespace TestData
} // namespace ApiExamples
