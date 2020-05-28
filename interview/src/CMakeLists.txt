include_directories(./inc)
aux_source_directory(./ Ten)
add_library(tencent SHARED ${Ten})