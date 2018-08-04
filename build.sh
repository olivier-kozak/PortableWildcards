#!/usr/bin/env bash

docker build -t portable-wildcards . && docker run portable-wildcards bash -c "cmake . && make && make test"
