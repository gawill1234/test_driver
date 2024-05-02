SHELL   = /bin/bash
#
CC      =       gcc
#
CFLAGS =  -c
#
#

.c.o:
	$(CC) $(CFLAGS) $<

SRC := \
	build_path.c check_tmp_dir.c clear_dir.c clear_directory.c \
	clear_line_use_track.c copy_directory.c copy_file.c copy_line.c \
	create_nested_directories.c data.c dir_setup.c do_env.c do_my_args.c \
	do_status.c do_test_count.c dohickey.c driver_setup.c dump_line.c \
	env_var_replace.c escape_WS.c file_ops.c file_usage.c files2.c \
	fill_new_file.c find_cmd.c find_end.c find_slot_by_pid.c find_this.c \
	flush_old_tests.c free_slot.c get_date.c get_open_slot.c get_test_line.c \
	kill_it.c kill_my_residuals.c lims.c main.c make_line_use_track.c \
	make_test_dir.c match_mode.c new_dir.c new_test_file_data.c \
	new_test_list_file.c randomize.c read_line.c replace_it.c run_it.c \
	search_dir.c start_time.c streq.c test_set_up.c usage.c use_slot.c \
	waits.c xml_dump.c

OBJ =	build_path.o check_tmp_dir.o clear_dir.o clear_directory.o \
	clear_line_use_track.o copy_directory.o copy_file.o copy_line.o \
	create_nested_directories.o data.o dir_setup.o do_env.o do_my_args.o \
	do_status.o do_test_count.o dohickey.o driver_setup.o dump_line.o \
	env_var_replace.o escape_WS.o file_ops.o file_usage.o files2.o \
	fill_new_file.o find_cmd.o find_end.o find_slot_by_pid.o find_this.o \
	flush_old_tests.o free_slot.o get_date.o get_open_slot.o get_test_line.o \
	kill_it.o kill_my_residuals.o lims.o main.o make_line_use_track.o \
	make_test_dir.o match_mode.o new_dir.o new_test_file_data.o \
	new_test_list_file.o randomize.o read_line.o replace_it.o run_it.o \
	search_dir.o start_time.o streq.o test_set_up.o usage.o use_slot.o \
	waits.o xml_dump.o


linux: 
	for item in $(SRC); do \
		$(CC) -c -D__LINUX__ $${item}; \
	done; \
	$(CC) -o gtd $(OBJ)

mac:
	for item in $(SRC); do \
		$(CC) -D__MACBOOK__ -c $${item}; \
	done; \
	$(CC) -o gtd $(OBJ)


clean:
	rm -f gtd
	rm -f *.o *.obj

build_path.o:	build_path.c
check_tmp_dir.o:	check_tmp_dir.c
clear_dir.o:	clear_dir.c
clear_directory.o:	clear_directory.c
clear_line_use_track.o:	clear_line_use_track.c
copy_directory.o:	copy_directory.c
copy_file.o:	copy_file.c
copy_line.o:	copy_line.c
create_nested_directories.o:	create_nested_directories.c
data.o:	data.c
dir_setup.o:	dir_setup.c
do_env.o:	do_env.c
do_my_args.o:	do_my_args.c
do_status.o:	do_status.c
do_test_count.o:	do_test_count.c
dohickey.o:	dohickey.c
driver_setup.o:	driver_setup.c
dump_line.o:	dump_line.c
env_var_replace.o:	env_var_replace.c
escape_WS.o:	escape_WS.c
file_ops.o:	file_ops.c
file_usage.o:	file_usage.c
files2.o:	files2.c
fill_new_file.o:	fill_new_file.c
find_cmd.o:	find_cmd.c
find_end.o:	find_end.c
find_slot_by_pid.o:	find_slot_by_pid.c
find_this.o:	find_this.c
flush_old_tests.o:	flush_old_tests.c
free_slot.o:	free_slot.c
get_date.o:	get_date.c
get_open_slot.o:	get_open_slot.c
get_test_line.o:	get_test_line.c
kill_it.o:	kill_it.c
kill_my_residuals.o:	kill_my_residuals.c
lims.o:	lims.c
main.o:	main.c
make_line_use_track.o:	make_line_use_track.c
make_test_dir.o:	make_test_dir.c
match_mode.o:	match_mode.c
new_dir.o:	new_dir.c
new_test_file_data.o:	new_test_file_data.c
new_test_list_file.o:	new_test_list_file.c
randomize.o:	randomize.c
read_line.o:	read_line.c
replace_it.o:	replace_it.c
run_it.o:	run_it.c
search_dir.o:	search_dir.c
start_time.o:	start_time.c
streq.o:	streq.c
test_set_up.o:	test_set_up.c
usage.o:	usage.c
use_slot.o:	use_slot.c
waits.o:	waits.c
xml_dump.o:	xml_dump.c
