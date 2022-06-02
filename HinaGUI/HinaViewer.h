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
            Eigen::Vector4f background_color;
        };

    public:
        void init(const std::string &json_file) override;
        void launch();
        void kill();
        void resize(int width, int height);
        void set_background_color(const Eigen::Vector4f &color);

    protected:
        void parse(const nlohmann::json &json) override;

    protected:
        Core::Window *window_ = nullptr;
    };
}


#endif //HINAGUI_HINAVIEWER_H
