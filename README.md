# Push Swap

A high-performance sorting algorithm implementation that efficiently sorts a stack of integers using two stacks and a limited set of operations.

## Overview

Push Swap is a sorting algorithm challenge that optimizes the number of operations required to sort a random list of integers. The program reads unsorted numbers and outputs a series of commands that, when executed on two stacks (stack A and stack B), will leave stack A sorted in ascending order.

This project includes:
- **Mandatory part**: Main sorting algorithm with optimal operation count
- **Bonus part**: Interactive checker to verify if a sequence of commands correctly sorts the input

## Project Structure

```
push_swap/
├── mandatory/           # Main sorting algorithm
│   ├── main.c
│   ├── ft_init_stacks.c
│   ├── ft_init_chunks.c
│   ├── ft_set_arr.c
│   ├── ft_exec_sort.c
│   ├── ft_sort_chunks.c
│   ├── ft_sort_single_chunk.c
│   ├── ft_impera.c
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   ├── reverse_rotate.c
│   ├── ft_utils.c
│   ├── ft_del_cmds.c
│   ├── ft_close.c
│   └── push_swap.h
├── bonus/               # Interactive checker
│   ├── main.c
│   ├── ft_init_stacks.c
│   ├── ft_close.c
│   ├── ft_read_cmds.c
│   ├── ft_execute_cmds.c
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   ├── reverse_rotate.c
│   └── ft_check_sort.c
├── tools/               # Utility tools & libraries
│   ├── Tester_pushswap.sh          # Automated testing script
│   ├── checker_linux                # Pre-built binary checker
│   ├── random_generator.py          # Random number generator
│   ├── libft/                        # Custom C library
│   └── push_swap_visualizer/        # GUI visualization tool
└── Makefile
```

## Stack Operations

The program uses the following operations to sort the stacks:

- **`sa`**: Swap the first two elements at the top of stack A
- **`sb`**: Swap the first two elements at the top of stack B
- **`ss`**: Perform `sa` and `sb` simultaneously
- **`pa`**: Push the first element from stack B to stack A
- **`pb`**: Push the first element from stack A to stack B
- **`ra`**: Rotate stack A upward (first element goes to the end)
- **`rb`**: Rotate stack B upward
- **`rr`**: Perform `ra` and `rb` simultaneously
- **`rra`**: Reverse rotate stack A downward (last element goes to the top)
- **`rrb`**: Reverse rotate stack B downward
- **`rrr`**: Perform `rra` and `rrb` simultaneously

## Building the Project

### Prerequisites
- GCC compiler
- Make
- Standard C library
- Python 3 (for random generator)
- CMake 3.16+ (for visualizer, optional)

### Compilation

**Build the mandatory program:**
```bash
make
```

**Build the bonus checker:**
```bash
make bonus
```

**Clean object files:**
```bash
make clean
```

**Remove all generated files:**
```bash
make fclean
```

**Rebuild everything:**
```bash
make re
```

## Usage

### Mandatory Program

```bash
./push_swap <numbers>
```

**Example:**
```bash
./push_swap 4 67 3 87 23
```

**Output:**
A sequence of operations that sort the numbers in ascending order.

### Bonus Checker

The checker program reads a sequence of operations from stdin and verifies if they correctly sort the input numbers.

```bash
./checker <numbers>
```

Then enter the operations (one per line). Send EOF (Ctrl+D) when done.

**Example:**
```bash
./checker 3 2 1
pb
rb
pa
```

The checker will output:
- `OK` if the operations correctly sort stack A and stack B is empty
- `KO` if the sorting is incorrect

---

## Algorithm Strategy

The implementation uses a **chunking-based sorting algorithm**:

1. **Initialization**: Parse input and distribute numbers into chunks
2. **Chunk Assignment**: Divide the stack into sortable chunks based on value ranges
3. **Progressive Sorting**: Sort each chunk and move elements strategically between stacks
4. **Optimization**: Minimize total operations through intelligent operation selection

This approach achieves efficient sorting for various input sizes while maintaining reasonable operation counts.

## Implementation Details

### Key Functions

- **`ft_init_stacks()`**: Parse command-line arguments and initialize stacks
- **`ft_init_chunks()`**: Determine chunk boundaries and assignments
- **`ft_exec_sort()`**: Execute the main sorting algorithm
- **`ft_sort_chunks()`**: Sort elements within their assigned chunks
- **`ft_impera()`**: Issue and optimize operation commands
- **`ft_check_sort()`** (bonus): Validate if stacks are sorted

### Data Structures

The program uses linked lists to represent stacks, with each node containing:
- Integer value
- Position information
- Chunk assignment
- Navigation pointers

## Language Composition

- **C**: 83.9%
- **C++**: 10.3% (visualizer)
- **Makefile**: 3.2%
- **CMake**: 1.4% (visualizer)
- **Other**: 1.2%

## Technical Specifications

- **Compiler Flags**: `-Wall -Wextra -Werror -g -gdwarf-4 -O3`
- **Standard**: C99 (C++17 for visualizer)
- **Memory Management**: Manual allocation and deallocation with cleanup functions
- **Error Handling**: Comprehensive input validation and error reporting

