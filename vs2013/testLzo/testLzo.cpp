// testLzo.cpp : Defines the entry point for the console application.
//

#include "cj.h"
using namespace cj;
#include "cjLzo.h"

#pragma comment( lib, "cjLzo.lib" )
#pragma comment( lib, "cjCore.lib" )

int main()
{
	Memory m1, m2, m3;

	String s = "test lzo!";
	m1.write((void*)s.to_string().c_str(), s.getLength());
	m1.setPos(0);

	Lzo lzo;

	lzo.compress(m1, m2);
	lzo.decompress(m2, m3);
	int sz = m3.getSize();

	getchar();

	return 0;
}
