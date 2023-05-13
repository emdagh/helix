#pragma once

#include <ostream>

#ifdef _MSC_VER
#ifdef GST_EXT_EXPORTS
#define GST_EXT_API __declspec(dllexport)
#else
#define GST_EXT_API __declspec(dllimport)
#endif
#else
#define GST_EXT_API
#define GST_EXT_PLUGIN_EXPORT
#endif

#define PLUGIN_DEFAULT_FIELDS                                                                                          \
    int api;                                                                                                           \
    const char* filename;                                                                                              \
    const char* classname;                                                                                             \
    const char* name;                                                                                                  \
    const char* version

#define GST_EXT_PLUGIN(TYPE, NAME, VER)                                        \
  extern "C" {                                                                 \
  GST_EXT_API plugin *get_plugin() {                                           \
    static TYPE t;                                                             \
    return dynamic_cast<plugin *>(&t);                                         \
  }                                                                            \
  GST_EXT_API plugin_info exports = {1000, __FILE__, #TYPE,                    \
                                     NAME, VER,      get_plugin};              \
  }

namespace helix {
    struct plugin
    {
    };

    typedef struct plugin* (*create_plugin_fun)();

    struct plugin_info {
      PLUGIN_DEFAULT_FIELDS;
      create_plugin_fun create;
    };

    inline static std::ostream &operator<<(std::ostream &os,
                                           const plugin_info &info) {
      os << "api=" << info.api << std::endl;
      os << "filename=" << info.filename << std::endl;
      os << "classname=" << info.classname << std::endl;
      os << "name=" << info.name << std::endl;
      return os;
    }
}
