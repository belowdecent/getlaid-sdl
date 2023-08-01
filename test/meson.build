getlaid_test = executable(
  'getlaid-test',
  'getlaid-test.c',
  include_directories : inc,
  link_with : getlaid)

test('ensure autocontainers use the same layout', getlaid_test)
