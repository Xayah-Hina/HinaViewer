#ifndef HINAGUI_DESCINITABLE_H
#define HINAGUI_DESCINITABLE_H

#include "nlohmann/json.hpp"

#include <string>

namespace HinaGUI::Base
{
    class DescInitable
    {
    public:
        struct Desc
        {
            virtual ~Desc() = default;

            template<typename Derived, typename std::enable_if<std::is_base_of<Desc, Derived>::value>::type * = nullptr>
            Derived *as()
            {
                return dynamic_cast<Derived *>(this);
            }
        };

    public:
        void init(const std::string &json_file);

    protected:
        virtual void parse(const nlohmann::json &json);
        Desc *desc_ = nullptr; // DISABLE arbitrary altering from outside
    };
}


#endif //HINAGUI_DESCINITABLE_H
