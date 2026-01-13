# Strean Flix Heroes

Cross-platform C++20 console application demonstrating PostgreSQL integration using libpq and CMake.


## Requirements

- C++20-compatible compiler
- CMake ≥ 4.2
- PostgreSQL (client libraries)
- MSYS MinGW64 (for Windows users)


## Installation

Open your preferred command line program (if on Windows, you should use MSYS MinGW64) and CD into a directory you would like to project to be stored into.

```bash
git clone https://github.com/jacobg431/stream-flix-heroes.git
```


## Build

To allow for local PostgreSQL server connection and let VS Code know your OS, run the setup environment script:

```bash
./setup-environment.sh
```

You will be prompted for PostgreSQL username and password. If you are using Windows, you will be asked to supply the path to your mingw64.exe file as well.

The next step is to actually build the project. You may choose whether to do this in VS Code or to purely use the command line.

### From Visual Studio Code

On Windows and macOS, you must select an appropriate CMake Kit
before configuring the project. Linux users will typically be
auto-configured correctly.

1. Open the stream-flix-heroes folder in VS Code
2. CTRL + SHIFT + P
3. CMake: Select a Kit
4. Choose GCC 15.x.x x86_64-w64-mingw32 (Windows) or Clang 15.x.x arm64-apple-darwin (macOS)
5. CTRL + SHIFT + P
6. CMake: Delete Cache and Reconfigure
7. Ensure compile_commands.json exists in the out/ folder

### From command line

If on Windows, make sure you are using the MinGW64 shell.

```bash
cd "path/to/stream-flix-heroes"
cmake -S . -B out
cmake --build out
```


## Run

From VS Code:
- CTRL + F5

From command line:
```bash
./out/stream-flix-heroes.exe
```