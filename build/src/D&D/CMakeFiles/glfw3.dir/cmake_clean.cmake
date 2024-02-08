file(REMOVE_RECURSE
  "libglfw3.a"
  "libglfw3.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/glfw3.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
