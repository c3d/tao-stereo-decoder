#ifndef STEREO_DECODER_H
#define STEREO_DECODER_H
// ****************************************************************************
//  stereo_decoder.h                                                Tao project
// ****************************************************************************
//
//   File Description:
//
//    Prototype of the function used by stereo_decoder.tbl to
//    implement the new XL primitive
//
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriété de Taodyne SAS - Confidentiel
//  (C) 1992-2010 Christophe de Dinechin <christophe@taodyne.com>
//  (C) 2010 Jerome Forissier <jerome@taodyne.com>
//  (C) 2011 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
//  (C) 2011 Taodyne SAS
// ****************************************************************************
#include "tree.h"
#include "main.h"
#include "runtime.h"
#include "base.h"
#include "tao/module_api.h"
#include "split_decoder.h"

using namespace XL;

// -------------------------------------------------------------------------------------------------------------------
//   SPLIT DECODER
// -------------------------------------------------------------------------------------------------------------------

Tree_p decode_horizontal_split(Tree_p);
Tree_p decode_vertical_split(Tree_p);


#endif
