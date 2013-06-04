# ******************************************************************************
#  stereo_decoder.pro                                                Tao project
# ******************************************************************************
# File Description:
# Qt build file for the Decoder module
# ******************************************************************************
# This software is property of Taodyne SAS - Confidential
# Ce logiciel est la propriété de Taodyne SAS - Confidentiel
# (C) 2010 Jerome Forissier <jerome@taodyne.com>
# (C) 2010 Taodyne SAS
# ******************************************************************************

MODINSTDIR = stereo_decoder

include(../modules.pri)

DEFINES     += GLEW_STATIC

INCLUDEPATH += $${TAOTOPSRC}/tao/include/tao/


OTHER_FILES = stereo_decoder.xl stereo_decoder2.xl
CRYPT_XL_SOURCES = stereo_decoder2.xl
include(../crypt_xl.pri)


QT          += core \
               gui \
               opengl

INSTALLS    += thismod_icon
INSTALLS    -= thismod_bin

QMAKE_SUBSTITUTES = doc/Doxyfile.in
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
include(../modules_doc.pri)
