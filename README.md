# C++ tasks solutions

Repository with tasks: [link](https://github.com/i-s-m-mipt/Education/tree/master)

# Build

### Build requirements 

To build this examples the CMake and CLang/GCC are needed.

### Build steps

1. Go to one of the examples dir:
```
cd 02_02
```
2. Configure the example:
```
cmake -S . -B build
```
3. Build the example:
```
cmake --build build
```
4. Build artifacts are in `build` folder. `compile_commands.json` is also generated.

### Build all

# Tests