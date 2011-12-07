// ****************************************************************************
//  vlc_video_split.cpp                                             Tao project
// ****************************************************************************
//
//   File Description:
//
//   Decode slideshow video.
//
//
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriété de Taodyne SAS - Confidentiel
//  (C) 2011 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
//  (C) 2011 Taodyne SAS
// ****************************************************************************
#include "split_decoder.h"

// ============================================================================
//
//   Split decoder
//
// ============================================================================


SplitDecoder::SplitDecoder(Format format)
// ----------------------------------------------------------------------------
//   Construction
// ----------------------------------------------------------------------------
    : format(format)
{
}


SplitDecoder::~SplitDecoder()
// ----------------------------------------------------------------------------
//   Destruction
// ----------------------------------------------------------------------------
{
}


void SplitDecoder::render_callback(void *arg)
// ----------------------------------------------------------------------------
//   Rendering callback: call the render function for the object
// ----------------------------------------------------------------------------
{
    ((SplitDecoder *)arg)->Draw();
}


void SplitDecoder::identify_callback(void *)
// ----------------------------------------------------------------------------
//   Identify callback: don't do anything
// ----------------------------------------------------------------------------
{
}


void SplitDecoder::delete_callback(void *arg)
// ----------------------------------------------------------------------------
//   Delete callback: destroy object
// ----------------------------------------------------------------------------
{
    delete (SplitDecoder *)arg;
}


void SplitDecoder::Draw()
// ----------------------------------------------------------------------------
//   Draw
// ----------------------------------------------------------------------------
{
    if (!tested)
    {
        licensed = tao->checkLicense("StereoDecoder 1.0", false);
        tested = true;
    }
    if (!licensed && !tao->blink(1.0, 1.0))
        return;

    int eye     = tao->getCurrentEye();
    int eyeMax  = tao->getEyesNumber();

    // Compatbility with Alioscopy
    if(eyeMax > 2)
        eye = 1;

    float scale = 0.5;
    float trans = (eye - 1) * 0.5;

    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    switch(format)
    {
        case HORIZONTAL:
            glTranslatef(trans, 0.0, 0.0);
            glScalef(scale, 1.0, 1.0);
            break;
        case VERTICAL:
            glTranslatef(0.0, trans, 0.0);
            glScalef(1.0, scale, 1.0);
            break;
    }
    glMatrixMode(GL_MODELVIEW);
}

