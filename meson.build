project('getlaid', 'c',
  version : '0.1.0',
  license : 'MIT')

sdl2_dep = dependency('sdl2')
add_project_dependencies(
  sdl2_dep,
  language : 'c')

inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  libraries : getlaid,
  version : '0.1',
  name : 'libgetlaid-sdl',
  filebase : 'getlaid-sdl',
  description : 'A simple layout library for SDL2')
