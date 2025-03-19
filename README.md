# LSCAV (Linux Scavanger)

## Description

**LSCAV** is a purpose-built, self-contained tool with little to no dependencies, relying solely on system-provided resources to ensure simplicity and efficiency; designed for developers, system administrators, and advanced users, it offers an easy-to-compile solution for collecting and analyzing critical system information on Linux environments, enabling effective system management, performance monitoring, troubleshooting, and optimization with rapid deployment and minimal setup.

## Features

N/A

## Installation

### Prerequisites

Make sure you have the following installed:
- **GCC**: A C compiler (like `gcc`).
- **Make**: The `make` utility to automate the build process.

### Steps for Installation

1. **Clone the repository**:

   If you haven't already, clone the repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/lscav.git
   cd lscav
   ```
2. **Build the project using Makefile**:
   
  The project includes a Makefile to automate the compilation process. To compile the project, simply run:

  ```bash
  make
  ```
  This will build the project and create the executable lscav_debug in the bin directory.
3. 

## Quick Compilation

```bash
gcc -o lscav lscav.c
```


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
