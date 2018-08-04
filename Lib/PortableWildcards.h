#ifndef PORTABLE_WILDCARDS_H
#define PORTABLE_WILDCARDS_H

#include <string>

namespace PortableWildcards {
    bool matches(const std::string &string, const std::string &pattern);
}

#endif //PORTABLE_WILDCARDS_H
