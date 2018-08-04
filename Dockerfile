FROM ubuntu:18.04

RUN apt-get update && apt-get install -y build-essential cmake libboost-test-dev

COPY CMake/ /opt/PortableWildcards/CMake/
COPY Lib/ /opt/PortableWildcards/Lib/
COPY CMakeLists.txt /opt/PortableWildcards/

WORKDIR /opt/PortableWildcards/
