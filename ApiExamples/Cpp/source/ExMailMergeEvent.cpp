﻿// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////
// CPPDEFECT: System.Data is not supported
#include "ExMailMergeEvent.h"

#include <Aspose.Words.Cpp/Model/MailMerge/FieldMergingArgs.h>
#include <Aspose.Words.Cpp/Model/MailMerge/ImageFieldMergingArgs.h>

using namespace Aspose::Words;
using namespace Aspose::Words::MailMerging;
namespace ApiExamples { namespace gtest_test {

class ExMailMergeEvent : public ::testing::Test
{
protected:
    static System::SharedPtr<::ApiExamples::ExMailMergeEvent> s_instance;

    void SetUp() override
    {
        s_instance->SetUp();
    };

    static void SetUpTestCase()
    {
        s_instance = System::MakeObject<::ApiExamples::ExMailMergeEvent>();
        s_instance->OneTimeSetUp();
    };

    static void TearDownTestCase()
    {
        s_instance->OneTimeTearDown();
        s_instance = nullptr;
    };
};

System::SharedPtr<::ApiExamples::ExMailMergeEvent> ExMailMergeEvent::s_instance;

TEST_F(ExMailMergeEvent, InsertHtml)
{
    s_instance->InsertHtml();
}

TEST_F(ExMailMergeEvent, ImageFromUrl)
{
    s_instance->ImageFromUrl();
}

}} // namespace ApiExamples::gtest_test
