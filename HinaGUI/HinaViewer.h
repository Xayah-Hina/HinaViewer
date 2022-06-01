#ifndef HINAGUI_HINAVIEWER_H
#define HINAGUI_HINAVIEWER_H

#include "base/desc_initable.h"
#include "core/window.h"

namespace HinaGUI
{
    class HinaViewer : public Base::DescInitable
    {
    public:
        struct HinaViewerDesc : public Desc
        {
            std::string name;
            int width, height;
            int pos_x, pos_y;
        };

    public:
        void init(const std::string &json_file) override;
        void launch();
        void kill();
        void resize(int width, int height);

    protected:
        void parse(const nlohmann::json &json) override;

    protected:
        Window *window_ = nullptr;
    };
}


#endif //HINAGUI_HINAVIEWER_H
