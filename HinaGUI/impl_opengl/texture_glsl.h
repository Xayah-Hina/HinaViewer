#ifndef HINAGUI_TEXTURE_GLSL_H
#define HINAGUI_TEXTURE_GLSL_H

#include "../core/texture.h"

class GLSLTexture : public Texture
{
public:
    void init(const std::string &texture) override;

protected:
    unsigned int ID_ = 0;
};


#endif //HINAGUI_TEXTURE_GLSL_H
