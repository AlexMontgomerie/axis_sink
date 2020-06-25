#include "axis_sink.hpp"

void sink(
    hls::stream<ap_axis<DMA_WIDTH,1,1,1>> &in,
    int size
)
{
    #pragma HLS INTERFACE axis port=in
    #pragma HLS INTERFACE s_axilite port=return bundle=ctrl  
    #pragma HLS INTERFACE s_axilite port=size bundle=ctrl  
    
    #pragma HLS STREAM variable=in
    
    #pragma HLS DATAFLOW

    for(int i=0;i<size;i++) {
        #pragma HLS PIPELINE II=1
        in.read();
    }
}
