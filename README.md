# PortableWildcards #

*PortableWildcards* is a small C++ library that provides ability to test
strings against expressions using Unix shell-style wildcards.

Here are the supported wildcards:
* `*` matches everything,
* `?` matches any single character,
* `[seq]` matches any character in *seq*,
* `[!seq]` matches any character not in *seq*.

*PortableWildcards* is licensed under the MIT License.

## Requirements ##

* A C++11 compliant compiler,
* CMake >= 3.9,
* Boost.Test >= 1.62.

## Getting started ##

* First, build and install the package:
    ```
    cmake . && make && sudo make install
    ```

* Then, in your project's `CMakeLists.txt` file:

    * Mark the package as required:
        ```
        find_package(PortableWildcards REQUIRED)
        ```

    * Declare the required include directory and library:
        ```
        target_include_directories(MyProgram PRIVATE ${PortableWildcards_INCLUDE_DIR})
        target_link_libraries(MyProgram ${PortableWildcards_LIBRARY})
        ```

* You can now use the library as follows:
    ```
    #include <iostream>

    #include <PortableWildcards.h>

    int main() {
        std::cout << PortableWildcards::matches("File.cpp", "*.cpp") << std::endl; //true
        std::cout << PortableWildcards::matches("File.cpp", "*.obj") << std::endl; //false
        ...

        return 0;
    }
    ```
