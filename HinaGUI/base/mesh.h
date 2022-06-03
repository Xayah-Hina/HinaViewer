#ifndef HINAGUI_MESH_H
#define HINAGUI_MESH_H

class Edge
{

};

class Mesh
{
public:
    virtual HINA_INLINE int *get_aligned_data() = 0;
};

class IndexedTriangleMesh : public Mesh
{
public:
    int *get_aligned_data() override
    {
        return nullptr;
    }
};

#endif //HINAGUI_MESH_H
