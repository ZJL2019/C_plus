	#pragma once


typedef unsigned char UCH;//255
typedef unsigned short USH;//65535
typedef unsigned long long ULL;



const USH MIN_MATCH =3;//最短长度
const USH MAX_MATCH = 258;//255+3--->length 最长长度
const USH WSIZE = 32 * 1024;//32k 缓冲区大小


const USH HASH_BITS = 15; //哈希地址位数
const USH HASH_SIZE = (1 << 15);//哈希表容量
const USH HASH_MASK = HASH_SIZE - 1;//哈希掩码
