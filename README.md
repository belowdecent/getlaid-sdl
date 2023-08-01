# GetLaid
## A layout library for SDL2

This is a library for quickly creating layouts in SDL2 projects.

It is heavily inspired by CSS Flexbox, ActionScript 3 and does not take
away any control over your rendering pipeline.

What GetLaid does is creates a sorted list rects with ids
which gives you positions, sizes and drawing order of elements
from a layout description written in C.

## Building
### Requirements:
- Meson
- SDL2

### Instructions:
To build the project simply use `meson compile`
```
> meson compile -C build
```
Alongside the library, examples will be created which you can freely check out.
