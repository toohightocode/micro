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
use directional arrows to move, or scroll if terminal supports it

# Installation
<details>
<summary>MacOS</summary>
Download latest release
</details>

<details>
<summary>Linux</summary>
<ol>
  <li>Download the repository</li>
  <li>download and compile the latest ncurses library version</li>
  <li>run `make`</li>
  <li>The compiled build can be found in `/build`</code></li>
</ol>
  
</details>
