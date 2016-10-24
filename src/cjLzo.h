#pragma once

#include "cj.h"
#include "minilzo.h"

namespace cj {

#define HEAP_ALLOC(var,size) \
	lzo_align_t __LZO_MMODEL var[((size)+(sizeof(lzo_align_t)-1)) / sizeof(lzo_align_t)]

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

class Lzo {
public:
	Lzo();
	virtual bool compress(Stream &in, Stream &out);
	virtual bool decompress(Stream &in, Stream &out);
};

}