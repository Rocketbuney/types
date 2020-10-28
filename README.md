# types

![CodeQL](https://github.com/Rocketbuney/types/workflows/CodeQL/badge.svg)
![CMake](https://github.com/Rocketbuney/types/workflows/CMake/badge.svg)
<a href="https://gitmoji.carloscuesta.me">
		<img src="https://img.shields.io/badge/gitmoji-%20😜%20😍-FFDD67.svg?style=flat-square"
			 alt="Gitmoji">
</a>


This repo holds common data structures I end up using, for my computer science courses.

## Building
```
git clone https://github.com/Rocketbuney/types.git && cd types
git submodule update --init --recursive
mkdir build && cd build
cmake ../ && make
```

## Usage
To use these data structures, link with the types.a file in the lib directory, and add include/ to the include directory.
