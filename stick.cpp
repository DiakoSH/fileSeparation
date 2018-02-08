#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define ll long long
#define blockSize (1024*1024-1)

int main(int argc, char** argv) {
	ll length;
	char *buffer = new char[blockSize];

	ofstream outFile("originalFile", std::ofstream::binary);
	//if (outFile)
	for(int i=1; i<argc; i++){
		
		// openning from i'th input file 
		ifstream inFile(argv[i], std::ifstream::binary);
		if(inFile)
			cout << "File" << i-1 << " successfully opened\n";
		else {
			cout << "an error accured while openning File" << i-1 << "\n";
			// exception statements 
		}
        
    
		// length of file 
		inFile.seekg(0, inFile.end);
		length = inFile.tellg();
		inFile.seekg(0, inFile.beg);
		
		// reading from i'th input file 
		inFile.read(buffer, length);
		if(inFile.good())
			cout << "read "<< length << " bytes from File" << i-1 << " successfull\n";
		else{
			cout << "an error accured from reading from File" << i-1 << "\n";
			// exception statements 
		}
		
		// create output file and wirte data 
		outFile.write(buffer, length);
		outFile.flush();
		if(outFile.good())
			cout << "Writting on File" << i-1 << " successfull\n\n";
		else 
			cout << "an error accured on writting to File" << i-1 << "\n\n";
	}
	
	
	delete[] buffer;
	cout << '\n';
	system("pause");	
	return 0;
}
