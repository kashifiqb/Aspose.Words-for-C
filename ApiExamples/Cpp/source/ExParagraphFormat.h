﻿#pragma once
// Copyright (c) 2001-2020 Aspose Pty Ltd. All Rights Reserved.
// This file is part of Aspose.Words. The source code in this file
// is only intended as a supplement to the documentation, and is provided
// "as is", without warranty of any kind, either expressed or implied.
//////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <Aspose.Words.Cpp/Model/Document/Document.h>
#include <Aspose.Words.Cpp/Model/Document/DocumentBuilder.h>
#include <Aspose.Words.Cpp/Model/Saving/SaveOutputParameters.h>
#include <Aspose.Words.Cpp/Model/Sections/Body.h>
#include <Aspose.Words.Cpp/Model/Sections/Section.h>
#include <Aspose.Words.Cpp/Model/Text/DropCapPosition.h>
#include <Aspose.Words.Cpp/Model/Text/Font.h>
#include <Aspose.Words.Cpp/Model/Text/LineSpacingRule.h>
#include <Aspose.Words.Cpp/Model/Text/OutlineLevel.h>
#include <Aspose.Words.Cpp/Model/Text/Paragraph.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphCollection.h>
#include <Aspose.Words.Cpp/Model/Text/ParagraphFormat.h>
#include <Aspose.Words.Cpp/Model/Text/Run.h>
#include <Aspose.Words.Cpp/Model/Text/RunCollection.h>
#include <system/test_tools/compare.h>
#include <system/test_tools/test_tools.h>
#include <testing/test_predicates.h>

#include "ApiExampleBase.h"
#include "DocumentHelper.h"

using System::String;
using System::SharedPtr;
using System::ArrayPtr;
using System::MakeObject;
using System::MakeArray;

using namespace Aspose::Words;

namespace ApiExamples {

class ExParagraphFormat : public ApiExampleBase
{
public:
    void AsianTypographyProperties()
    {
        //ExStart
        //ExFor:ParagraphFormat.FarEastLineBreakControl
        //ExFor:ParagraphFormat.WordWrap
        //ExFor:ParagraphFormat.HangingPunctuation
        //ExSummary:Shows how to set special properties for Asian typography.
        auto doc = MakeObject<Document>(MyDir + u"Document.docx");

        SharedPtr<ParagraphFormat> format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();
        format->set_FarEastLineBreakControl(true);
        format->set_WordWrap(false);
        format->set_HangingPunctuation(true);

        doc->Save(ArtifactsDir + u"ParagraphFormat.AsianTypographyProperties.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.AsianTypographyProperties.docx");
        format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();

        ASSERT_TRUE(format->get_FarEastLineBreakControl());
        ASSERT_FALSE(format->get_WordWrap());
        ASSERT_TRUE(format->get_HangingPunctuation());
    }

    void DropCap()
    {
        //ExStart
        //ExFor:DropCapPosition
        //ExSummary:Shows how to set the position of a drop cap.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Every paragraph has its own drop cap setting
        SharedPtr<ParagraphFormat> format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();

        // By default, it is "none", for no drop caps
        ASSERT_EQ(DropCapPosition::None, format->get_DropCapPosition());

        // Move the first capital to outside the text margin
        format->set_DropCapPosition(DropCapPosition::Margin);
        format->set_LinesToDrop(2);

        // This text will be affected
        builder->Write(u"Hello world!");

        doc->Save(ArtifactsDir + u"ParagraphFormat.DropCap.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.DropCap.docx");
        format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();

        ASSERT_EQ(DropCapPosition::Margin, format->get_DropCapPosition());
        ASSERT_EQ(2, format->get_LinesToDrop());
    }

