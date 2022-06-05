#ifndef HINAGUI_RENDERABLE_H
#define HINAGUI_RENDERABLE_H

#include "defines.h"

#include "particles_pool.h"
#include "mesh.h"
#include "texture.h"

class Renderable
{
public: // STATIC
    static ParticlesPool &particles()
    { return particles_; };

public:
    virtual unsigned int load_from_model() = 0;
    virtual unsigned int register_to_renderer() = 0;

public:
    HINA_INLINE void init(unsigned int vertices_size, Mesh *mesh)
    {
        vertices_start_offset_ = particles().size();
        vertices_size_ = vertices_size;
        mesh_ = mesh;
    }

    HINA_INLINE void del()
    {
        mesh_->clear();
        delete mesh_;
    }

protected:
    enum
    {
        FILL = 1 << 0,
        WIREFRAME = 1 << 1,
        DONT_RENDER = 1 << 2
    } RENDERING_MODE = FILL;

    static ParticlesPool particles_;
    unsigned int vertices_start_offset_;
    unsigned int vertices_size_;
    Mesh *mesh_;
};

#endif //HINAGUI_RENDERABLE_H
