#ifndef HINAGUI_HINAVIEWER_H
#define HINAGUI_HINAVIEWER_H

#include "util/desc_initable.h"
#include "core/window.h"

namespace HinaGUI
{
    class HinaViewer : public DescInitable
    {
    public:
        struct HinaViewerDesc : public Desc
        {
            std::string name;
            int width, height;
            int pos_x, pos_y;
            Vector4r background_color;
        };

    public:
        void init(const std::string &json_file) override;
        void launch();
        void kill();
        void set_background_color(const Vector4r &color);

    protected:
        void parse(const nlohmann::json &json) override;

    protected:
        Window *window_ = nullptr;
    };
}


#endif //HINAGUI_HINAVIEWER_H
