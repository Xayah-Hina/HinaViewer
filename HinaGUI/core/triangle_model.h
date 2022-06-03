#ifndef HINAGUI_TRIANGLE_MODEL_H
#define HINAGUI_TRIANGLE_MODEL_H

#include "../base/particle.h"
#include "../base/mesh.h"
#include "../base/renderable.h"

class TriangleModel : public Renderable
{
public:
    Real *get_vertices_data() override;
    int *get_indices_data() override;

    int get_vertices_size() override;
    int get_indices_size() override;

private:
    ImmutableParticles particles_;
    IndexedTriangleMesh mesh_;
};

#endif //HINAGUI_TRIANGLE_MODEL_H
