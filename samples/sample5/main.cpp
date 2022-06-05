#include "HinaGUI/HinaViewer.h"

#include <fstream>

struct A
{
    int a; // 4
    float b; // 4
    char c; // 1
};


class Foo
{

};

int main(int argc, char **argv)
{

    HinaGUI::HinaViewer viewer;
//    viewer.init("C:/Users/Administrator/Desktop/BFU_Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
    viewer.init("/Users/xayah/Desktop/BFU-Graphics/HinaGUI/HinaGUI/builtin-desc/classic_viewer.json");
    viewer.launch();
    viewer.kill();

    std::unique_ptr<Foo> a = std::make_unique<Foo>();

    std::vector<int> b; 8

    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);

    std::sqrt()

    Foo * ptr = a.get();

    return 0;
}
