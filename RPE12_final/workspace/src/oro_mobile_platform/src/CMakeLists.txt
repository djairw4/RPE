
#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library liboro_mobile_platform-<target>.so
# and installs in the directory lib/orocos/oro_mobile_platform/
#
orocos_component(generator generator.hpp generator.cpp) # ...you may add multiple source files
orocos_component(data_logger data_logger.hpp data_logger.cpp)
#
# You may add multiple orocos_component statements.



#
# Additional headers:
#
# Installs in the include/orocos/oro_mobile_platform/ directory
#
orocos_install_headers(generator.hpp data_logger.hpp) # ...you may add multiple header files
#
# You may add multiple orocos_install_headers statements.

