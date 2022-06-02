//#include "HinaGUI/HinaViewer.h"

#define _USE_MATH_DEFINES
#include "OpenMesh/Core/IO/MeshIO.hh"
//#include "OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh"
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>

#include "GL/glut.h"
#include <iostream>

OpenMesh::PolyMesh_ArrayKernelT<> mesh;

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glBegin(GL_TRIANGLES);

    for (OpenMesh::PolyMesh_ArrayKernelT<>::FaceIter f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it)
    {
        for (OpenMesh::PolyMesh_ArrayKernelT<>::FVIter fv_it = mesh.fv_begin(*f_it); fv_it != mesh.fv_end(*f_it); ++fv_it)
        {
            glColor3ubv(mesh.color(*fv_it).data());
            glVertex3fv(mesh.point(*fv_it).data());
        }
    }

    glEnd();
    glPopMatrix();

    glFlush();
}

int main()
{
    mesh.request_vertex_colors();
    OpenMesh::IO::Options opt;
    opt += OpenMesh::IO::Options::VertexColor;
    std::cout << OpenMesh::IO::read_mesh(mesh, "C:/Users/Administrator/Desktop/BFU_Graphics/libigl/cmake-build-release/_deps/libigl_tutorial_tata-src/armadillo.obj", opt) << std::endl;

    int foo = 1;
    char * bar[1] = {" "};
    glutInit(&foo, bar);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    glutCreateWindow("first");

    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    gluPerspective(80, 1, 0.1, 1000);
    gluLookAt(0, 0, 500,	// eye
              0, 0 , 0,			// center
              0, 1, 0);			// Top

    glutDisplayFunc(drawFunc);
    //glutIdleFunc(drawFunc);
    glutMainLoop();

    system("pause");


//    HinaGUI::HinaViewer viewer;
//    viewer.init("C:/Users/Administrator/Desktop/BFU_Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
////    viewer.init("/Users/xayah/Desktop/BFU-Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
//    viewer.launch();
//    viewer.kill();
    return 0;
}
