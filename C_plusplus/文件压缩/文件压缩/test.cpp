#include "LZ77.h"
#include "FileCompress.h"


int main()
{
	LZ77 lz;
	FileCompress fc;
	//fc.CompressFile("1.mp3");
	lz.CompressFile("1.txt");
	fc.CompressFile("2.lzp");
	fc.UnCompressFile("3.lzp");
	lz.UnCompressFile("4.lzp");
	return 0;
}


