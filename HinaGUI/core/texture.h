#ifndef HINAGUI_TEXTURE_H
#define HINAGUI_TEXTURE_H

#include <string>

class Texture
{
public:
    virtual void init(const std::string &texture) = 0;
};

#endif //HINAGUI_TEXTURE_H
