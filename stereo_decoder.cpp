// ****************************************************************************
//  stereo_decoder.cpp                                              Tao project
// ****************************************************************************
//
//   File Description:
//
//     Implementation of the XL primitives for the "StereoDecoder" module.
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

#include "stereo_decoder.h"
#include <iostream>
#include "coords3d.h"

XL_DEFINE_TRACES

// -------------------------------------------------------------------------------------------------------------------
//   SPLIT DECODER
// -------------------------------------------------------------------------------------------------------------------


Tree_p decode_horizontal_split(Tree_p)
// ----------------------------------------------------------------------------
//   Define horizontal split format
// ----------------------------------------------------------------------------
{
    SplitDecoder* decoder = new SplitDecoder(SplitDecoder::HORIZONTAL);
    Decoder::tao->AddToLayout2(SplitDecoder::render_callback,
                               SplitDecoder::identify_callback,
                               decoder, SplitDecoder::delete_callback);
    return xl_true;
}


Tree_p decode_vertical_split(Tree_p)
// ----------------------------------------------------------------------------
//   Define vertical split format
// ----------------------------------------------------------------------------
{       
    SplitDecoder* decoder = new SplitDecoder(SplitDecoder::VERTICAL);
    Decoder::tao->AddToLayout2(SplitDecoder::render_callback,
                               SplitDecoder::identify_callback,
                               decoder, SplitDecoder::delete_callback);

    return xl_true;
}


int module_init(const Tao::ModuleApi *api, const Tao::ModuleInfo *)
// ----------------------------------------------------------------------------
//   Initialize the Tao module
// ----------------------------------------------------------------------------
{
    glewInit();
    XL_INIT_TRACES();

    Decoder::tao = api;

    return 0;
}


int module_exit()
// ----------------------------------------------------------------------------
//   Uninitialize the Tao module
// ----------------------------------------------------------------------------
{
    return 0;
}
