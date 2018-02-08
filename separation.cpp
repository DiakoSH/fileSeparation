#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define ll long long
#define blockSize (1024*1024-1)

int main(int argc, char** argv) {
	ll length;
  char * buffer = new char [blockSize];

	// path of input file
	//cout << "\nargc = " << argc << '\n';
	//for (int i=0; i<argc; i++)
	//	 cout << "file name = " << argv[i] << '\n';
	cout << "file path = " << argv[1] << "\n\n";

	// open input file and get the length
	ifstream inFile(argv[1], std::ifstream::binary);
	if(inFile){
		inFile.seekg(0, inFile.end);
		length = inFile.tellg();
		inFile.seekg(0, inFile.beg);
	}

	// create subFiles
	char fileName[10] = "File";
	double numOfSubFiles = 1.*length/blockSize;
	
	for(int i=0; i<(int)numOfSubFiles; i++){
		// reading
		inFile.read(buffer, blockSize);
		if(inFile.good())
			cout << blockSize << " Bytes read from input file\n";
		else 
			cout << "an error accured while reading from file\n";
		
		// writing
		fileName[4] = i + '0';
		ofstream outFile(fileName, std::ofstream::binary);
		outFile.write(buffer, blockSize) << '\n';
		if(outFile.good())
			cout << "Writting on File" << i << " successfull\n\n";
		else 
			cout << "an error accured on ritting to File" << i << "\n\n";
	}	
	// last subfile
	if(numOfSubFiles != (int)numOfSubFiles){	
		ll lastFileLength = length - ((int)numOfSubFiles)*blockSize;
		
		// reading
		inFile.read(buffer, lastFileLength);
		if(inFile.good())
			cout << lastFileLength << " Bytes read from input file\n";
		else 
			cout << "an error accured while reading from file\n";
		
		// writing
		fileName[4] = (int)numOfSubFiles + '0';
		ofstream outFile(fileName, std::ofstream::binary);
		outFile.write(buffer, lastFileLength) << '\n';
		if(outFile.good())	
			cout << "Writting on File" << (int)numOfSubFiles << " successfull\n\n";
		else 
			cout << "an error accured on ritting to File" << (int)numOfSubFiles << "\n\n";
	}

	// close input file 
	inFile.close();
	if(inFile.good())
		cout << "input file successfully closed\n\n";
	else 
		cout << "an error accured in closing input file\n\n";
	
	delete [] buffer;
	cout << '\n';
	system("pause");
	return 0;
}
