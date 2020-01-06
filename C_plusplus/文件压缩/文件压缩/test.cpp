#include "FileCompress.h"


int main()
{
	FileCompress fc;
	fc.CompressFile("1.txt");
	fc.UnCompressFile("2.txt");
	return 0;
}
