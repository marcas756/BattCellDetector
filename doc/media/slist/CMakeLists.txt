# set the list of documents to process
set(DOCS 	slist_back
		slist_erase
		slist_init
		slist_insert_after
		slist_insert_before
		slist_node_t
		slist_pop_back
		slist_pop_front
		slist_push_back
		slist_push_front
		slist_t
)


find_program(DIA_EXECUTABLE dia REQUIRED)


 dia -e test.svg -t svg dlist_back.dia

# add the custom commands for each document
foreach(DOC ${DOCS})
  add_custom_command(
    OUTPUT  ${PROJECT_BINARY_DIR}/${DOC}.pdf
    DEPENDS ${PROJECT_SOURCE_DIR}/${DOC}.dia
    COMMAND ${LATEX} ${PROJECT_SOURCE_DIR}/${DOC}.dia
    COMMAND ${DVIPDF} ${PROJECT_BINARY_DIR}/${DOC}.dvi
    )

  # build a list of all the results
  list(APPEND DOC_RESULTS ${PROJECT_BINARY_DIR}/${DOC}.pdf)
endforeach()

# finally add the custom target that when invoked
# will cause the generation of the pdf file
add_custom_target(slistimgs ALL
  DEPENDS ${DOC_RESULTS}
  )
  

  
  
 
