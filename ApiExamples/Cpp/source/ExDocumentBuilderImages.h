﻿#pragma once
// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <Aspose.Words.Cpp/Model/Document/BreakType.h>
#include <Aspose.Words.Cpp/Model/Document/ConvertUtil.h>
#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Document/DocumentBuilder.h>
#include <Aspose.Words.Cpp/Model/Drawing/ImageData.h>
#include <Aspose.Words.Cpp/Model/Drawing/ImageSize.h>
#include <Aspose.Words.Cpp/Model/Drawing/ImageType.h>
#include <Aspose.Words.Cpp/Model/Drawing/RelativeHorizontalPosition.h>
#include <Aspose.Words.Cpp/Model/Drawing/RelativeVerticalPosition.h>
#include <Aspose.Words.Cpp/Model/Drawing/Shape.h>
#include <Aspose.Words.Cpp/Model/Drawing/WrapType.h>
#include <Aspose.Words.Cpp/Model/Nodes/Node.h>
#include <Aspose.Words.Cpp/Model/Nodes/NodeType.h>
#include <Aspose.Words.Cpp/Model/Saving/SaveOutputParameters.h>
#include <drawing/image.h>
#include <drawing/imaging/image_format.h>
#include <system/array.h>
#include <system/details/dispose_guard.h>
#include <system/exceptions.h>
#include <system/io/file.h>
#include <system/io/file_stream.h>
#include <system/io/memory_stream.h>
#include <system/io/stream.h>
#include <system/test_tools/compare.h>
#include <system/test_tools/test_tools.h>
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

namespace ApiExamples {

class ExDocumentBuilderImages : public ApiExampleBase
{
public:
    void InsertImageFromStream()
    {
        //ExStart
        //ExFor:DocumentBuilder.InsertImage(Stream)
        //ExFor:DocumentBuilder.InsertImage(Stream, Double, Double)
        //ExFor:DocumentBuilder.InsertImage(Stream, RelativeHorizontalPosition, Double, RelativeVerticalPosition, Double, Double, Double, WrapType)
        //ExSummary:Shows how to insert an image from a stream into a document.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        {
            SharedPtr<System::IO::Stream> stream = System::IO::File::OpenRead(ImageDir + u"Logo.jpg");
            // Below are three ways of inserting an image from a stream:
            // 1 -  Inline shape with a default size based on the image's original dimensions:
            builder->InsertImage(stream);

            builder->InsertBreak(BreakType::PageBreak);

            // 2 -  Inline shape with custom dimensions:
            builder->InsertImage(stream, ConvertUtil::PixelToPoint(250), ConvertUtil::PixelToPoint(144));

            builder->InsertBreak(BreakType::PageBreak);

            // 3 -  Floating shape with custom dimensions:
            builder->InsertImage(stream, RelativeHorizontalPosition::Margin, 100.0, RelativeVerticalPosition::Margin, 100.0, 200.0, 100.0, WrapType::Square);
        }

        doc->Save(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromStream.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromStream.docx");

        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 1, true));

