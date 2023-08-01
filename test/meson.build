autocont_test = executable(
  'autocontainer-sanity',
  'autocontainer-sanity.c',
  include_directories : inc,
  link_with : getlaid)

trivial_element_test = executable(
  'trivial-element',
  'trivial-element.c',
  include_directories : inc,
  link_with : getlaid)

test('ensure autocontainers use the same layout', autocont_test)
test('basic element test', trivial_element_test)
