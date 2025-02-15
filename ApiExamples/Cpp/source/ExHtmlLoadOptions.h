﻿#pragma once
// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <Aspose.Words.Cpp/Model/Document/CertificateHolder.h>
#include <Aspose.Words.Cpp/Model/Document/DigitalSignatureUtil.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Document/HtmlControlType.h>
#include <Aspose.Words.Cpp/Model/Document/HtmlLoadOptions.h>
#include <Aspose.Words.Cpp/Model/Document/IWarningCallback.h>
#include <Aspose.Words.Cpp/Model/Document/LoadFormat.h>
#include <Aspose.Words.Cpp/Model/Document/SignOptions.h>
#include <Aspose.Words.Cpp/Model/Document/WarningInfo.h>
#include <Aspose.Words.Cpp/Model/Document/WarningSource.h>
#include <Aspose.Words.Cpp/Model/Document/WarningType.h>
#include <Aspose.Words.Cpp/Model/Drawing/ImageData.h>
#include <Aspose.Words.Cpp/Model/Drawing/ImageType.h>
#include <Aspose.Words.Cpp/Model/Drawing/Shape.h>
#include <Aspose.Words.Cpp/Model/Fields/FormFields/FormField.h>
#include <Aspose.Words.Cpp/Model/Markup/Sdt/SdtListItem.h>
#include <Aspose.Words.Cpp/Model/Markup/Sdt/SdtListItemCollection.h>
#include <Aspose.Words.Cpp/Model/Markup/Sdt/StructuredDocumentTag.h>
#include <Aspose.Words.Cpp/Model/Nodes/Node.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeCollection.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeType.h>
#include <Aspose.Words.Cpp/Model/Saving/SaveOutputParameters.h>
#include <system/array.h>
#include <system/collections/list.h>
#include <system/date_time.h>
#include <system/enum_helpers.h>
#include <system/exceptions.h>
#include <system/io/memory_stream.h>
#include <system/test_tools/compare.h>
#include <system/test_tools/method_argument_tuple.h>
#include <system/test_tools/test_tools.h>
#include <system/text/encoding.h>
#include <testing/test_predicates.h>

#include "ApiExampleBase.h"
#include "TestUtil.h"

using System::String;
using System::SharedPtr;
using System::ArrayPtr;
using System::MakeObject;
using System::MakeArray;

using namespace Aspose::Words;
using namespace Aspose::Words::Drawing;
using namespace Aspose::Words::Fields;
using namespace Aspose::Words::Markup;

namespace ApiExamples {

class ExHtmlLoadOptions : public ApiExampleBase
{
public:
    void SupportVml(bool doSupportVml)
    {
        //ExStart
        //ExFor:HtmlLoadOptions.#ctor()
        //ExFor:HtmlLoadOptions.SupportVml
        //ExSummary:Shows how to support VML while parsing a document.
        auto loadOptions = MakeObject<HtmlLoadOptions>();

        // If value is true, then we take VML code into account while parsing the loaded document
        loadOptions->set_SupportVml(doSupportVml);

        // This document contains an image within "<!--[if gte vml 1]>" tags, and another different image within "<![if !vml]>" tags
        // Upon loading the document, only the contents of the first tag will be shown if VML is enabled,
        // and only the contents of the second tag will be shown otherwise
        auto doc = MakeObject<Document>(MyDir + u"VML conditional.htm", loadOptions);

        // Only one of the two unique images will be loaded, depending on the value of loadOptions.SupportVml
        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        if (doSupportVml)
        {
            TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        }
        else
        {
            TestUtil::VerifyImageInShape(400, 400, ImageType::Png, imageShape);
        }
        //ExEnd
    }

