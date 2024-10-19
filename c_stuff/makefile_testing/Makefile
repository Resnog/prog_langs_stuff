FILE_INC_LIST = something1 something2 something3 something4 something5
FILE_SRC_LIST = stuff1 stuff2 stuff3 stuff4 stuff5 stuff1

OPTION ?=

INC_DIR = inc
SRC_DIR = src
TARGET_DIR = a_target

default: result
	@echo DONE HERE!!! 

.PHONY: check_dirs
check-dirs:
	@mkdir -p $(INC_DIR)
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(TARGET_DIR)

.PHONY: write-h
write-h: check-dirs
	@for file in $(FILE_INC_LIST); do \
		touch -a ${INC_DIR}/$$file.header; \
		echo This is file $$file as a header >> ${INC_DIR}/$$file.header; \
		echo $$file.header written in ${INC_DIR}; \
	done

.PHONY: write-c
write-c: check-dirs
	@for file in $(FILE_SRC_LIST); do \
		touch -a ${SRC_DIR}/$$file.src; \
		echo This is file $$file as src>> ${SRC_DIR}/$$file.src; \
		echo $$file.src written in ${SRC_DIR}; \
	done

.PHONY: write
write: write-h write-c

.PHONY: clean
clean:
	@rm -rf ${INC_DIR}
	@rm -rf ${SRC_DIR}
	@rm -rf ${TARGET_DIR}
	@echo "Project CLEANSED!"

.PHONY: print-list 
print-list:
	@for file in $(FILE_INC_LIST); do \
		echo $$file; \
	done

.PHONY: result
result:
	@for file in $(FILE_SRC_LIST); do \
		cp -f -p ${SRC_DIR}/$$file.src ${TARGET_DIR}/$$file.res; \
		echo Copied $$file.src from ${SRC_DIR}/$$file.src to ${TARGET_DIR}/$$file.res; \
	done
	
	@for file in $(FILE_INC_LIST); do \
		cp -f -p ${INC_DIR}/$$file.header ${TARGET_DIR}/$$file.res; \
		echo Copied $$file.header from ${INC_DIR}/$$file.header to ${TARGET_DIR}/$$file.res; \
	done

