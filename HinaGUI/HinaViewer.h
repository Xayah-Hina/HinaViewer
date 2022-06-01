#ifndef HINAGUI_HINAVIEWER_H
#define HINAGUI_HINAVIEWER_H

#include "base/DescInitable.h"

namespace HinaGUI
{
    class HinaViewer : public Base::DescInitable
    {
    public:
        struct HinaViewerDesc : public Desc
        {
            int pos_x, pos_y;
            int width, height;
        };

        void resize(int width, int height);

    protected:
        void parse(const nlohmann::json &json) override;
    };
}


#endif //HINAGUI_HINAVIEWER_H
