# Project StF
# Main point
open a c source file provided by the user, and convert it to a flowchart using both gui and cmd
## GUI
### Menu
- top menu
  - file
    - Open .c
    - save jpg
    - save png
    - ? save md ? - probably the easiest part
    - keybinds
  - view
    - theme
      - load
        - custom
    - reset zoom
    - zoom in
    - zoom out
  - exit
### Viewport
- visualize 
  - colorful (themes, INI filetype)
  - functions: squares
  probably not gonna implement:
    - use doxygen comments for description
    - only for functions
    - only javadoc style
  - structs: to the left side
  - functions point to variables they make and variable point to functions that use them
  - references pont to function and it points back to them
  - if makes branch
  - switch makes multiple branches
  - for, while loops loop back on themselves
  - objects movable by mouse
  - viewport movable my mouse (zoom, pan)
### Theme
 - colors
 - background
 - for:
   - functions
   - structs
   - variables
   - ifs
   - loops
 - for:
   - main viewport:
     - only background
##  CMD
### Options
- -o output fileWithExt
- -t themefile.ini
- -h help
- none open file in gui
- no file, open gui