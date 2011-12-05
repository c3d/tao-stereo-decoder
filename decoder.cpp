// ****************************************************************************
//  decoder.cpp                                                     Tao project
// ****************************************************************************
//
//   File Description:
//
//   Basic decoder implementation.
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
//  (C) 1992-2010 Christophe de Dinechin <christophe@taodyne.com>
//  (C) 2010 Jerome Forissier <jerome@taodyne.com>
//  (C) 2010 Taodyne SAS
// ****************************************************************************
#include "decoder.h"

const Tao::ModuleApi *Decoder::tao = NULL;

bool Decoder::tested = false;
bool Decoder::licensed = false;

// ============================================================================
//
//    Decoder
//
// ============================================================================

Decoder::Decoder()
// ----------------------------------------------------------------------------
//   Construction
// ----------------------------------------------------------------------------
{
}

Decoder::~Decoder()
// ----------------------------------------------------------------------------
//   Destruction
// ----------------------------------------------------------------------------
{
}

void Decoder::render_callback(void *arg)
// ----------------------------------------------------------------------------
//   Rendering callback: call the render function for the object
// ----------------------------------------------------------------------------
{
    ((Decoder *)arg)->Draw();
}

void Decoder::delete_callback(void *arg)
// ----------------------------------------------------------------------------
//   Delete callback: destroy object
// ----------------------------------------------------------------------------
{
    delete (Decoder *)arg;
}

void Decoder::Draw()
{
}

