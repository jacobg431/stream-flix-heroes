#!/usr/bin/env bash

set -e

ENV_FILE=".env"

echo "=== C++ PostgreSQL Project Environment Setup ==="
echo

# --------------------------------------
# 1. Detect Operating System
# --------------------------------------
OS_NAME="unknown"

case "$(uname -s)" in
  Linux*)
    OS_NAME="linux"
    ;;
  Darwin*)
    OS_NAME="macos"
    ;;
  MINGW*|MSYS*|CYGWIN*)
    OS_NAME="windows"
    ;;
  *)
    echo "Unsupported operating system."
    exit 1
    ;;
esac

echo "Detected OS: ${OS_NAME}"
echo

# --------------------------------------
# 2. Windows-specific MinGW64 Path
# --------------------------------------
MINGW64_PATH=""

if [ "$OS_NAME" = "windows" ]; then
  echo "Please enter the full path to mingw64.exe"
  echo "Example:"
  echo "  C:\\Program Files (x86)\\msys2\\mingw64.exe"
  echo
  read -r -p "MinGW64 path: " MINGW64_PATH

  if [ -z "$MINGW64_PATH" ]; then
    echo "MinGW64 path cannot be empty on Windows."
    exit 1
  fi
fi

# --------------------------------------
# 3. PostgreSQL Configuration
# --------------------------------------
echo
read -r -p "PostgreSQL port [5432]: " POSTGRESQL_PORT
POSTGRESQL_PORT=${POSTGRESQL_PORT:-5432}

read -r -p "PostgreSQL username: " POSTGRESQL_USER
if [ -z "$POSTGRESQL_USER" ]; then
  echo "PostgreSQL username cannot be empty."
  exit 1
fi

read -r -s -p "PostgreSQL password: " POSTGRESQL_PASS
echo
if [ -z "$POSTGRESQL_PASS" ]; then
  echo "PostgreSQL password cannot be empty."
  exit 1
fi

# --------------------------------------
# 4. Write .env File
# --------------------------------------
cat > "$ENV_FILE" <<EOF
# Auto-generated environment file
# Do not commit this file to version control

OS=${OS_NAME}
MinGW64_PATH=${MINGW64_PATH}
POSTGRESQL_PORT=${POSTGRESQL_PORT}
POSTGRESQL_USER=${POSTGRESQL_USER}
POSTGRESQL_PASS=${POSTGRESQL_PASS}
EOF

echo
echo ".env file created successfully."
echo "You may now use it from VS Code tasks, launch configurations, and C++ code."
