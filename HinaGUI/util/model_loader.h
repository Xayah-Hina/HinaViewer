#ifndef HINAGUI_MODEL_LOADER_H
#define HINAGUI_MODEL_LOADER_H

#include "../core/renderable.h"

#include <string>

class ModelLoader
{
public:
    static void load_model(const std::string& model_path);
};

#endif //HINAGUI_MODEL_LOADER_H
