# Project S-t-F
# Main point
open a c source file provided by the user, and convert it to a flowchart
## GUI
### Menu
- Open file (both .h and .c at the same time)
- save img
- ? save md ?
- theme
- top menu
### Viewport
- visualize 
  - colorful (themes, INI filetype)
  - functions: squares
    - use doxygen comments for description
    - only for functions
    - only javadoc style
  - structs: to the left side
  - functions point to variables they make and variable point to functions that use them
  - no threading
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
- -o output fileWithoutExt
- -t output [type] (jpg, png ,?md?)
- -h help
- - themefile.ini
- none open file in gui
- no file, open gui