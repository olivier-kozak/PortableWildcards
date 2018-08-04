#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PortableWildcards

#include <boost/test/unit_test.hpp>

#include <PortableWildcards.h>

BOOST_AUTO_TEST_CASE(matches) {
    BOOST_TEST(PortableWildcards::matches("text", "*"));

    BOOST_TEST(PortableWildcards::matches("text", "text"));
    BOOST_TEST(!PortableWildcards::matches("text", "TEXT"));
    BOOST_TEST(!PortableWildcards::matches("text", "tex"));
    BOOST_TEST(!PortableWildcards::matches("text", "texts"));

    BOOST_TEST(PortableWildcards::matches("text", "t*t"));
    BOOST_TEST(PortableWildcards::matches("text", "*t*t*"));
    BOOST_TEST(!PortableWildcards::matches("text", "T*T"));

    BOOST_TEST(PortableWildcards::matches("text", "t??t"));
    BOOST_TEST(PortableWildcards::matches("text", "*t??t*"));
    BOOST_TEST(!PortableWildcards::matches("text", "T??T"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t???t"));

    BOOST_TEST(PortableWildcards::matches("text", "t?[xy]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[a-z]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[A-Zx]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[a-zX]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[xA-Z]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[Xa-z]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "T?[xy]T"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[XY]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[A-Z]t"));

    BOOST_TEST(PortableWildcards::matches("text", "t?[!XY]t"));
    BOOST_TEST(PortableWildcards::matches("text", "t?[!A-Z]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "T?[!XY]T"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!xy]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!a-z]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!a-zX]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!A-Zx]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!Xa-z]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[!xA-Z]t"));

    BOOST_TEST(PortableWildcards::matches("t??t", "t?[?]t"));
    BOOST_TEST(PortableWildcards::matches("t*t", "t[*]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t[*]t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t?[?]t"));

    BOOST_TEST(PortableWildcards::matches("text", "t*[t]"));
    BOOST_TEST(PortableWildcards::matches("text", "t*[a-z]"));
    BOOST_TEST(!PortableWildcards::matches("text", "t*[t"));
    BOOST_TEST(!PortableWildcards::matches("text", "t*[a-z"));
    BOOST_TEST(!PortableWildcards::matches("text", "t*[a-]"));

    BOOST_TEST(PortableWildcards::matches("File.cpp", "*.cpp"));
    BOOST_TEST(!PortableWildcards::matches("File.cpp", "*.obj"));
}
