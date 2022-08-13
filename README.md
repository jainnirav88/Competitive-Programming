# Competitive Programming

* My Competitive Programming (CP) Sublime snippets (templates) and Stress testing template

## CP setup for Intel Macbook

* Install [Homebrew](https://brew.sh/) (Ignore if already installed) using instruction given on the website.

* Install [GCC](https://gcc.gnu.org/) :
  * Install GCC with the help of homebrew using command `brew install gcc`
  * Move to bin folder where g++-x (Eg: g++-11) is present using command `cd /usr/local/bin` (Now you can check g++-x by using command `ls`)
  * Rename  g++-11 to g++ using command `ln -s g++-11 g++` (Now you can check g++ version using command `g++ --version`) (It should show gcc version that we have installed)

* Precompile headers :
  * To precompile **bits/stdc++.h**, move to **bits/** folder. Find the file using command `sudo find /usr -name stdc++.h`
  * To precompile header, use command `g++ -DLOCAL -std=c++17 stdc++.h` (New file **stdc++.h.gch** will be generetad) (Use command `ls` to check it)
  * To precompile **pb_ds/assoc_container.hpp**, move to **pbds** folder. Find the file using command `sudo find /usr -name assoc_container.hpp`
  * To precompile header, use command `g++ -DLOCAL -std=c++17 assoc_container.hpp` (Now file **assoc_container.hpp.gch** will be generated) (Use command `ls` to check it)

* Install [Sublime](https://www.sublimetext.com/) from website

* Sublime setup :
  * Copy and paste [sublime snippets](/snippets) to `Sublime Text/Packages/Users` folder.
  * Install [Origami](https://github.com/SublimeText/Origami) package from package manager of sublime
  * Use already saved origami CP layout from `View->Origami->Window->New->From Saved Layout`
  * Install **PackageResourceViewer** package in sublime from package manager if not already installed
  * Extract origami package in sublime using PackageResourceViewer package.
  * Copy [origami.py](/origami/origami.py) file and paste it into origami.py file of extracted origami.py file and save it.
  * Checkout [/snippets/Default (OSX).sublime-keymap](/snippets/Default%20(OSX).sublime-keymap) to use origami shortcuts

* Now use [C++17 CP Intel MAC](/snippets/c%2B%2B%2017%20CP%20(Intel%20MAC).sublime-build) build to build your c++ program :)
