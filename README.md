#  <#Title#>

## SDL 
// On linux compile with:
g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl
// On windows compile with (if using mingw)
g++ main.cpp ./glad/src/glad.c -I./glad/include -o prog.exe -lmingw32 -lSDL2main -lSDL2

//Location of SDL headers
sdl2-config --cflags --libs 

g++ -std=c++17 main.cpp -o prog $(sdl2-config --cflags --libs)

clang++ main.cpp -I/Library/Frameworks/SDL2.framework/Headers

clang++ main.cpp ./glad/src/glad.c $(sdl2-config --cflags --libs) -I./glad/include

clang++ main.cpp -o game ./glad/src/glad.c $(sdl2-config --cflags --libs) -I./glad/include -F/Library/Frameworks -framework SDL2

# GLFW
