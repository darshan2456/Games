#!/bin/bash

#install build tools and raylib dependencies

sudo apt update

sudo apt install -y make \
    build-essential \
    libasound2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxcursor-dev \
    libxinerama-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev

#builds raylib from source

git clone --depth 1 https://github.com/raysan5/raylib.git

cd raylib/src
make PLATFORM=PLATFORM_DESKTOP

sudo make install
sudo ldconfig
