# Halls of Corruption

An RPG/dungeon crawler for C64 with pseudo 3D graphics 
Rewritten in C
Original ASM project from https://github.com/pizza666/HOC/

## Build instructions

### On Windows

1. Get cc65 from https://cc65.github.io/

2. Get MSYS2 https://www.msys2.org/ \
    pacman -S mingw-w64-ucrt-x86_64-gcc\
    pacman -S make

3. Get vice https://vice-emu.sourceforge.io/

4. Add to path environment variable:\
    C:\msys64\usr\bin\
    C:\msys64\ucrt64\bin\
    C:\\{path to cc65}\bin\
    C:\\{path to VICE }\bin

5. Compile with: \
    make

6. Start with:\
    make test

## Keybinds

* W: Walk forward
* S: Walk backwards
* A: Strafe left
* D: Strafe right
* Q: Turn Left
* E: Turn right
* Space: Attack
* R: Draw weapon (only visual yet)
* I: Inventory
* M: Map
* K: Skills
* 6: Roll 1D6 (For debugging)

## Working Features

* Byte-Tile based map loading
* 4x3 FOV with charset based walls
* Basic sprites for weapon and enemy
* Walking and 90° turnin... with sound!

## Planned Features

TBA