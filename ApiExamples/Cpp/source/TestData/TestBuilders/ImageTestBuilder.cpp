﻿#include "TestData/TestBuilders/ImageTestBuilder.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/scope_guard.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/array.h>
#include <drawing/image.h>
#include <cstdint>

#include "TestData/TestClasses/ImageTestClass.h"


using namespace ApiExamples::TestData::TestClasses;
namespace ApiExamples {

namespace TestData {

namespace TestBuilders {

ImageTestBuilder::ImageTestBuilder()
{
    //Self Reference+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    System::Details::ThisProtector __local_self_ref(this);
    //---------------------------------------------------------Self Reference
    
    mImage = System::Drawing::Image::FromFile(ImageDir + u"Transparent background logo.png");
    mImageStream = System::IO::Stream::Null;
    mImageBytes = System::MakeArray<uint8_t>(0, 0);
    mImageString = System::String::Empty;
}

System::SharedPtr<ImageTestBuilder> ImageTestBuilder::WithImage(System::SharedPtr<System::Drawing::Image> image)
{
    mImage = image;
    return System::MakeSharedPtr(this);
}

System::SharedPtr<ImageTestBuilder> ImageTestBuilder::WithImageStream(System::SharedPtr<System::IO::Stream> imageStream)
{
    mImageStream = imageStream;
    return System::MakeSharedPtr(this);
}

System::SharedPtr<ImageTestBuilder> ImageTestBuilder::WithImageBytes(System::ArrayPtr<uint8_t> imageBytes)
{
    mImageBytes = imageBytes;
    return System::MakeSharedPtr(this);
}

System::SharedPtr<ImageTestBuilder> ImageTestBuilder::WithImageString(System::String imageString)
{
    mImageString = imageString;
    return System::MakeSharedPtr(this);
}

System::SharedPtr<ImageTestClass> ImageTestBuilder::Build()
{
    return System::MakeObject<ImageTestClass>(mImage, mImageStream, mImageBytes, mImageString);
}

ImageTestBuilder::~ImageTestBuilder()
{
}

} // namespace TestBuilders
} // namespace TestData
} // namespace ApiExamples
