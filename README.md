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

If on Windows, make sure you are using the MinGW64 shell.

```bash
cd "path/to/stream-flix-heroes"
cmake -S . -B out
cmake --build out
```


## Run

From command line:
```bash
./out/stream-flix-heroes.exe
```