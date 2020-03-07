#pragma once
#include<unordered_map>'
#include<iostream>
#include<string>
using namespace std;


void TestUnordered_map()
{
	unordered_map<string, string> m;
	m.insert(pair<string, string>("蛋糕", "10元"));
	m.insert(pair<string, string>("奶酪", "15元"));
	m.insert(pair<string, string>("面包", "19元"));

	m.insert(make_pair("薯片", "20"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;
	cout << m.bucket_size(0) << endl;

	cout << m.bucket("蛋糕") << endl;//获取key所在的桶号

	m["咖喱"] = "10元";//如果key不存在则将key-val插入到容器中，返回默认val
	cout << m["咖喱"] << endl;
	cout << m.size() << endl;

	m.erase("咖喱");
	cout << m.size() << endl;

	auto it = m.find("蛋糕");
	cout << it->first << "is" << it->second << endl;
}