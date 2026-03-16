# micro
Lightweight CLI text file viewer built with C++ around ncurses and only compatible with MacOS/Linux.
This simple tool helps visualize text files quickly without the need of having syntax highlighting, complex editing stuff or any other performance killer features.

Features:
- Blazing fast buffering load
- low ram usage (as low as ~2Mb)
- line count indicator
- title bar with filename

<img width="808" height="647" alt="Screenshot 2026-03-16 at 16 19 33" src="https://github.com/user-attachments/assets/6b9af7cc-eef6-4f09-abb4-cf1c9bcf1ca4" />


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
