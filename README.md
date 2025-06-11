# supermarket

Supermarket Management Software - University project

## Build and Run Instructions

### Using g++ directly

#### On Linux/macOS:

```bash
# Navigate to the project directory
cd path/to/supermarket

# Make the compile script executable
chmod +x compile.sh

# Run the compilation script
./compile.sh

# Run the program
./bin/supermarket_app
```

#### On Windows:

```cmd
# Navigate to the project directory
cd path\to\supermarket

# Run the compilation script
compile.bat

# Run the program
run.bat

# For debugging (build and launch debugger)
debug.bat

# For Make-based debugging
make-debug.bat
```

### Using the Makefile (Linux/macOS/Windows with MinGW):

```bash
# Navigate to the project directory
cd path/to/supermarket

# Build the project
make

# Run the program
./supermarket_app

# Clean build files
make clean
```

### Running from IDEs

#### Visual Studio Code
1. Open the project folder in VS Code
2. Press `Ctrl+Shift+B` (or `Cmd+Shift+B` on Mac) to build the project
3. Press `F5` to run and debug the application

#### CLion
1. Open the project folder in CLion
2. Choose one of the following run configurations:
   - `Build and Run` - Compiles and runs the application
   - `Build and Debug` - Compiles with debug symbols and starts GDB
   - `Make Debug and Run` - Uses make to build with debug symbols and starts GDB

#### Debugging the Application

For debugging, you have several options:

##### On Linux/macOS:

1. **Using the compile script with debug symbols**:
   ```bash
   ./compile.sh debug
   gdb ./bin/supermarket_app
   ```

2. **Using Make with debug target**:
   ```bash
   make debug
   gdb ./supermarket_app_debug
   ```

##### On Windows:

1. **Using the debug batch file**:
   ```cmd
   debug.bat
   ```

2. **Using Make with debug target**:
   ```cmd
   make-debug.bat
   ```

3. **Manual two-step process**:
   ```cmd
   compile.bat debug
   gdb bin\supermarket_app_debug.exe
   ```

4. **Using your IDE's integrated debugger** with the configurations provided

#### Other IDEs
1. Make sure you have g++ installed and in your PATH
2. Configure your IDE to use the compile.sh/compile.bat script as the build command
3. For debugging, add `-g` to the compiler flags
4. Set the output executable as the run target

### Requirements

- g++ compiler (GCC) with C++11 support
- Make (for Makefile option)
- VS Code Extensions (for VS Code): C/C++ extension, Code Runner (optional)