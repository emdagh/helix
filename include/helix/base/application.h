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

class application_base : public application
{
    struct impl;
    std::unique_ptr<impl> _pimpl;
    // std::unique_ptr<applet> m_applet;

public:
    application_base();
    virtual ~application_base();
    virtual int init();
    virtual int deinit();
    virtual int start();
    virtual int pause();
    virtual int stop();
};

struct applet;

template <typename, typename>
class factory;
typedef factory<application, std::string> application_factory;

template <typename>
struct state;
typedef state<application> application_state;

} // namespace helix
