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

bool                  SplitDecoder::failed = false;
QGLShaderProgram*     SplitDecoder::pgm = NULL;
std::map<text, GLint> SplitDecoder::uniforms;

SplitDecoder::SplitDecoder(int format)
// ----------------------------------------------------------------------------
//   Construction
// ----------------------------------------------------------------------------
    : format(format)
{
    if(!pgm && !failed)
    {
        pgm = new QGLShaderProgram();
        bool ok = false;

        // Basic vertex shader
        static string vSrc =
                "void main()"
                "{"
                "   gl_Position = ftransform();"

                "   /* Compute texture coordinates */"
                "   gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
                "}";

        static string fSrc =
                "/* Filter parameters */"
                "uniform int       eye;"
                "uniform int       format;"
                "uniform float     scale;"
                "uniform sampler2D colorMap;"

                "void main()"
                "{"
                "   if(format == 1)"
                "       gl_TexCoord[0].s = 0.5 * gl_TexCoord[0].s + (eye - 1) * 0.5;"
                "   else if(format == 2)"
                "        gl_TexCoord[0].t = 0.5 * gl_TexCoord[0].t + (eye - 1) * 0.5;"
                "   vec4 color = texture2D( colorMap, gl_TexCoord[0].st );"
                "   gl_FragColor = color;"
                "}";

        if (pgm->addShaderFromSourceCode(QGLShader::Vertex, vSrc.c_str()))
        {
            if (pgm->addShaderFromSourceCode(QGLShader::Fragment, fSrc.c_str()))
            {
                ok = true;
            }
            else
            {
                std::cerr << "Error loading fragment shader code: " << "\n";
                std::cerr << pgm->log().toStdString();
            }
        }
        else
        {
            std::cerr << "Error loading vertex shader code: " << "\n";
            std::cerr << pgm->log().toStdString();
        }
        if (!ok)
        {
            delete pgm;
            pgm = NULL;
            failed = true;
        }
        else
        {
            pgm->link();

            // Save uniform locations
            uint id = pgm->programId();
            uniforms["eye"]  = glGetUniformLocation(id, "eye");
            uniforms["scale"]   = glGetUniformLocation(id, "scale");
            uniforms["format"]   = glGetUniformLocation(id, "format");
            uniforms["colorMap"] = glGetUniformLocation(id, "colorMap");
        }
    }
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

    uint prg_id = 0;
    if(pgm)
        prg_id = pgm->programId();

    if(prg_id)
    {
        tao->SetShader(prg_id);

        int eye = tao->getCurrentEye();
        int eyeMax = tao->getEyesNumber();

        if(eyeMax <= 2)
        {
            // Set texture parameters
            glUniform1i(uniforms["eye"], eye);
            glUniform1f(uniforms["scale"], 0.5);
            glUniform1i(uniforms["format"], format);
            glUniform1i(uniforms["colorMap"], 0);
        }
    }
}

