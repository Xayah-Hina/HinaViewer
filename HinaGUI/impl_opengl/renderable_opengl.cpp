#include "renderable_opengl.h"

#include "glad/glad.h"

unsigned int RenderableOpenGL::register_to_renderer()
{
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &VAO_);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO_);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size_ * sizeof(Vector3r), particles().get_aligned_particles_data_at(vertices_start_offset_), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh_->size() * mesh_->vertices_per_face() * sizeof(unsigned int), mesh_->get_aligned_indices_data(), GL_STATIC_DRAW);

#ifdef HINA_USE_DOUBLE
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
#else
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
#endif
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return 0;
}