    //ExStart
    //ExFor:HtmlLoadOptions.WebRequestTimeout
    //ExSummary:Shows how to set a time limit for web requests that will occur when loading an html document which links external resources.
    void WebRequestTimeout()
    {
        // Create a new HtmlLoadOptions object and verify its timeout threshold for a web request
        auto options = MakeObject<HtmlLoadOptions>();

        // When loading an Html document with resources externally linked by a web address URL,
        // web requests that fetch these resources that fail to complete within this time limit will be aborted
        ASSERT_EQ(100000, options->get_WebRequestTimeout());

        // Set a WarningCallback that will record all warnings that occur during loading
        auto warningCallback = MakeObject<ExHtmlLoadOptions::ListDocumentWarnings>();
        options->set_WarningCallback(warningCallback);

        // Load such a document and verify that a shape with image data has been created,
        // provided the request to get that image took place within the timeout limit
        String html =
            String(u"<html>\n    <img src=\"") + AsposeLogoUrl + u"\" alt=\"Aspose logo\" style=\"width:400px;height:400px;\">\n</html>";

        auto doc = MakeObject<Document>(MakeObject<System::IO::MemoryStream>(System::Text::Encoding::get_UTF8()->GetBytes(html)), options);
        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        ASSERT_EQ(7498, imageShape->get_ImageData()->get_ImageBytes()->get_Length());
        ASSERT_EQ(0, warningCallback->Warnings()->get_Count());

        // Set an unreasonable timeout limit and load the document again
        options->set_WebRequestTimeout(0);
        doc = MakeObject<Document>(MakeObject<System::IO::MemoryStream>(System::Text::Encoding::get_UTF8()->GetBytes(html)), options);

        // If a request fails to complete within the timeout limit, a shape with image data will still be produced
        // However, the image will be the red 'x' that commonly signifies missing images
        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));
        ASSERT_EQ(924, imageShape->get_ImageData()->get_ImageBytes()->get_Length());

        // A timeout like this will also accumulate warnings that can be picked up by a WarningCallback implementation
        ASSERT_EQ(WarningSource::Html, warningCallback->Warnings()->idx_get(0)->get_Source());
        ASSERT_EQ(WarningType::DataLoss, warningCallback->Warnings()->idx_get(0)->get_WarningType());
        ASSERT_EQ(String::Format(u"Couldn't load a resource from \'{0}\'.", AsposeLogoUrl), warningCallback->Warnings()->idx_get(0)->get_Description());

        ASSERT_EQ(WarningSource::Html, warningCallback->Warnings()->idx_get(1)->get_Source());
        ASSERT_EQ(WarningType::DataLoss, warningCallback->Warnings()->idx_get(1)->get_WarningType());
        ASSERT_EQ(u"Image has been replaced with a placeholder.", warningCallback->Warnings()->idx_get(1)->get_Description());

        doc->Save(ArtifactsDir + u"HtmlLoadOptions.WebRequestTimeout.docx");
    }

private:
    /// <summary>
    /// Stores all warnings that occur during a document loading operation in a List.
    /// </summary>
    class ListDocumentWarnings : public IWarningCallback
    {
    public:
        void Warning(SharedPtr<WarningInfo> info) override
        {
            mWarnings->Add(info);
        }

        SharedPtr<System::Collections::Generic::List<SharedPtr<WarningInfo>>> Warnings()
        {
            return mWarnings;
        }

        ListDocumentWarnings() : mWarnings(MakeObject<System::Collections::Generic::List<SharedPtr<WarningInfo>>>())
        {
        }

    private:
        SharedPtr<System::Collections::Generic::List<SharedPtr<WarningInfo>>> mWarnings;
    };
    //ExEnd

