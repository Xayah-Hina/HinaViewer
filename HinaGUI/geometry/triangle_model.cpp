#include "triangle_model.h"

void TriangleModel::load_triangle_model(const std::string &model_path)
{

}

Real *TriangleModel::get_vertices_data()
{
    if (particles_ != nullptr)
        return particles_->get_aligned_data();
    else
        return nullptr;
}

int *TriangleModel::get_indices_data()
{
    if (mesh_ != nullptr)
        return mesh_->get_aligned_data();
    else
        return nullptr;
}

int TriangleModel::get_vertices_size()
{
    return 0;
}

int TriangleModel::get_indices_size()
{
    return 0;
}
