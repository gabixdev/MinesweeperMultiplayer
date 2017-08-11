# Function for preparing include list
function(prepare_include variable)
    set(${variable} "" CACHE INTERNAL "Include list")
endfunction()

# Function for creating include list
function(append_include variable fileList)
    foreach (file ${fileList})
        include_directories(${file})
        get_filename_component(absfile ${file} ABSOLUTE)
        set(${variable} "${${variable}};${absfile}" CACHE INTERNAL "")
    endforeach ()
endfunction()

function(append_include_simple variable fileList)
    foreach (file ${fileList})
        set(${variable} "${${variable}};${file}" CACHE INTERNAL "")
    endforeach ()
endfunction()