## Installing C Compiler on Windows

Credits goes to [LearningLad]([LearningLad - YouTube](https://www.youtube.com/channel/UCvxAt_WebjZ_-pMsxpraROg)) who created a [video tutorial]([How to Download and Install C Cpp Toolset ( gcc g++ gdb ) in Windows 10 using mingw-w64 and msys2 - YouTube](https://youtu.be/0HD0pqVtsmw)) for this on YouTube.

The written document that I wrote here is for my future reference, contents are based on the video that LearningLad created.

1. Download and Install `msys2`
   - Download the installer from `msys2` [website](https://www.msys2.org/).
   
   - Install `msys2` with the installer.
   
   - Run `msys2` when the installer finishes.
   
   - Update the package database with the command:
     `$ pacman -Syu`

2. Install `gcc` and `gdb`
   - Click the Windows button, find the `MSYS2 64bit` folder, inside it run the `MSYS2 MinGW 64-bit`.
   
   - In the `MinGW` terminal, run the following command to install `gcc`:
     `$ pacman -Ss mingw64/mingw-w64-x86_64-gcc`
   
   - In the `MinGW` terminal, run the following command to install `gdb`:
     `$ pacman -Ss mingw64/mingw-w64-x86_64-gdb`
   
   - Check installation with:
     `$ gcc --version`, `$ g++ --version`, `$ gdb --version`
3. Setup Environement Variables on Windows
   - Copy the path of `mingw64` folder, this will be something like this:
     `C:\msys64\mingw64\bin`
   
   - Click windows button and search with following keyword '*Edit the system environment variables*'.
   
   - In the Advanced tab, click the 'Environment Variables' button.
   
   - In the 'Sytem Variables' section, click the 'Path' row, and click 'Edit'.
   
   - Add the path we copied before.
   
   - Now, `gcc`, `g++ `, and `gdb` should be able to run from the command prompt.
4. 












