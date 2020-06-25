open_project axis_sink_prj
set_top sink
add_files axis_sink.cpp         -cflags "-std=c++11  -I."
add_files axis_sink_tb.cpp -tb  -cflags "-std=c++11  -I."
open_solution -reset "solution"
set_part "xc7z045ffg900-2" -tool vivado
config_dataflow -default_channel fifo -fifo_depth 2 
create_clock -period 6.6666 -name default
csim_design -mflags "-j 8" 
csynth_design 
#cosim_design -rtl verilog -trace_level all
export_design -rtl verilog -format ip_catalog
exit
