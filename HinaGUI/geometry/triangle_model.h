#ifndef HINAGUI_TRIANGLE_MODEL_H
#define HINAGUI_TRIANGLE_MODEL_H

#include "../base/renderable.h"
#include "particles_immutable.h"
#include "mesh_triangles.h"

class TriangleModel : public Renderable
{
public: // Static Methods
    static void load_triangle_model(const std::string &model_path);

public: // Renderable Implements
    Real *get_vertices_data() override;
    int *get_indices_data() override;

    int get_vertices_size() override;
    int get_indices_size() override;

private:
    ImmutableParticles particles_;
    IndexedTriangleMesh mesh_;
};

#endif //HINAGUI_TRIANGLE_MODEL_H
