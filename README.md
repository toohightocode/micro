# micro
Lightweight CLI text file viewer built with C++ around ncurses and only compatible with MacOS/Linux.
This simple tool helps visualize text files quickly without the need of having syntax highlighting, complex editing stuff or any other performance killer features.

Features:
- Blazing fast buffering load
- low ram usage (as low as ~2Mb)
- line count indicator
- title bar with filename

<img width="616" height="513" alt="micro" src="https://github.com/user-attachments/assets/7475f8cd-1b5c-455f-9659-371fa0775b09" />

# Usage
open a file with `micro [filename]` <br>
`q` or `Q` - quit <br>
use directional arrows to move

# Installation
<details>
<summary>MacOS</summary>
Download latest release
</details>

<details>
<summary>Linux</summary>
<ol>
  <li>Download source code</li>
  <li>make sure ncurses library is installed above src folder</li>
  <li>compile with <code>g++ src/main.cpp -lncurses -o micro</code></li>
</ol>
  
</details>
