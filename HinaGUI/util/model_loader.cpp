#include "model_loader.h"

#ifndef HINA_USE_ASSIMP

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include <iostream>

Mesh processMesh(aiMesh *mesh, const aiScene *scene)
{
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
    {

    }
    return Mesh();
}

void process_node(aiNode *node, const aiScene *scene)
{
    std::vector<Mesh> meshes;
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
        meshes.push_back(processMesh(scene->mMeshes[node->mMeshes[i]], scene));

    for (unsigned int i = 0; i < node->mNumChildren; i++)
        process_node(node->mChildren[i], scene);
}

void ModelLoader::load_model(const std::string &model_path)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(model_path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
        std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        return;
    }

    std::string directory = model_path.substr(0, model_path.find_last_of('/'));
}

#endif
