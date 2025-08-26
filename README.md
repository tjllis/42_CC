# 42 Core Curriculum Projects

A collection of projects from the 42 School curriculum, showcasing various programming concepts and algorithms implemented in C.

## 🚀 Projects Overview

## 🛠️ [Common Library (LIBFT) - includes FT_PRINTF & GET_NEXT_LINE](LIBFT_GNL_PRINTF/)

All projects include a comprehensive C library with custom implementations of:

- **String Functions**: `ft_strlen`, `ft_strcpy`, `ft_strcat`, `ft_strcmp`, etc.
- **Memory Functions**: `ft_malloc`, `ft_free`, `ft_memcpy`, `ft_memset`, etc.
- **List Functions**: `ft_lstnew`, `ft_lstadd_back`, `ft_lstclear`, etc.
- **Utility Functions**: `ft_atoi`, `ft_itoa`, `ft_split`, etc.

### Major Implementations

- **`ft_printf`** - Complete printf implementation with all standard specifiers
- **`get_next_line`** - Memory-safe line reading without memory leaks
- **`ft_atoi_base`** - Convert string to integer with custom base
- **`ft_atoi_safe`** - Safe integer conversion with error checking

### [PUSH_SWAP](PUSH_SWAP/) - Stack Sorting Algorithm

An efficient stack-based sorting algorithm with minimal operations:

- **Multiple Algorithms**: Radix sort, small sort optimization
- **Operation Counting**: Minimal moves to sort any stack
- **Input Validation**: Robust parsing of various input formats
- **Memory Efficient**: Optimized data structures

**Key Features:**

- Handles both single string and multiple argument inputs
- Normalizes values for efficient sorting
- Specialized algorithms for small stacks (≤5 elements)
- Radix sort for larger stacks with O(n log n) complexity

### [MINITALK](MINITALK/) - Client-Server Communication

A signal-based communication system using Unix signals:

- **Signal Handling**: Custom signal processing for data transmission
- **Binary Protocol**: Efficient bit-by-bit data transfer
- **Bidirectional**: Client-server communication using SIGUSR1/SIGUSR2
- **Real-time**: Instant message transmission

**Key Features:**

- Uses SIGUSR1 and SIGUSR2 for binary communication
- Efficient bit manipulation for data encoding
- Robust error handling and validation
- Cross-platform signal compatibility

### [FDF](FDF/) - Wireframe Viewer

A 3D wireframe viewer that renders topographic maps from height data files. Features include:

- **3D Visualization**: Isometric projection of height maps
- **Interactive Controls**: Zoom, rotation, translation, and scaling
- **Color Support**: Custom color schemes and height-based coloring
- **Cross-platform**: Works on both Linux and macOS
- **Real-time Rendering**: Smooth wireframe drawing with OpenGL

**Key Features:**

- Parse `.fdf` files containing height data
- Interactive keyboard controls for navigation
- Smooth wireframe rendering with Bresenham's line algorithm
- Memory-efficient parsing and rendering

### [PHILOSOPHERS](PHILOSOPHERS/) - Dining Philosophers Problem

A solution to the classic synchronization problem using threads and mutexes:

- **Thread Management**: Efficient philosopher lifecycle management
- **Resource Synchronization**: Fork sharing with mutex protection
- **Performance Monitoring**: Meal counting and timing
- **Deadlock Prevention**: Smart resource allocation strategy

**Key Features:**

- Configurable number of philosophers and timing parameters
- Efficient mutex-based synchronization
- Comprehensive error handling and cleanup
- Performance optimization for large numbers of philosophers

## 📋 Requirements

- **Compiler**: GCC/Clang with C99 support
- **OS**: Linux (Ubuntu/Debian) or macOS
- **Libraries**:
  - Linux: X11, Xext, OpenGL
  - macOS: X11, OpenGL, AppKit
- **Build Tools**: Make

## 🔧 Compilation

### Quick Start

```bash
# Clone the repository
git clone <your-repo-url>
cd 42_Core

# Build all projects
make -C FDF
make -C PHILOSOPHERS
make -C PUSH_SWAP
make -C MINITALK
```

### Individual Project Builds

#### FDF

```bash
cd FDF
make
./fdf [map_file.fdf]
```

#### PHILOSOPHERS

```bash
cd PHILOSOPHERS
make
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

#### PUSH_SWAP

```bash
cd PUSH_SWAP
make
./push_swap [numbers...]
# or
./push_swap "1 2 3 4 5"
```

#### MINITALK

```bash
cd MINITALK
make
# Terminal 1: Start server
./server
# Terminal 2: Send message from client
./client [server_pid] [message]
```

## 🎮 Usage Examples

### FDF - Viewing a Map

```bash
cd FDF
make
./fdf maps/42.fdf
```

**Controls:**

- `WASD` - Move view
- `Q/E` - Rotate Z-axis
- `R/F` - Rotate X-axis
- `T/G` - Rotate Y-axis
- `+/-` - Zoom in/out
- `C` - Reset view
- `ESC` - Exit

### PHILOSOPHERS - Simulation

```bash
cd PHILOSOPHERS
make
./philo 5 800 200 200 7
```

This runs a simulation with:

- 5 philosophers
- 800ms time to die
- 200ms to eat
- 200ms to sleep
- Each must eat 7 times

### PUSH_SWAP - Sorting

```bash
cd PUSH_SWAP
make
./push_swap "3 1 4 2 5"
# Output: sa ra sa ra sa
```

### MINITALK - Communication

```bash
cd MINITALK
make
# Terminal 1
./server
# Output: PID: 12345

# Terminal 2
./client 12345 "Hello, World!"
```

## 🧹 Cleanup

```bash
# Clean object files
make clean

# Full cleanup (objects + executables)
make fclean

# Rebuild everything
make re
```

## 📁 Project Structure

```
42_Core/
├── FDF/                 # 3D Wireframe Viewer
├── PHILOSOPHERS/        # Dining Philosophers Problem
├── PUSH_SWAP/          # Stack Sorting Algorithm
├── MINITALK/           # Signal-based Communication
└── LIBFT_GNL_PRINTF/   # Common Library Functions
```

## 🐛 Troubleshooting

### Common Issues

1. **FDF won't compile on macOS**

   - Install X11: `brew install xquartz`
   - Ensure X11 is running before launching

2. **Permission denied errors**

   - Check file permissions: `chmod +x [executable]`
   - Ensure proper ownership

3. **Library not found errors**
   - Install required packages:
     - Ubuntu: `sudo apt-get install libx11-dev libxext-dev`
     - macOS: `brew install xquartz`

## 📚 Learning Resources

- **42 School Documentation**: [42.fr](https://42.fr)
- **C Programming**: [GNU C Library](https://www.gnu.org/software/libc/)
- **OpenGL**: [OpenGL Documentation](https://www.opengl.org/documentation/)

## 🤝 Contributing

This repository contains educational projects. Feel free to:

- Report bugs or issues
- Suggest improvements
- Share your own implementations
- Ask questions about the algorithms

## 📄 License

These projects are part of the 42 School curriculum. Please respect the academic integrity policies of your institution.

---

**Happy Coding! 🚀**
