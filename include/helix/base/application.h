#pragma once

#include <memory>

namespace helix
{
struct application
{
    virtual ~application() = default;
    virtual int init() = 0;
    virtual int deinit() = 0;
    virtual int start() = 0;
    virtual int pause() = 0;
    virtual int stop() = 0;
};

struct applet;

class application_base : public application
{
    std::unique_ptr<applet> m_applet;

public:
    application_base();
    virtual ~application_base();
};

template <typename, typename> class factory;
typedef factory<application, std::string> application_factory;

} // namespace helix