        ASPOSE_ASSERT_EQ(108.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(187.5, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 2, true));

        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(200.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Square, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Margin, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Margin, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());
    }

    void InsertImageFromFilename()
    {
        //ExStart
        //ExFor:DocumentBuilder.InsertImage(String)
        //ExFor:DocumentBuilder.InsertImage(String, Double, Double)
        //ExFor:DocumentBuilder.InsertImage(String, RelativeHorizontalPosition, Double, RelativeVerticalPosition, Double, Double, Double, WrapType)
        //ExSummary:Shows how to insert an image from the local file system into a document.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Below are three ways of inserting an image from a local system filename:
        // 1 -  Inline shape with a default size based on the image's original dimensions:
        builder->InsertImage(ImageDir + u"Logo.jpg");

        builder->InsertBreak(BreakType::PageBreak);

        // 2 -  Inline shape with custom dimensions:
        builder->InsertImage(ImageDir + u"Transparent background logo.png", ConvertUtil::PixelToPoint(250), ConvertUtil::PixelToPoint(144));

        builder->InsertBreak(BreakType::PageBreak);

        // 3 -  Floating shape with custom dimensions:
        builder->InsertImage(ImageDir + u"Windows MetaFile.wmf", RelativeHorizontalPosition::Margin, 100.0, RelativeVerticalPosition::Margin, 100.0, 200.0,
                             100.0, WrapType::Square);

        doc->Save(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromFilename.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromFilename.docx");

        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 1, true));

        ASPOSE_ASSERT_EQ(108.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(187.5, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Png, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 2, true));

        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(200.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Square, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Margin, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Margin, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(1600, 1600, ImageType::Wmf, imageShape);
        ASPOSE_ASSERT_EQ(400.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(400.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());
    }

    void InsertImageFromImageObject()
    {
        //ExStart
        //ExFor:DocumentBuilder.InsertImage(Image, Double, Double)
        //ExFor:DocumentBuilder.InsertImage(Image, RelativeHorizontalPosition, Double, RelativeVerticalPosition, Double, Double, Double, WrapType)
        //ExSummary:Shows how to insert an image from an object into a document.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        SharedPtr<System::Drawing::Image> image = System::Drawing::Image::FromFile(ImageDir + u"Logo.jpg");

        // Below are three ways of inserting an image from an Image object instance:
        // 1 -  Inline shape with a default size based on the image's original dimensions:
        builder->InsertImage(image);

        builder->InsertBreak(BreakType::PageBreak);

        // 2 -  Inline shape with custom dimensions:
        builder->InsertImage(image, ConvertUtil::PixelToPoint(250), ConvertUtil::PixelToPoint(144));

        builder->InsertBreak(BreakType::PageBreak);

        // 3 -  Floating shape with custom dimensions:
        builder->InsertImage(image, RelativeHorizontalPosition::Margin, 100.0, RelativeVerticalPosition::Margin, 100.0, 200.0, 100.0, WrapType::Square);

        doc->Save(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromImageObject.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromImageObject.docx");

        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 1, true));

        ASPOSE_ASSERT_EQ(108.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(187.5, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 2, true));

        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(200.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Square, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Margin, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Margin, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Jpeg, imageShape);
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints());
        ASPOSE_ASSERT_EQ(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints());
    }

    void InsertImageFromByteArray()
    {
        //ExStart
        //ExFor:DocumentBuilder.InsertImage(Byte[])
        //ExFor:DocumentBuilder.InsertImage(Byte[], Double, Double)
        //ExFor:DocumentBuilder.InsertImage(Byte[], RelativeHorizontalPosition, Double, RelativeVerticalPosition, Double, Double, Double, WrapType)
        //ExSummary:Shows how to insert an image from a byte array into a document.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        SharedPtr<System::Drawing::Image> image = System::Drawing::Image::FromFile(ImageDir + u"Logo.jpg");

        {
            auto ms = MakeObject<System::IO::MemoryStream>();
            image->Save(ms, System::Drawing::Imaging::ImageFormat::get_Png());
            ArrayPtr<uint8_t> imageByteArray = ms->ToArray();

            // Below are three ways of inserting an image from a byte array:
            // 1 -  Inline shape with a default size based on the image's original dimensions:
            builder->InsertImage(imageByteArray);

            builder->InsertBreak(BreakType::PageBreak);

            // 2 -  Inline shape with custom dimensions:
            builder->InsertImage(imageByteArray, ConvertUtil::PixelToPoint(250), ConvertUtil::PixelToPoint(144));

            builder->InsertBreak(BreakType::PageBreak);

            // 3 -  Floating shape with custom dimensions:
            builder->InsertImage(imageByteArray, RelativeHorizontalPosition::Margin, 100.0, RelativeVerticalPosition::Margin, 100.0, 200.0, 100.0,
                                 WrapType::Square);
        }

        doc->Save(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromByteArray.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"DocumentBuilderImages.InsertImageFromByteArray.docx");

        auto imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 0, true));

        ASSERT_NEAR(300.0, imageShape->get_Height(), 0.1);
        ASSERT_NEAR(300.0, imageShape->get_Width(), 0.1);
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Png, imageShape);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints(), 0.1);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints(), 0.1);

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 1, true));

        ASPOSE_ASSERT_EQ(108.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(187.5, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(0.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Inline, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Column, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Paragraph, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Png, imageShape);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints(), 0.1);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints(), 0.1);

        imageShape = System::DynamicCast<Shape>(doc->GetChild(NodeType::Shape, 2, true));

        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Height());
        ASPOSE_ASSERT_EQ(200.0, imageShape->get_Width());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Left());
        ASPOSE_ASSERT_EQ(100.0, imageShape->get_Top());

        ASSERT_EQ(WrapType::Square, imageShape->get_WrapType());
        ASSERT_EQ(RelativeHorizontalPosition::Margin, imageShape->get_RelativeHorizontalPosition());
        ASSERT_EQ(RelativeVerticalPosition::Margin, imageShape->get_RelativeVerticalPosition());

        TestUtil::VerifyImageInShape(400, 400, ImageType::Png, imageShape);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_HeightPoints(), 0.1);
        ASSERT_NEAR(300.0, imageShape->get_ImageData()->get_ImageSize()->get_WidthPoints(), 0.1);
    }
};

} // namespace ApiExamples
