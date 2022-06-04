#ifndef HINAGUI_MESH_H
#define HINAGUI_MESH_H

#include "defines.h"

class Edge
{

};

class Mesh
{
public:
    virtual HINA_INLINE int *get_aligned_data() = 0;
};

#endif //HINAGUI_MESH_H