## Performance Characteristics

- **Time Complexity**: O(n log n) average case for optimal chunk-based sorting
- **Space Complexity**: O(n) for stack storage
- **Operation Efficiency**: Optimized for competitive operation counts

---

## Tools Guide

### 1. **Automated Tester** (`tools/Tester_pushswap.sh`)

An automated bash script that tests your push_swap algorithm with random numbers and automatically validates results with the checker.

#### Binary Paths Used:
- **`./push_swap`** (line 21, 42) - Expects the compiled push_swap binary in the **current directory** (root of the project)
- **`./checker_linux`** (line 42) - Expects the checker binary in the **current directory** (root of the project)
- **`random_generator.py`** (line 12) - Located in the **same directory** as the script (`tools/`)

#### Features:
- Generates random numbers using the Python generator
- Executes push_swap and counts operations
- Validates results against checker
- Color-coded output (green for pass, red for fail)
- Checks operation count against competitive thresholds:
  - **100 numbers**: < 700 operations (green if passed)
  - **500 numbers**: < 5500 operations (green if passed)
  - **Other sizes**: Shows count only

#### How to Use It:

**Step 1: Prepare your project structure**
```bash
# First, compile your project
make          # Creates ./push_swap
make bonus    # Creates ./checker (optional, or use ./checker_linux)
```

**Step 2: Copy checker binary to project root (if needed)**
```bash
# If using the pre-built checker_linux
cp tools/checker_linux ./
```

**Step 3: Run the tester from project root**
```bash
# Interactive mode (prompts for quantity)
./tools/Tester_pushswap.sh

# With direct argument
./tools/Tester_pushswap.sh 100
./tools/Tester_pushswap.sh 500
./tools/Tester_pushswap.sh 50
```

**Step 4: Make sure it's executable**
```bash
chmod +x tools/Tester_pushswap.sh
```

#### Example Execution:
```bash
$ cd /path/to/push_swap  # Project root directory
$ ./tools/Tester_pushswap.sh 100

Numeri generati: 42 17 88 5 91 3 ... (100 numbers)

Comandi: 532          (in green if < 700 operations)

Esito: OK             (in green if successful)
```

#### Common Issues & Fixes:

**Issue**: `./push_swap: No such file or directory`
```bash
# Solution: Make sure you run from project root and compiled it
cd /path/to/push_swap
make
./tools/Tester_pushswap.sh 100
```

**Issue**: `./checker_linux: No such file or directory`
```bash
# Solution: Copy checker_linux to project root
cp tools/checker_linux ./
./tools/Tester_pushswap.sh 100
```

**Issue**: `random_generator.py: No such file or directory`
```bash
# Solution: Make sure you run the tester from project root, not from tools/
cd /path/to/push_swap
./tools/Tester_pushswap.sh  # Correct ✓
cd tools && ./Tester_pushswap.sh  # Wrong ✗
```

---

### 2. **Random Number Generator** (`tools/random_generator.py`)

A Python utility that generates random permutations of numbers from 1 to N without duplicates.

#### Features:
- Generates unique random integers
- Output as space-separated values
- Perfect for testing with various dataset sizes

#### How to Use It:

**Direct usage (standalone):**
```bash
# Generate 10 random numbers
python3 tools/random_generator.py <<< "10"

# Generate 100 random numbers
echo 100 | python3 tools/random_generator.py

# Generate 500 random numbers
echo 500 | python3 tools/random_generator.py
```

**In combination with push_swap:**
```bash
# Test with generated numbers
ARG=$(python3 tools/random_generator.py <<< "50")
./push_swap $ARG | ./checker_linux $ARG
```

**Store in variable for reuse:**
```bash
# Generate numbers once, test multiple times
NUMBERS=$(echo 20 | python3 tools/random_generator.py)
./push_swap $NUMBERS | wc -l  # Count operations
./push_swap $NUMBERS | ./checker_linux $NUMBERS  # Validate
```

#### Example:
```bash
$ echo 5 | python3 tools/random_generator.py
3 1 5 2 4
```

---

### 3. **Pre-built Checker Binary** (`tools/checker_linux`)

A compiled Linux binary of the bonus checker program. Use this if you can't or don't want to compile the bonus part yourself.

#### Requirements:
- Linux system (compiled for Linux x86_64)
- Placed in project root directory or tools directory

#### How to Use It:

**Step 1: Copy to project root**
```bash
cp tools/checker_linux ./
```

**Step 2: Use in testing**
```bash
# Basic usage
./checker_linux 3 2 1

# In a pipeline
./push_swap 3 2 1 | ./checker_linux 3 2 1

# With validation
output=$(./push_swap 5 2 8 3 1 | ./checker_linux 5 2 8 3 1)
if [ "$output" = "OK" ]; then
    echo "✓ Sorting is correct!"
else
    echo "✗ Sorting failed!"
fi
```

**Step 3: Full testing example**
```bash
# Generate random numbers and test
NUMS=$(echo 100 | python3 tools/random_generator.py)
./push_swap $NUMS | ./checker_linux $NUMS
```

