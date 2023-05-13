#include "application.h"
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
};
} // namespace helix