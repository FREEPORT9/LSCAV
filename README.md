# LSCAV: Linux Scavanger

## Description

**LSCAV** is a purpose-built, self-contained tool with little to no dependencies, relying solely on system-provided resources to ensure simplicity and efficiency; designed for developers, system administrators, and advanced users, it offers an easy-to-compile solution for collecting and analyzing critical system information on Linux environments, enabling effective system management, performance monitoring, troubleshooting, and optimization with rapid deployment and minimal setup.

## Features

- **Minimal Dependencies**: Operates with minimal external dependencies.
- **Quick Compilation**: Easy to compile with simple commands.
- **Efficient System Analysis**: Provides critical system data for troubleshooting and performance monitoring.
- **Cross-Platform Compatibility**: Works seamlessly across Linux distributions.
- **Security-Centric**: Adheres to best practices for secure operation.
- **Lightweight and Fast**: Optimized for performance with minimal resource usage.

## Installation

### Prerequisites

Before building the project, ensure that you have the following dependencies installed:

- **GCC**: The GNU Compiler Collection (GCC) to compile the source code.
- **Make**: The build automation tool to run the Makefile.
- **Required Libraries**: Make sure any required libraries for your project are installed in your system. You can modify the Makefile to point to custom include directories and library paths as needed.

### Build Instructions

1. **Clone the repository**:

    ```bash
    git clone https://github.com/nxff/LSCAV.git
    cd LSCAV
    ```

2. **Run the build**:

   The project can be built with three possible configurations: **Base**, **Debug**, and **Release**.

   - **Base Build** (default):
     
     This build is compiled using the base flags with standard optimizations and no debugging features.
     
     ```bash
     make
     ```

   - **Debug Build**:
     
     This build includes debugging flags and additional sanitizers for runtime analysis (e.g., memory and thread sanitizers).
     
     ```bash
     make debug
     ```

   - **Release Build**:
  
     This build optimizes the code for production use, including higher optimization levels and additional security features like stack protection and PIE (Position Independent Executable).
     
     ```bash
     make release
     ```

   The final executables will be placed in the `../bin` directory as follows:
   - `lscav_base` (from the Base Build)
   - `lscav_debug` (from the Debug Build)
   - `lscav_release` (from the Release Build)

3. **Clean Build**:
   
   If you want to remove the compiled object files and binaries, you can run the clean target:
   
   ```bash
   make clean
   ```
   This will delete all object files (*.o) and binary executables in the ../obj and ../bin directories.

5. **Notes**:

    You can modify the Makefile to customize compiler flags or add any additional dependencies required for your system.
   
    Ensure your system supports the necessary compiler options (e.g., -fstack-protector, -flto, etc.) for optimal performance and security.

## Usage

```bash
./lscav

[-u List All Users]
[-g List All Groups]
[-r List Regular Users Only]
[-s List System Information]
```

## License

**LSCAV** is licensed under the **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)** License.

#### You are free to:
- **Share**: Copy, distribute, and transmit the tool, as long as you credit the original author.
- **Adapt**: Remix, transform, and build upon the tool for non-commercial purposes only.

#### The following restrictions apply:
- **Non-Commercial Use**: Commercial use is prohibited. This includes any use intended for commercial advantage or monetary gain.
- **Attribution**: Any use or modification of **LSCAV** must provide appropriate credit to the author, include a link to this license, and clearly indicate if changes were made.

#### For Commercial Use:
If you wish to use **LSCAV** for commercial purposes, please **contact the author** to discuss licensing arrangements and fees. Commercial use is not covered under the current license, but special permissions can be granted.

For more information, visit the [CC BY-NC 4.0 License](https://creativecommons.org/licenses/by-nc/4.0/).

This license ensures that **LSCAV** remains open for personal, educational, and non-commercial use, while safeguarding it from unauthorized commercial exploitation.

## Contact

If you have any questions, suggestions, or would like to discuss licensing for commercial use, feel free to reach out.

**Author:**
Nikola Kipariz Stamov

**Email:**
[**nxa.bakeshop479@passinbox.com**](mailto:nxa.bakeshop479@passinbox.com)

---

Please don't hesitate to get in touch for any inquiries regarding **LSCAV** or related topics. I am happy to assist with technical questions, provide support, or discuss potential collaboration opportunities.
