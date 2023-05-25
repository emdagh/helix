#include "application.h"
#include "factory.h"
#include <X11/Xlib.h>

namespace helix
{
class x11_application : public application
{
    Display* _dpy;
    Window _win;

public:
    x11_application()
    {
        _dpy = XOpenDisplay(NULL);
        if (!_dpy)
        {
            // error
        }

        int screenId = DefaultScreen(_dpy);
        _win = XCreateSimpleWindow(_dpy, RootWindow(_dpy, screenId), 0, 0, 640, 480, 1, BlackPixel(_dpy, screenId),
                                   WhitePixel(_dpy, screenId));
        XSelectInput(_dpy, _win, ExposureMask | KeyPressMask);
        XMapWindow(_dpy, _win);
    }

    virtual ~x11_application()
    {
        XCloseDisplay(_dpy);
    }

    virtual int init()
    {
        return -1;
    }
    virtual int deinit()
    {
        return -1;
    }

    virtual int start()
    {
        return -1;
    }

    virtual int pause()
    {
        return -1;
    }

    virtual int stop()
    {
        return -1;
    }
};

// application_factory::instance().
// register_factory<application, x11_application, std::string>("base.application.x11");

static class __reg
{
public:
    __reg()
    {
        register_factory<application, x11_application>(
            "helix.base.x11_application"); //, [] { return static_cast<application*>(new
                                           // x11_application);
    }
} __reg_f;
//});

} // namespace helix