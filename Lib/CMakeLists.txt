include_directories(.)

add_library(PortableWildcards PortableWildcards.cpp PortableWildcards.h)
set_target_properties(PortableWildcards PROPERTIES PUBLIC_HEADER PortableWildcards.h)

install(TARGETS PortableWildcards ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include)

add_subdirectory(Test)
