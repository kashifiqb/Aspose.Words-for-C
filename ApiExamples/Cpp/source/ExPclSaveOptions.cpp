﻿// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////
#include "ExPclSaveOptions.h"

namespace ApiExamples { namespace gtest_test {

class ExPclSaveOptions : public ::testing::Test
{
protected:
    static System::SharedPtr<::ApiExamples::ExPclSaveOptions> s_instance;

    void SetUp() override
    {
        s_instance->SetUp();
    };

    static void SetUpTestCase()
    {
        s_instance = System::MakeObject<::ApiExamples::ExPclSaveOptions>();
        s_instance->OneTimeSetUp();
    };

    static void TearDownTestCase()
    {
        s_instance->OneTimeTearDown();
        s_instance = nullptr;
    };
};

System::SharedPtr<::ApiExamples::ExPclSaveOptions> ExPclSaveOptions::s_instance;

TEST_F(ExPclSaveOptions, RasterizeElements)
{
    s_instance->RasterizeElements();
}

TEST_F(ExPclSaveOptions, SetPrinterFont)
{
    s_instance->SetPrinterFont();
}

TEST_F(ExPclSaveOptions, DISABLED_GetPreservedPaperTrayInformation)
{
    s_instance->GetPreservedPaperTrayInformation();
}

}} // namespace ApiExamples::gtest_test
