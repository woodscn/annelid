# Copyright (c) 2009, Maximilian Marx <mmarx@wh2.tu-dresden.de>            
                                                                         
# Permission to use, copy, modify, and/or distribute this software for any 
# purpose with or without fee is hereby granted, provided that the above   
# copyright notice and this permission notice appear in all copies.        
                                                                         
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES 
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF         
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN    
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

cmake_minimum_required (VERSION 2.6)

project (annelid)

include("cmake/Doxygen-helper.cmake")
include("cmake/Fortran-helper.cmake")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(libDL REQUIRED)
include_directories("${libDL_INCLUDE_DIRS}")

add_executable("annelid" "annelid.f90")
add_library("annelid_test_a" SHARED "test/annelid_test_a.f90")
add_executable("loader" "loader.c")
target_link_libraries("loader" ${libDL_LIBRARIES})
