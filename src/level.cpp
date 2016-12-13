#include <level.hpp>

using namespace std;

// source : http://stackoverflow.com/questions/236129/split-a-string-in-c
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<string> split(const string &s, char delim) {
    std::vector<string> elems;
    split(s, delim, elems);
    return elems;
}


Level::Level(string imageFile){
    ifstream image(imageFile);	

	string line;
	int i=0, j=0, width=0, height=0;
	vector<string> widthHeight;
	vector<vector<string>> elems;
	vector<string> elemsLine;
	
	while (getline(image,line)){
		if (i==0 && line.compare("P3")) break;
		if (i==2) {
			widthHeight = split(line, ' ');
			width = stoi(widthHeight[0]);
			height = stoi(widthHeight[1]);
		}
		if (i > 3){
			if ( i == j-2) {
				elemsLine.push_back(line);
				i+=3;
				elems.push_back(elemsLine);
			}
			else {
				elemsLine.push_back(line);
			}
		}
		else {i++;}
		j++;
	}
	
	cout << "width = " << width << ", height = " << height << endl;
	cout << "nbCases = " << elemsLine.size() << endl;
	
}

Level::~Level(){
}


