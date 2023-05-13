#pragma once

namespace helix
{
struct graphics_context
{
    virtual ~graphics_context() = default;
    virtual int make_current() = 0;
    virtual int swap() = 0;
};
} // namespace helix