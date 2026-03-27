#!/bin/bash

x86_64-w64-mingw32-gcc main.c -o game.exe   -I$HOME/raylib/src   -L$HOME/raylib/src   -lraylib -lopengl32 -lgdi32 -lwinmm
gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
source /home/kevin/emsdk/emsdk_env.sh
emcc main.c -o index.html -I$HOME/emsdk/raylib/src $HOME/emsdk/raylib/src/libraylib.web.a -s WASM=1 -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 -s FULL_ES2=1 -s ASYNCIFY --preload-file assets
zip -r game_win.zip game.exe assets/
zip -r game_linux.zip game assets/

