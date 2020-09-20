include_directories("../inc")
aux_source_directory(./ SRC)
add_library(rank ${SRC})

