#ifndef SPLIT_DECODER_H
#define SPLIT_DECODER_H
// ****************************************************************************
//  split_decoder.h                                                 Tao project
// ****************************************************************************
//
//   File Description:
//
//      Decoder for slideshow video
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriÃ©tÃ© de Taodyne SAS - Confidentiel
//  (C) 2011 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
//  (C) 2011 Taodyne SAS
// ****************************************************************************

#include "decoder.h"

using namespace std;
using namespace Tao;

struct SplitDecoder : Decoder
{
    enum Format
    {
        HORIZONTAL = 1,
        VERTICAL = 2
    };

    SplitDecoder(int format);
    ~SplitDecoder();

    virtual void    Draw();

    static void     render_callback(void *arg);
    static void     identify_callback(void *arg);
    static void     delete_callback(void *arg);

 private:
   int format;

   static bool failed;
   static QGLShaderProgram* pgm;
   static std::map<text, GLint> uniforms;
};


#endif
