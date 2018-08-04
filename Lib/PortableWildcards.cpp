#include <PortableWildcards.h>

#include <vector>
#include <utility>

namespace {
    class Sequence {
    public:
        explicit Sequence(std::string &pattern) {
            std::vector<std::pair<std::string::value_type, std::string::value_type>> *chars;

            if (!pattern.empty() && (pattern[0] == '!')) {
                pattern = pattern.substr(1);

                chars = &excludes;
            } else {
                chars = &includes;
            }

            if (!pattern.empty()) {
                do {
                    if ((pattern.size() >= 3) && (pattern[1] == '-')) {
                        chars->emplace_back(pattern[0], pattern[2]);
                        pattern = pattern.substr(3);
                    } else {
                        chars->emplace_back(pattern[0], pattern[0]);
                        pattern = pattern.substr(1);
                    }

                } while (!pattern.empty() && (pattern[0] != ']'));
            }

            if (!pattern.empty() && (pattern[0] == ']')) {
                pattern = pattern.substr(1);
            } else {
                chars->clear();
            }
        }

        bool matches(std::string::value_type char_) {
            if (!includes.empty()) {
                for (auto includesRange : includes) {
                    if (includesRange.first <= char_ && char_ <= includesRange.second) {
                        return true;
                    }
                }
                return false;
            }

            if (!excludes.empty()) {
                for (auto excludesRange : excludes) {
                    if (excludesRange.first <= char_ && char_ <= excludesRange.second) {
                        return false;
                    }
                }
                return true;
            }

            return false;
        }

    private:
        std::vector<std::pair<std::string::value_type, std::string::value_type>> includes, excludes;
    };
}

namespace PortableWildcards {
    bool matches(const std::string &string, const std::string &pattern) {
        if (string.empty() && pattern.empty()) {
            return true;
        }

        if (pattern.empty()) {
            return false;
        }

        switch (pattern[0]) {
            case '?':
                if (string.empty()) {
                    return false;
                }

                return matches(string.substr(1), pattern.substr(1));

            case '*':
                if (string.empty()) {
                    return true;
                }

                for (std::size_t i = 0; i <= string.size(); i++) {
                    if (matches(string.substr(i), pattern.substr(1))) {
                        return true;
                    }
                }
                return false;

            case '[':
                if (string.empty()) {
                    return false;
                }

                auto nextPattern = pattern.substr(1);
                Sequence sequence(nextPattern);

                return sequence.matches(string[0]) && matches(string.substr(1), nextPattern);
        }

        if (string.empty()) {
            return false;
        }

        return (string[0] == pattern[0]) && matches(string.substr(1), pattern.substr(1));
    }
}
