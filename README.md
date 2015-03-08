Mongo-s2
====

Mongo-s2 is derived from the geospatial library [s2](https://code.google.com/p/s2-geometry-library/) used in [MongoDB](http://www.mongodb.org/). Mongo-s2 can be compiled into dynamic library or [asm.js](http://asmjs.org/) to interoperate with python (e.g. via ctypes) or Javascript.

Compile
----

### Native Dynamic Library

1. Install [SCons](http://www.scons.org/).
2. Run ``scons -j4`` to compile the library into `build` directory with 4 processes.

### Emscripten .js file

1. Install [emscripten](http://kripken.github.io/emscripten-site/index.html).
2. ``source /PATH/TO/EMSDK/emsdk_portable/emsdk_env.sh`` to set the enviroment.
3. ``bash ./compile_em.sh`` to compile ``S2::CellId`` and ``S2::Cell`` related code into ``s2.js``. See ``src/em_wrapper.cc`` for an example of exporting funcitons to Javascript.

