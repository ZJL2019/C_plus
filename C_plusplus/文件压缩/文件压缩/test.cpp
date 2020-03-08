#include "LZ77.h"
#include "FileCompress.h"


int main()
{
	LZ77 lz;
	FileCompress fc;
	lz.CompressFile("1.txt");
	fc.CompressFile("2.lzp");
	fc.UnCompressFile("3.lzp");
	lz.UnCompressFile("4.lzp");
	return 0;
}


