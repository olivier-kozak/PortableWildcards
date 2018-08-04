cmake_minimum_required(VERSION 3.9)

find_path(PortableWildcards_INCLUDE_DIR PortableWildcards.h)
find_library(PortableWildcards_LIBRARY PortableWildcards)

if(PortableWildcards_INCLUDE_DIR AND PortableWildcards_LIBRARY)
    set(PortableWildcards_FOUND TRUE)
else(PortableWildcards_INCLUDE_DIR AND PortableWildcards_LIBRARY)
    set(PortableWildcards_FOUND FALSE)
endif(PortableWildcards_INCLUDE_DIR AND PortableWildcards_LIBRARY)

if(PortableWildcards_FOUND)
    message("-- Found PotableWildcards: ${PortableWildcards_LIBRARY}")
endif(PortableWildcards_FOUND)
