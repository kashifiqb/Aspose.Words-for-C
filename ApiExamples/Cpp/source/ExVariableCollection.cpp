﻿// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////
#include "ExVariableCollection.h"

namespace ApiExamples { namespace gtest_test {

class ExVariableCollection : public ::testing::Test
{
protected:
    static System::SharedPtr<::ApiExamples::ExVariableCollection> s_instance;

    void SetUp() override
    {
        s_instance->SetUp();
    };

    static void SetUpTestCase()
    {
        s_instance = System::MakeObject<::ApiExamples::ExVariableCollection>();
        s_instance->OneTimeSetUp();
    };

    static void TearDownTestCase()
    {
        s_instance->OneTimeTearDown();
        s_instance = nullptr;
    };
};

System::SharedPtr<::ApiExamples::ExVariableCollection> ExVariableCollection::s_instance;

TEST_F(ExVariableCollection, Primer)
{
    s_instance->Primer();
}

}} // namespace ApiExamples::gtest_test