#### Example Output:
```bash
$ ./push_swap 5 2 8 3 1 | ./checker_linux 5 2 8 3 1
OK

$ ./push_swap 1 2 3 | ./checker_linux 1 2 3
OK
```

#### Platform Compatibility:
- ✓ Linux (native)
- ✗ macOS (use `make bonus` instead)
- ✗ Windows (use Windows Subsystem for Linux or `make bonus`)

---

### 4. **Push Swap Visualizer** (`tools/push_swap_visualizer/`)

A GUI visualization tool built with C++ and ImGui to visually see your sorting algorithm in action.

#### Key Configuration:

The visualizer looks for your push_swap binary at this path:
```cpp
// From: tools/push_swap_visualizer/src/pushswap.cpp (line 9)
path{"../../push_swap"}  // Relative path from visualizer build directory
```

This means:
- Build directory: `tools/push_swap_visualizer/build/`
- Binary path: `../../push_swap` resolves to **project root** `/push_swap`

#### Requirements:
- CMake 3.16+
- C++ compiler (C++17 or later)
- Graphics libraries (SFML)

#### Building the Visualizer:

```bash
cd tools/push_swap_visualizer
mkdir build
cd build
cmake ..
make
```

#### Running the Visualizer:

**Option 1: From visualizer build directory (automatic path resolution)**
```bash
cd tools/push_swap_visualizer/build
./bin/push_swap_visualizer
```
This works if your `./push_swap` binary is in the project root.

**Option 2: Specify custom path in GUI**
1. Launch the visualizer
2. In the GUI, go to "Values" panel
3. Locate "push_swap file path" input field
4. Enter custom path:
   - Absolute: `/full/path/to/push_swap`
   - Relative: `./push_swap` or `../../push_swap`
5. Click "Compute"

#### How to Use It:

1. **Generate/Input Numbers:**
   - Enter a count in "Count" field
   - Click "Shuffle" to generate random numbers
   - Or manually enter space-separated numbers in "Values" field

2. **Specify Push Swap Path:**
   - Default: `../../push_swap`
   - If your binary is elsewhere, change the path

3. **Execute:**
   - Click "Compute" to run push_swap and load operations
   - Status will show "OK" when loaded

4. **Visualize:**
   - Click "Start" to play animation
   - Adjust "Speed" slider (1-500 operations per second)
   - Use "Pause", "Step", "Step Back" for manual control
   - Use "Reverse" to go backwards through operations
   - "Scale UI" to adjust interface size

#### Example Workflow:
```bash
# Build project
make
make bonus

# Build visualizer
cd tools/push_swap_visualizer
mkdir build && cd build
cmake .. && make

# Run visualizer
./bin/push_swap_visualizer

# In the GUI:
# 1. Enter "50" in Count field
# 2. Click Shuffle
# 3. Click Compute (if ../../push_swap doesn't work, change path to ./push_swap)
# 4. Click Start to see animation
```

#### What You'll See:
- **Left side**: Stack A (being sorted)
- **Right side**: Stack B (temporary storage)
- **Colored bars**: Each number represented as a bar
- **Animation**: Real-time visualization of all operations
- **Command list**: Shows all operations being performed

#### Troubleshooting Visualizer:

**Issue**: `popen() failed!` or binary not found
```
Solution: Verify path in GUI input field
- Check that ./push_swap exists in project root
- Or provide full/correct path to binary
- Try absolute path: /full/path/to/push_swap
```

**Issue**: CMake not found
```bash
sudo apt install cmake  # Ubuntu/Debian
brew install cmake      # macOS
```

**Issue**: Visualizer won't build
```bash
# Ensure dependencies are installed
sudo apt install libsfml-dev libimgui-dev  # Ubuntu/Debian
brew install sfml imgui  # macOS

# Clean and rebuild
cd tools/push_swap_visualizer
rm -rf build
mkdir build && cd build
cmake .. && make
```

---

## Complete Testing Workflow

Here's a comprehensive testing setup using all tools:

```bash
# 1. Navigate to project root
cd /path/to/push_swap

# 2. Build the project
make           # Build push_swap
make bonus     # Build checker (optional)
cp tools/checker_linux ./  # Copy pre-built checker

# 3. Quick test with small numbers
./push_swap 3 2 1 | ./checker_linux 3 2 1

# 4. Test with random generator
ARG=$(python3 tools/random_generator.py <<< "10")
./push_swap $ARG | ./checker_linux $ARG

# 5. Use automated tester
chmod +x tools/Tester_pushswap.sh
./tools/Tester_pushswap.sh 100      # Test 100 numbers
./tools/Tester_pushswap.sh 500      # Test 500 numbers

# 6. Build and use visualizer (optional)
cd tools/push_swap_visualizer
mkdir build && cd build
cmake .. && make
./bin/push_swap_visualizer
# In GUI: Shuffle numbers → Set path to ../../push_swap → Compute → Start
```

---

## Contributing

This is an educational project. Feel free to study the code and understand the algorithm implementation.

## License

Educational project created as part of 42 cursus.

## Author

**abecucci** (abecucci@student.42roma.it)