public:
    void EncryptedHtml()
    {
        //ExStart
        //ExFor:HtmlLoadOptions.#ctor(String)
        //ExSummary:Shows how to encrypt an Html document and then open it using a password.
        // Create and sign an encrypted html document from an encrypted .docx
        SharedPtr<CertificateHolder> certificateHolder = CertificateHolder::Create(MyDir + u"morzal.pfx", u"aw");

        auto signOptions = MakeObject<SignOptions>();
        signOptions->set_Comments(u"Comment");
        signOptions->set_SignTime(System::DateTime::get_Now());
        signOptions->set_DecryptionPassword(u"docPassword");

        String inputFileName = MyDir + u"Encrypted.docx";
        String outputFileName = ArtifactsDir + u"HtmlLoadOptions.EncryptedHtml.html";
        DigitalSignatureUtil::Sign(inputFileName, outputFileName, certificateHolder, signOptions);

        // This .html document will need a password to be decrypted, opened and have its contents accessed
        // The password is specified by HtmlLoadOptions.Password
        auto loadOptions = MakeObject<HtmlLoadOptions>(u"docPassword");
        ASSERT_EQ(signOptions->get_DecryptionPassword(), loadOptions->get_Password());

        auto doc = MakeObject<Document>(outputFileName, loadOptions);
        ASSERT_EQ(u"Test encrypted document.", doc->GetText().Trim());
        //ExEnd
    }

    void BaseUri()
    {
        //ExStart
        //ExFor:HtmlLoadOptions.#ctor(LoadFormat,String,String)
        //ExFor:LoadOptions.LoadFormat
        //ExFor:LoadFormat
        //ExSummary:Shows how to specify a base URI when opening an html document.
        // If we want to load an .html document which contains an image linked by a relative URI
        // while the image is in a different location, we will need to resolve the relative URI into an absolute one
        // by creating an HtmlLoadOptions and providing a base URI
        auto loadOptions = MakeObject<HtmlLoadOptions>(LoadFormat::Html, u"", ImageDir);

        ASSERT_EQ(LoadFormat::Html, loadOptions->get_LoadFormat());

        auto doc = MakeObject<Document>(MyDir + u"Missing image.html", loadOptions);

        // While the image was broken in the input .html, it was successfully found in our base URI
        auto imageShape = System::DynamicCast<Shape>(doc->GetChildNodes(NodeType::Shape, true)->idx_get(0));
        ASSERT_TRUE(imageShape->get_IsImage());

        // The image will be displayed correctly by the output document
        doc->Save(ArtifactsDir + u"HtmlLoadOptions.BaseUri.docx");
        //ExEnd
    }

    void GetSelectAsSdt()
    {
        //ExStart
        //ExFor:HtmlLoadOptions.PreferredControlType
        //ExSummary:Shows how to set preferred type of document nodes that will represent imported <input> and <select> elements.
        const String html = u"\r\n                <html>\r\n                    <select name='ComboBox' size='1'>\r\n                        <option "
                                    u"value='val1'>item1</option>\r\n                        <option value='val2'></option>                        \r\n        "
                                    u"            </select>\r\n                </html>\r\n            ";

        auto htmlLoadOptions = MakeObject<HtmlLoadOptions>();
        htmlLoadOptions->set_PreferredControlType(HtmlControlType::StructuredDocumentTag);

        auto doc =
            MakeObject<Document>(MakeObject<System::IO::MemoryStream>(System::Text::Encoding::get_UTF8()->GetBytes(html)), htmlLoadOptions);
        SharedPtr<NodeCollection> nodes = doc->GetChildNodes(NodeType::StructuredDocumentTag, true);

        auto tag = System::DynamicCast<StructuredDocumentTag>(nodes->idx_get(0));
        //ExEnd

        ASSERT_EQ(2, tag->get_ListItems()->get_Count());

        ASSERT_EQ(u"val1", tag->get_ListItems()->idx_get(0)->get_Value());
        ASSERT_EQ(u"val2", tag->get_ListItems()->idx_get(1)->get_Value());
    }

    void GetInputAsFormField()
    {
        const String html =
            u"\r\n                <html>\r\n                    <input type='text' value='Input value text' />\r\n                </html>\r\n            ";

        // By default, "HtmlLoadOptions.PreferredControlType" value is "HtmlControlType.FormField"
        // So, we do not set this value
        auto htmlLoadOptions = MakeObject<HtmlLoadOptions>();

        auto doc =
            MakeObject<Document>(MakeObject<System::IO::MemoryStream>(System::Text::Encoding::get_UTF8()->GetBytes(html)), htmlLoadOptions);
        SharedPtr<NodeCollection> nodes = doc->GetChildNodes(NodeType::FormField, true);

        ASSERT_EQ(1, nodes->get_Count());

        auto formField = System::DynamicCast<FormField>(nodes->idx_get(0));
        ASSERT_EQ(u"Input value text", formField->get_Result());
    }
};

} // namespace ApiExamples
