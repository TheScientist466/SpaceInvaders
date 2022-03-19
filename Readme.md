# Space Invaders

## About
A game completely made from scratch using the SFML library. This has no connection to the original classic space invaders game.

this purely for self-teaching purposes so that I can learn new things.

## Build from source

#### On linux

###### Dependencies:
- SFML from official repositories
- Cmake
- clang or g++ compiler

###### Building:
```
mkdir build && cd build
cmake ..
make
./SpaceInvaders
```

#### On Windows
- MinGW32-gcc
- MinGW32-g++
- MinGW32-make
- Cmake

```
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
SpaceInvaders.exe
```