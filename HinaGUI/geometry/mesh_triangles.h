#ifndef HINAGUI_MESH_TRIANGLES_H
#define HINAGUI_MESH_TRIANGLES_H

#include "../base/mesh.h"

class IndexedTriangleMesh : public Mesh
{
public:
    int *get_aligned_data() override
    {
        return nullptr;
    }
};


#endif //HINAGUI_MESH_TRIANGLES_H
