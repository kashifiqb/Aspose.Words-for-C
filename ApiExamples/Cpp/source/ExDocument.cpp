﻿// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////
// CPPDEFECT: Aspose.Pdf and HarfBuzz is not supported
#include "ExDocument.h"

#include <Aspose.Words.Cpp/Model/Comparer/Granularity.h>
#include <Aspose.Words.Cpp/Model/Markup/CustomPartCollection.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeChangingArgs.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeType.h>
#include <Aspose.Words.Cpp/Model/Revisions/Revision.h>
#include <system/shared_ptr.h>
#include <system/string.h>
#include <system/text/string_builder.h>

using namespace Aspose::Words;
using namespace Aspose::Words::Markup;
namespace ApiExamples { namespace gtest_test {

class ExDocument : public ::testing::Test
{
protected:
    static System::SharedPtr<::ApiExamples::ExDocument> s_instance;

    void SetUp() override
    {
        s_instance->SetUp();
    };

public:
    static void SetUpTestCase()
    {
        s_instance = System::MakeObject<::ApiExamples::ExDocument>();
        s_instance->OneTimeSetUp();
    };

    static void TearDownTestCase()
    {
        s_instance->OneTimeTearDown();
        s_instance = nullptr;
    };
};

System::SharedPtr<::ApiExamples::ExDocument> ExDocument::s_instance;

TEST_F(ExDocument, Constructor)
{
    s_instance->Constructor();
}

TEST_F(ExDocument, LoadFromStream)
{
    s_instance->LoadFromStream();
}

TEST_F(ExDocument, LoadFromWeb)
{
    s_instance->LoadFromWeb();
}

TEST_F(ExDocument, ConvertToPdf)
{
    s_instance->ConvertToPdf();
}

TEST_F(ExDocument, DetectPdfDocumentFormat)
{
    s_instance->DetectPdfDocumentFormat();
}

TEST_F(ExDocument, OpenFromStreamWithBaseUri)
{
    s_instance->OpenFromStreamWithBaseUri();
}

TEST_F(ExDocument, IgnoreOnJenkins_InsertHtmlFromWebPage)
{
    RecordProperty("category", "IgnoreOnJenkins");

    s_instance->InsertHtmlFromWebPage();
}

TEST_F(ExDocument, LoadEncrypted)
{
    s_instance->LoadEncrypted();
}

TEST_F(ExDocument, TempFolder)
{
    s_instance->TempFolder();
}

TEST_F(ExDocument, ConvertToHtml)
{
    s_instance->ConvertToHtml();
}

TEST_F(ExDocument, ConvertToMhtml)
{
    s_instance->ConvertToMhtml();
}

TEST_F(ExDocument, ConvertToTxt)
{
    s_instance->ConvertToTxt();
}

TEST_F(ExDocument, ConvertToEpub)
{
    s_instance->ConvertToEpub();
}

TEST_F(ExDocument, SaveToStream)
{
    s_instance->SaveToStream();
}

TEST_F(ExDocument, FontChangeViaCallback)
{
    s_instance->FontChangeViaCallback();
}

TEST_F(ExDocument, AppendDocument)
{
    s_instance->AppendDocument();
}

TEST_F(ExDocument, AppendDocumentFromAutomation)
{
    s_instance->AppendDocumentFromAutomation();
}

TEST_F(ExDocument, ValidateIndividualDocumentSignatures)
{
    s_instance->ValidateIndividualDocumentSignatures();
}

TEST_F(ExDocument, DigitalSignature)
{
    s_instance->DigitalSignature_();
}

TEST_F(ExDocument, AppendAllDocumentsInFolder)
{
    s_instance->AppendAllDocumentsInFolder();
}

TEST_F(ExDocument, JoinRunsWithSameFormatting)
{
    s_instance->JoinRunsWithSameFormatting();
}

TEST_F(ExDocument, DefaultTabStop)
{
    s_instance->DefaultTabStop();
}

TEST_F(ExDocument, CloneDocument)
{
    s_instance->CloneDocument();
}

TEST_F(ExDocument, DocumentGetTextToString)
{
    s_instance->DocumentGetTextToString();
}

TEST_F(ExDocument, DocumentByteArray)
{
    s_instance->DocumentByteArray();
}

TEST_F(ExDocument, ProtectUnprotect)
{
    s_instance->ProtectUnprotect();
}

TEST_F(ExDocument, DocumentEnsureMinimum)
{
    s_instance->DocumentEnsureMinimum();
}

TEST_F(ExDocument, RemoveMacrosFromDocument)
{
    s_instance->RemoveMacrosFromDocument();
}

TEST_F(ExDocument, GetPageCount)
{
    s_instance->GetPageCount();
}

TEST_F(ExDocument, GetUpdatedPageProperties)
{
    s_instance->GetUpdatedPageProperties();
}

TEST_F(ExDocument, TableStyleToDirectFormatting)
{
    s_instance->TableStyleToDirectFormatting();
}

TEST_F(ExDocument, GetOriginalFileInfo)
{
    s_instance->GetOriginalFileInfo();
}

TEST_F(ExDocument, FootnoteColumns)
{
    s_instance->FootnoteColumns();
}

TEST_F(ExDocument, Compare)
{
    s_instance->Compare();
}

TEST_F(ExDocument, CompareDocumentWithRevisions)
{
    s_instance->CompareDocumentWithRevisions();
}

TEST_F(ExDocument, CompareOptions)
{
    s_instance->CompareOptions_();
}

TEST_F(ExDocument, RemoveExternalSchemaReferences)
{
    s_instance->RemoveExternalSchemaReferences();
}

TEST_F(ExDocument, TrackRevisions)
{
    s_instance->TrackRevisions();
}

TEST_F(ExDocument, AcceptAllRevisions)
{
    s_instance->AcceptAllRevisions();
}

TEST_F(ExDocument, GetRevisedPropertiesOfList)
{
    s_instance->GetRevisedPropertiesOfList();
}

TEST_F(ExDocument, UpdateThumbnail)
{
    s_instance->UpdateThumbnail();
}

TEST_F(ExDocument, HyphenationOptions)
{
    s_instance->HyphenationOptions_();
}

TEST_F(ExDocument, HyphenationOptionsDefaultValues)
{
    s_instance->HyphenationOptionsDefaultValues();
}

TEST_F(ExDocument, HyphenationOptionsExceptions)
{
    s_instance->HyphenationOptionsExceptions();
}

TEST_F(ExDocument, OoxmlComplianceVersion)
{
    s_instance->OoxmlComplianceVersion();
}

TEST_F(ExDocument, DISABLED_ImageSaveOptions)
{
    s_instance->ImageSaveOptions_();
}

TEST_F(ExDocument, Cleanup)
{
    s_instance->Cleanup();
}

TEST_F(ExDocument, AutomaticallyUpdateStyles)
{
    s_instance->AutomaticallyUpdateStyles();
}

TEST_F(ExDocument, DefaultTemplate)
{
    s_instance->DefaultTemplate();
}

TEST_F(ExDocument, UseSubstitutions)
{
    s_instance->UseSubstitutions();
}

TEST_F(ExDocument, SetInvalidateFieldTypes)
{
    s_instance->SetInvalidateFieldTypes();
}

TEST_F(ExDocument, LayoutOptionsRevisions)
{
    s_instance->LayoutOptionsRevisions();
}

using LayoutOptionsHiddenText_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::LayoutOptionsHiddenText)>::type;

struct LayoutOptionsHiddenTextVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<LayoutOptionsHiddenText_Args>
{
    static std::vector<LayoutOptionsHiddenText_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(LayoutOptionsHiddenTextVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->LayoutOptionsHiddenText(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, LayoutOptionsHiddenTextVP, ::testing::ValuesIn(LayoutOptionsHiddenTextVP::TestCases()));

using LayoutOptionsParagraphMarks_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::LayoutOptionsParagraphMarks)>::type;

struct LayoutOptionsParagraphMarksVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<LayoutOptionsParagraphMarks_Args>
{
    static std::vector<LayoutOptionsParagraphMarks_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(LayoutOptionsParagraphMarksVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->LayoutOptionsParagraphMarks(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, LayoutOptionsParagraphMarksVP, ::testing::ValuesIn(LayoutOptionsParagraphMarksVP::TestCases()));

TEST_F(ExDocument, DocPackageCustomParts)
{
    s_instance->DocPackageCustomParts();
}

using ShadeFormData_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::ShadeFormData)>::type;

struct ShadeFormDataVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<ShadeFormData_Args>
{
    static std::vector<ShadeFormData_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(ShadeFormDataVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->ShadeFormData(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, ShadeFormDataVP, ::testing::ValuesIn(ShadeFormDataVP::TestCases()));

TEST_F(ExDocument, VersionsCount)
{
    s_instance->VersionsCount();
}

TEST_F(ExDocument, WriteProtection)
{
    s_instance->WriteProtection_();
}

using RemovePersonalInformation_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::RemovePersonalInformation)>::type;

struct RemovePersonalInformationVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<RemovePersonalInformation_Args>
{
    static std::vector<RemovePersonalInformation_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(RemovePersonalInformationVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->RemovePersonalInformation(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, RemovePersonalInformationVP, ::testing::ValuesIn(RemovePersonalInformationVP::TestCases()));

using ShowComments_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::ShowComments)>::type;

struct ShowCommentsVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<ShowComments_Args>
{
    static std::vector<ShowComments_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(ShowCommentsVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->ShowComments(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, ShowCommentsVP, ::testing::ValuesIn(ShowCommentsVP::TestCases()));

TEST_F(ExDocument, CopyTemplateStylesViaDocument)
{
    s_instance->CopyTemplateStylesViaDocument();
}

TEST_F(ExDocument, CopyTemplateStylesViaDocumentNew)
{
    s_instance->CopyTemplateStylesViaDocumentNew();
}

TEST_F(ExDocument, ReadMacrosFromExistingDocument)
{
    s_instance->ReadMacrosFromExistingDocument();
}

TEST_F(ExDocument, SaveOutputParameters)
{
    s_instance->SaveOutputParameters_();
}

TEST_F(ExDocument, SubDocument)
{
    s_instance->SubDocument_();
}

TEST_F(ExDocument, CreateWebExtension)
{
    s_instance->CreateWebExtension();
}

TEST_F(ExDocument, GetWebExtensionInfo)
{
    s_instance->GetWebExtensionInfo();
}

TEST_F(ExDocument, EpubCover)
{
    s_instance->EpubCover();
}

TEST_F(ExDocument, TextWatermark)
{
    s_instance->TextWatermark();
}

TEST_F(ExDocument, ImageWatermark)
{
    s_instance->ImageWatermark();
}

using SpellingAndGrammarErrors_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::SpellingAndGrammarErrors)>::type;

struct SpellingAndGrammarErrorsVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<SpellingAndGrammarErrors_Args>
{
    static std::vector<SpellingAndGrammarErrors_Args> TestCases()
    {
        return {
            std::make_tuple(false),
            std::make_tuple(true),
        };
    }
};

TEST_P(SpellingAndGrammarErrorsVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->SpellingAndGrammarErrors(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, SpellingAndGrammarErrorsVP, ::testing::ValuesIn(SpellingAndGrammarErrorsVP::TestCases()));

using GranularityCompareOption_Args = System::MethodArgumentTuple<decltype(&ApiExamples::ExDocument::GranularityCompareOption)>::type;

struct GranularityCompareOptionVP : public ExDocument, public ApiExamples::ExDocument, public ::testing::WithParamInterface<GranularityCompareOption_Args>
{
    static std::vector<GranularityCompareOption_Args> TestCases()
    {
        return {
            std::make_tuple(Granularity::CharLevel),
            std::make_tuple(Granularity::WordLevel),
        };
    }
};

TEST_P(GranularityCompareOptionVP, Test)
{
    using std::get;
    const auto& params = GetParam();
    ASSERT_NO_FATAL_FAILURE(s_instance->GranularityCompareOption(get<0>(params)));
}

INSTANTIATE_TEST_SUITE_P(ExDocument, GranularityCompareOptionVP, ::testing::ValuesIn(GranularityCompareOptionVP::TestCases()));

}} // namespace ApiExamples::gtest_test
