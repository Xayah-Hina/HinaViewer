#ifndef HINAGUI_RENDERABLE_H
#define HINAGUI_RENDERABLE_H

#include "defines.h"

#include "particles.h"
#include "mesh.h"
#include "texture.h"

class Renderable
{
public: // STATIC
    static Particles &particles()
    { return particles_; };

public:
    virtual unsigned int register_to_renderer() = 0;

public:
    HINA_INLINE void init(unsigned int vertices_start_offset, unsigned int vertices_size, Mesh *mesh, const std::vector<unsigned int> &textures_id)
    {
        vertices_start_offset_ = vertices_start_offset;
        vertices_size_ = vertices_size;
        mesh_ = mesh;
        textures_id_ = textures_id;
    }

    HINA_INLINE void del()
    {
        mesh_->del();
        textures_id_.clear();
    }

protected:
    enum
    {
        FILL = 1 << 0,
        WIREFRAME = 1 << 1,
        DONT_RENDER = 1 << 2
    } RENDERING_MODE = FILL;

    static Particles particles_;
    unsigned int vertices_start_offset_;
    unsigned int vertices_size_;
    Mesh *mesh_;
    std::vector<unsigned int> textures_id_;
};

#endif //HINAGUI_RENDERABLE_H
