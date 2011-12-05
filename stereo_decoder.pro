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
HEADERS = stereo_decoder.h \
          decoder.h \
          split_decoder.h \

SOURCES = decoder.cpp $${TAOTOPSRC}/tao/include/tao/GL/glew.c \
          split_decoder.cpp \
          stereo_decoder.cpp

TBL_SOURCES  = stereo_decoder.tbl

OTHER_FILES = decoder.xl decoder.tbl traces.tbl
QT          += core \
               gui \
               opengl

INSTALLS    += thismod_icon

LICENSE_FILES = stereo_decoder.taokey.notsigned
include(../licenses.pri)