    void LineSpacing()
    {
        //ExStart
        //ExFor:ParagraphFormat.LineSpacing
        //ExFor:ParagraphFormat.LineSpacingRule
        //ExSummary:Shows how to work with line spacing.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Set the paragraph's line spacing to have a minimum value
        // This will give vertical padding to lines of text of any size that's too small to maintain the line height
        builder->get_ParagraphFormat()->set_LineSpacingRule(LineSpacingRule::AtLeast);
        builder->get_ParagraphFormat()->set_LineSpacing(20.0);

        builder->Writeln(u"Minimum line spacing of 20.");
        builder->Writeln(u"Minimum line spacing of 20.");

        // Set the line spacing to always be exactly 5 points
        // If the font size is larger than the spacing, the top of the text will be truncated
        builder->get_ParagraphFormat()->set_LineSpacingRule(LineSpacingRule::Exactly);
        builder->get_ParagraphFormat()->set_LineSpacing(5.0);

        builder->Writeln(u"Line spacing of exactly 5.");
        builder->Writeln(u"Line spacing of exactly 5.");

        // Set the line spacing to a multiple of the default line spacing, which is 12 points by default
        // 18 points will set the spacing to always be 1.5 lines, which will scale with different font sizes
        builder->get_ParagraphFormat()->set_LineSpacingRule(LineSpacingRule::Multiple);
        builder->get_ParagraphFormat()->set_LineSpacing(18.0);

        builder->Writeln(u"Line spacing of 1.5 default lines.");
        builder->Writeln(u"Line spacing of 1.5 default lines.");

        doc->Save(ArtifactsDir + u"ParagraphFormat.LineSpacing.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.LineSpacing.docx");
        SharedPtr<ParagraphCollection> paragraphs = doc->get_FirstSection()->get_Body()->get_Paragraphs();

        ASSERT_EQ(LineSpacingRule::AtLeast, paragraphs->idx_get(0)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(20.0, paragraphs->idx_get(0)->get_ParagraphFormat()->get_LineSpacing());
        ASSERT_EQ(LineSpacingRule::AtLeast, paragraphs->idx_get(1)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(20.0, paragraphs->idx_get(1)->get_ParagraphFormat()->get_LineSpacing());

        ASSERT_EQ(LineSpacingRule::Exactly, paragraphs->idx_get(2)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(5.0, paragraphs->idx_get(2)->get_ParagraphFormat()->get_LineSpacing());
        ASSERT_EQ(LineSpacingRule::Exactly, paragraphs->idx_get(3)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(5.0, paragraphs->idx_get(3)->get_ParagraphFormat()->get_LineSpacing());

        ASSERT_EQ(LineSpacingRule::Multiple, paragraphs->idx_get(4)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(18.0, paragraphs->idx_get(4)->get_ParagraphFormat()->get_LineSpacing());
        ASSERT_EQ(LineSpacingRule::Multiple, paragraphs->idx_get(5)->get_ParagraphFormat()->get_LineSpacingRule());
        ASPOSE_ASSERT_EQ(18.0, paragraphs->idx_get(5)->get_ParagraphFormat()->get_LineSpacing());
    }

    void ParagraphSpacing()
    {
        //ExStart
        //ExFor:ParagraphFormat.NoSpaceBetweenParagraphsOfSameStyle
        //ExFor:ParagraphFormat.SpaceAfter
        //ExFor:ParagraphFormat.SpaceAfterAuto
        //ExFor:ParagraphFormat.SpaceBefore
        //ExFor:ParagraphFormat.SpaceBeforeAuto
        //ExSummary:Shows how to work with paragraph spacing.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Set the amount of white space before and after each paragraph to 12 points
        builder->get_ParagraphFormat()->set_SpaceBefore(12.0f);
        builder->get_ParagraphFormat()->set_SpaceAfter(12.0f);

        // We can set these flags to apply default spacing, effectively ignoring the spacing in the attributes we set above
        ASSERT_FALSE(builder->get_ParagraphFormat()->get_SpaceAfterAuto());
        ASSERT_FALSE(builder->get_ParagraphFormat()->get_SpaceBeforeAuto());
        ASSERT_FALSE(builder->get_ParagraphFormat()->get_NoSpaceBetweenParagraphsOfSameStyle());

        // Insert two paragraphs which will have padding above and below them and save the document
        builder->Writeln(u"Paragraph 1.");
        builder->Writeln(u"Paragraph 2.");

        doc->Save(ArtifactsDir + u"ParagraphFormat.ParagraphSpacing.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.ParagraphSpacing.docx");
        SharedPtr<ParagraphFormat> format = doc->get_FirstSection()->get_Body()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat();

        ASPOSE_ASSERT_EQ(12.0, format->get_SpaceBefore());
        ASPOSE_ASSERT_EQ(12.0, format->get_SpaceAfter());
        ASSERT_FALSE(format->get_SpaceAfterAuto());
        ASSERT_FALSE(format->get_SpaceBeforeAuto());
        ASSERT_FALSE(format->get_NoSpaceBetweenParagraphsOfSameStyle());

        format = doc->get_FirstSection()->get_Body()->get_Paragraphs()->idx_get(1)->get_ParagraphFormat();

        ASPOSE_ASSERT_EQ(12.0, format->get_SpaceBefore());
        ASPOSE_ASSERT_EQ(12.0, format->get_SpaceAfter());
        ASSERT_FALSE(format->get_SpaceAfterAuto());
        ASSERT_FALSE(format->get_SpaceBeforeAuto());
        ASSERT_FALSE(format->get_NoSpaceBetweenParagraphsOfSameStyle());
    }

    void ParagraphOutlineLevel()
    {
        //ExStart
        //ExFor:ParagraphFormat.OutlineLevel
        //ExSummary:Shows how to set paragraph outline levels to create collapsible text.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Each paragraph has an OutlineLevel, which could be any number from 1 to 9, or at the default "BodyText" value
        // Setting the attribute to one of the numbered values will enable an arrow in Microsoft Word
        // next to the beginning of the paragraph that, when clicked, will collapse the paragraph
        builder->get_ParagraphFormat()->set_OutlineLevel(OutlineLevel::Level1);
        builder->Writeln(u"Paragraph outline level 1.");

        // Level 1 is the topmost level, which practically means that clicking its arrow will also collapse
        // any following paragraph with a lower level, like the paragraphs below
        builder->get_ParagraphFormat()->set_OutlineLevel(OutlineLevel::Level2);
        builder->Writeln(u"Paragraph outline level 2.");

        // Two paragraphs of the same level will not collapse each other
        builder->get_ParagraphFormat()->set_OutlineLevel(OutlineLevel::Level3);
        builder->Writeln(u"Paragraph outline level 3.");
        builder->Writeln(u"Paragraph outline level 3.");

        // The default "BodyText" value is the lowest
        builder->get_ParagraphFormat()->set_OutlineLevel(OutlineLevel::BodyText);
        builder->Writeln(u"Paragraph at main text level.");

        doc->Save(ArtifactsDir + u"ParagraphFormat.ParagraphOutlineLevel.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.ParagraphOutlineLevel.docx");
        SharedPtr<ParagraphCollection> paragraphs = doc->get_FirstSection()->get_Body()->get_Paragraphs();

        ASSERT_EQ(OutlineLevel::Level1, paragraphs->idx_get(0)->get_ParagraphFormat()->get_OutlineLevel());
        ASSERT_EQ(OutlineLevel::Level2, paragraphs->idx_get(1)->get_ParagraphFormat()->get_OutlineLevel());
        ASSERT_EQ(OutlineLevel::Level3, paragraphs->idx_get(2)->get_ParagraphFormat()->get_OutlineLevel());
        ASSERT_EQ(OutlineLevel::Level3, paragraphs->idx_get(3)->get_ParagraphFormat()->get_OutlineLevel());
        ASSERT_EQ(OutlineLevel::BodyText, paragraphs->idx_get(4)->get_ParagraphFormat()->get_OutlineLevel());
    }

    void PageBreakBefore()
    {
        //ExStart
        //ExFor:ParagraphFormat.PageBreakBefore
        //ExSummary:Shows how to force a page break before each paragraph.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Set this to insert a page break before this paragraph
        builder->get_ParagraphFormat()->set_PageBreakBefore(true);

        // The value we set is propagated to all paragraphs that are created afterwards
        builder->Writeln(u"Paragraph 1, page 1.");
        builder->Writeln(u"Paragraph 2, page 2.");

        doc->Save(ArtifactsDir + u"ParagraphFormat.PageBreakBefore.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.PageBreakBefore.docx");

        ASSERT_TRUE(doc->get_FirstSection()->get_Body()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat()->get_PageBreakBefore());
        ASSERT_TRUE(doc->get_FirstSection()->get_Body()->get_Paragraphs()->idx_get(1)->get_ParagraphFormat()->get_PageBreakBefore());
    }

    void WidowControl()
    {
        //ExStart
        //ExFor:ParagraphFormat.WidowControl
        //ExSummary:Shows how to enable widow/orphan control for a paragraph.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Insert text that will not fit on one page, with one line spilling into page 2
        builder->get_Font()->set_Size(68);
        builder->Writeln(String(u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, ") +
                         u"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

        // This line is referred to as an "Orphan", and a line left behind on the end of the previous page is called a "Widow"
        // They can be fixed by changing size/line spacing/page margins
        // Alternatively, we can use this flag, for which the corresponding Microsoft Word option is
        // found in Home > Paragraph > Paragraph Settings (button on the bottom right of the tab)
        // This will add more text to the orphan by putting two lines of text into the second page
        builder->get_ParagraphFormat()->set_WidowControl(true);

        doc->Save(ArtifactsDir + u"ParagraphFormat.WidowControl.docx");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.WidowControl.docx");

        ASSERT_TRUE(doc->get_FirstSection()->get_Body()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat()->get_WidowControl());
    }

    void LinesToDrop()
    {
        //ExStart
        //ExFor:ParagraphFormat.LinesToDrop
        //ExSummary:Shows how to set the size of the drop cap text.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        // Setting this attribute will designate the current paragraph as a drop cap,
        // in this case with a height of 4 lines of text
        builder->get_ParagraphFormat()->set_LinesToDrop(4);
        builder->Write(u"H");

        // Any subsequent paragraphs will wrap around the drop cap
        builder->InsertParagraph();
        builder->Write(u"ello world!");

        doc->Save(ArtifactsDir + u"ParagraphFormat.LinesToDrop.odt");
        //ExEnd

        doc = MakeObject<Document>(ArtifactsDir + u"ParagraphFormat.LinesToDrop.odt");
        SharedPtr<ParagraphCollection> paragraphs = doc->get_FirstSection()->get_Body()->get_Paragraphs();

        ASSERT_EQ(4, paragraphs->idx_get(0)->get_ParagraphFormat()->get_LinesToDrop());
        ASSERT_EQ(0, paragraphs->idx_get(1)->get_ParagraphFormat()->get_LinesToDrop());
    }

    void SuppressHyphens()
    {
        //ExStart
        //ExFor:ParagraphFormat.SuppressAutoHyphens
        //ExSummary:Shows how to suppress document hyphenation.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);

        builder->get_Font()->set_Size(24);
        builder->get_ParagraphFormat()->set_SuppressAutoHyphens(false);

        builder->Writeln(String(u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, ") +
                         u"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

        doc->Save(ArtifactsDir + u"ParagraphFormat.SuppressHyphens.docx");
        //ExEnd
    }

    void ParagraphSpacingAndIndents()
    {
        //ExStart
        //ExFor:ParagraphFormat.CharacterUnitLeftIndent
        //ExFor:ParagraphFormat.CharacterUnitRightIndent
        //ExFor:ParagraphFormat.CharacterUnitFirstLineIndent
        //ExFor:ParagraphFormat.LineUnitBefore
        //ExFor:ParagraphFormat.LineUnitAfter
        //ExSummary:Shows how to change paragraph spacing and indents.
        auto doc = MakeObject<Document>();
        auto builder = MakeObject<DocumentBuilder>(doc);
        SharedPtr<ParagraphFormat> format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();

        ASPOSE_ASSERT_EQ(format->get_LeftIndent(), 0.0);
        //ExSkip
        ASPOSE_ASSERT_EQ(format->get_RightIndent(), 0.0);
        //ExSkip
        ASPOSE_ASSERT_EQ(format->get_FirstLineIndent(), 0.0);
        //ExSkip
        ASPOSE_ASSERT_EQ(format->get_SpaceBefore(), 0.0);
        //ExSkip
        ASPOSE_ASSERT_EQ(format->get_SpaceAfter(), 0.0);
        //ExSkip

        // Also ParagraphFormat.LeftIndent will be updated
        format->set_CharacterUnitLeftIndent(10.0);
        // Also ParagraphFormat.RightIndent will be updated
        format->set_CharacterUnitRightIndent(-5.5);
        // Also ParagraphFormat.FirstLineIndent will be updated
        format->set_CharacterUnitFirstLineIndent(20.3);
        // Also ParagraphFormat.SpaceBefore will be updated
        format->set_LineUnitBefore(5.1);
        // Also ParagraphFormat.SpaceAfter will be updated
        format->set_LineUnitAfter(10.9);

        builder->Writeln(String(u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, ") +
                         u"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
        builder->Write(String(u"测试文档测试文档测试文档测试文档测试文档测试文档测试文档测试文档测试") +
                       u"文档测试文档测试文档测试文档测试文档测试文档测试文档测试文档测试文档测试文档");
        //ExEnd

        doc = DocumentHelper::SaveOpen(doc);
        format = doc->get_FirstSection()->get_Body()->get_FirstParagraph()->get_ParagraphFormat();

        ASPOSE_ASSERT_EQ(format->get_CharacterUnitLeftIndent(), 10.0);
        ASPOSE_ASSERT_EQ(format->get_LeftIndent(), 120.0);

        ASPOSE_ASSERT_EQ(format->get_CharacterUnitRightIndent(), -5.5);
        ASPOSE_ASSERT_EQ(format->get_RightIndent(), -66.0);

        ASPOSE_ASSERT_EQ(format->get_CharacterUnitFirstLineIndent(), 20.3);
        ASSERT_NEAR(format->get_FirstLineIndent(), 243.59, 0.1);

        ASSERT_NEAR(format->get_LineUnitBefore(), 5.1, 0.1);
        ASSERT_NEAR(format->get_SpaceBefore(), 61.1, 0.1);

        ASPOSE_ASSERT_EQ(format->get_LineUnitAfter(), 10.9);
        ASSERT_NEAR(format->get_SpaceAfter(), 130.8, 0.1);
    }

    void SnapToGrid()
    {
        //ExStart
        //ExFor:ParagraphFormat.SnapToGrid
        //ExSummary:Shows how to work with extremely wide spacing in the document.
        auto doc = MakeObject<Document>();
        SharedPtr<Paragraph> par = doc->get_FirstSection()->get_Body()->get_FirstParagraph();
        // Set 'SnapToGrid' to true if need optimize the layout when typing in Asian characters
        // Use 'SnapToGrid' for the whole paragraph
        par->get_ParagraphFormat()->set_SnapToGrid(true);

        auto builder = MakeObject<DocumentBuilder>(doc);
        builder->Writeln(String(u"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod ") +
                         u"tempor incididunt ut labore et dolore magna aliqua.");
        // Use 'SnapToGrid' for the specific run
        par->get_Runs()->idx_get(0)->get_Font()->set_SnapToGrid(true);

        doc->Save(ArtifactsDir + u"Paragraph.SnapToGrid.docx");
    }
};

} // namespace ApiExamples
