#include "cj.h"
#include "cjLzo.h"
#include "minilzo.h"

namespace cj {

Lzo::Lzo() {

}

bool Lzo::compress(Stream &in, Stream &out) {
	Memory m;
	int sz = in.getSize();
	m.setSize(sz);
	in.read(m.data, sz);

	Memory mout;
	mout.setSize(sz + sz / 16 + 64 + 3);
	lzo_uint out_len;
	int r = lzo1x_1_compress((uchar*)m.data, sz, (uchar*)mout.data, &out_len, wrkmem);
	out.write(mout.data, out_len);
	out.setPos(0);
	return r == LZO_E_OK;
}

bool Lzo::decompress(Stream &in, Stream &out) {
	Memory m;
	int sz = in.getSize();
	m.setSize(sz);
	in.read(m.data, sz);

	Memory mout;
	mout.setSize(sz + sz / 16 + 64 + 3);

	lzo_uint new_len;// = in.getSize();

	int r = lzo1x_decompress((uchar*)m.data, sz, (uchar*)mout.data, &new_len, NULL);
	out.write(mout.data, new_len);
	out.setPos(0);
	return r == LZO_E_OK;
}

}