# LSCAV (Linux Scavanger)

## Description

**LSCAV** is a purpose-built, self-contained tool with little to no dependencies, relying solely on system-provided resources to ensure simplicity and efficiency; designed for developers, system administrators, and advanced users, it offers an easy-to-compile solution for collecting and analyzing critical system information on Linux environments, enabling effective system management, performance monitoring, troubleshooting, and optimization with rapid deployment and minimal setup.

## Features

N/A

## Quick Compilation

```bash
gcc -o lscav lscav.c
```
## Full Compilation

```bash
gcc -std=c99 \
-Wall \
-Wextra \
-Wpedantic \
-Werror \
-O3 \
-fstack-protector-strong \
-D_FORTIFY_SOURCE=3 \
-fPIE \
-pie \
-fvisibility=hidden \
-fno-common \
-fstack-clash-protection \
-D_GNU_SOURCE \
-march=native \
-mtune=native \
-flto \
-fno-strict-aliasing \
-fno-omit-frame-pointer \
-fno-builtin \
-fwrapv \
-fdiagnostics-show-option \
-fno-inline \
-Wl,-z,relro \
-Wl,-z,now \
-Wl,-z,defs \
-Wl,-z,noexecstack \
-D_POSIX_C_SOURCE=200809L \
-D_XOPEN_SOURCE=700 \
-funswitch-loops \
-funroll-loops \
-finline-functions \
-fno-plt \
-pthread \
-fsanitize=address,undefined,leak \
-o lscav \
lscav.c
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
