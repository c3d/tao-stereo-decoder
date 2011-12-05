#ifndef DECODER_H
#define DECODER_H
// ****************************************************************************
//  decoder.h                                                       Tao project
// ****************************************************************************
//
//   File Description:
//
//      Define a basic decoder.
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

#include "tao/coords3d.h"
#include "tao/module_api.h"
#include "tao/tao_gl.h"
#include <QObject>

using namespace std;
using namespace Tao;

struct Decoder : public QObject
{
    Decoder();
    ~Decoder();

    virtual void    Draw();

    static void     render_callback(void *arg);
    static void     delete_callback(void *arg);

public:
    // Pointer to Tao functions
    static const Tao::ModuleApi *tao;

    static bool tested, licensed;
};


#endif
