﻿#include "TestData/TestClasses/DocumentTestClass.h"

#include <system/string.h>
#include <system/scope_guard.h>
#include <system/io/stream.h>
#include <system/array.h>
#include <cstdint>
#include <Aspose.Words.Cpp/Model/Document/Document.h>


using namespace Aspose::Words;
namespace ApiExamples {

namespace TestData {

namespace TestClasses {

System::SharedPtr<Aspose::Words::Document> DocumentTestClass::get_Document()
{
    return pr_Document;
}

void DocumentTestClass::set_Document(System::SharedPtr<Aspose::Words::Document> value)
{
    pr_Document = value;
}

System::SharedPtr<System::IO::Stream> DocumentTestClass::get_DocumentStream()
{
    return pr_DocumentStream;
}

void DocumentTestClass::set_DocumentStream(System::SharedPtr<System::IO::Stream> value)
{
    pr_DocumentStream = value;
}

System::ArrayPtr<uint8_t> DocumentTestClass::get_DocumentBytes()
{
    return pr_DocumentBytes;
}

void DocumentTestClass::set_DocumentBytes(System::ArrayPtr<uint8_t> value)
{
    pr_DocumentBytes = value;
}

System::String DocumentTestClass::get_DocumentString()
{
    return pr_DocumentString;
}

void DocumentTestClass::set_DocumentString(System::String value)
{
    pr_DocumentString = value;
}

DocumentTestClass::DocumentTestClass(System::SharedPtr<Aspose::Words::Document> doc, System::SharedPtr<System::IO::Stream> docStream, System::ArrayPtr<uint8_t> docBytes, System::String docString)
{
    //Self Reference+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    System::Details::ThisProtector __local_self_ref(this);
    //---------------------------------------------------------Self Reference
    
    set_Document(doc);
    set_DocumentStream(docStream);
    set_DocumentBytes(docBytes);
    set_DocumentString(docString);
}

} // namespace TestClasses
} // namespace TestData
} // namespace ApiExamples
