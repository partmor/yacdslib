add_library(yacdslib SHARED
        linked_list.c linked_list.h
        vector.c vector.h)

install(TARGETS yacdslib DESTINATION lib)
install(FILES linked_list.h vector.h DESTINATION include)
