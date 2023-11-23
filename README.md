# igraph.js

igraph.js is an JavaScript interface of the igraph network analysis library compiled to WebAssembly using Emscripten.

## Build

You can build project using `emcmake` from `emsdk`:
```bash
> mkdir build && cd build
> emcmake cmake ..
> make
> make test # Makes and runs tests using node.js
```
