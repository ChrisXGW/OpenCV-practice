
#include "extractTable.hpp"
#include <stdio.h>
#include <io.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;

void getAllFiles(string path, vector<string>& files);

int main(int argc, char** argv)
{
	Mat src, dst;
	string path = "G:\\change\\to\\your\\directory";
	vector<string> files;
	getAllFiles(path,files);

	for (auto file : files)
	{
		extractTable(file);
	}
	return 0;
}

void getAllFiles(string path, vector<string>& files)
{
	//�ļ����  
	__int64 hFile = 0;
	//�ļ���Ϣ  
	struct __finddata64_t  fileinfo;  //�����õ��ļ���Ϣ��ȡ�ṹ
	string p;  //string�������˼��һ����ֵ����:assign()���кܶ����ذ汾

	
	if ((hFile = _findfirst64(p.assign(path).append("\\*.jpg").c_str(), &fileinfo)) == -1)
	{
		cout << "No file is found\n" << endl;
	}
	else
	{
		do
		{
			files.push_back(p.assign(path).append("\\").append(fileinfo.name));
		} while (_findnext64(hFile, &fileinfo) == 0);  //Ѱ����һ�����ɹ�����0������-1
		_findclose(hFile);
	}
	
}