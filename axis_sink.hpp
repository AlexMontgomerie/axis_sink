#ifndef AXIS_SINK_HPP_
#define AXIS_SINK_HPP_

#include <ap_fixed.h>
#include "hls_stream.h"
#include "hls_math.h"
#include "ap_axi_sdata.h"
#include "stdint.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DMA_WIDTH 64

void sink(
    hls::stream<ap_axis<DMA_WIDTH,1,1,1>> &in,
    int size
);

#endif
