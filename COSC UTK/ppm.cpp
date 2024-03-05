/* Program Name: PPM Manipulation
 * Student Name: Ariel Thompson
 * Net ID: athom211
 * Student ID: 000-66-6497
 * Program Description: The PPM Manipulation Program takes a ppm file (from file input and standard input) and prints 
 * out a new image to an output files through a set of commands.*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Pixel {

	int r, g, b;
};

class Picture {

	private:
	vector<Pixel> pixels;
	int pictureWidth;
	int pictureHeight;
	int maxIntensity;

	public:
	Picture();
	const Pixel& get_pixel(int row, int col) const;
	Pixel& get_pixel(int row, int col);
	void set_pixel(int row, int col, const Pixel& pix);
	void invert();
	void flip_x();
	void flip_y();
	bool read_input(istream& ssref);
	void write_output(ostream& osref);

};

// sets all values of image to 0
Picture::Picture(){

	pictureWidth = 0;
	pictureHeight = 0;
	maxIntensity = 0;
}

// obtains a pixel by row/column and returns a const reference (not mutable)
const Pixel& Picture::get_pixel(int row, int col) const{

	int selectedRow = pictureWidth * row;
	const Pixel& p = pixels[selectedRow + col];
	return p;
}

// obtains a pixel by row/column and returns a mutable reference
Pixel& Picture::get_pixel(int row, int col){

	int selectedRow = pictureWidth * row;
	Pixel& p = pixels[selectedRow + col];
	return p;
}

// sets const reference pixels
void Picture::set_pixel(int row, int col, const Pixel& pix){

	
	get_pixel(row, col) = pix;
}

// inverts colors of ppm files by substracting rgb color from max intensity
void Picture::invert(){

	for (size_t i = 0; i < pixels.size(); i++){

		pixels[i].r = maxIntensity - pixels[i].r;
		pixels[i].b = maxIntensity - pixels[i].b;
		pixels[i].g = maxIntensity - pixels[i].g;
	}

}

// flips ppm image across x-axis
void Picture::flip_x(){

	for (int i = 0; i < pictureHeight; i++){
		
		int lastRow;
		lastRow = (pictureHeight - i) - 1;

		if (i >= lastRow){
			
			break;
		}

		for (int j = 0; j < pictureWidth; j++){
			
			Pixel top, bottom;
			top = get_pixel(i, j);
			bottom = get_pixel(lastRow, j);
			set_pixel(i, j, bottom);
			set_pixel(lastRow, j, top);
		}
	}
}

// flips ppm image across y-axis
void Picture::flip_y(){

	for (int i = 0; i < pictureWidth; i++){
		
		int lastColumn;
		lastColumn = (pictureWidth - i) - 1;

		if (i >= lastColumn){
			
			break;
		}

		for (int j = 0; j < pictureHeight; j++){
			
			Pixel left, right;
			left = get_pixel(j, i);
			right = get_pixel(j, lastColumn);
			set_pixel(j, i, left);
			set_pixel(j, lastColumn, right);
		}
	}
}

// reads in information (h, w, maxI, rgb pixels) and stores it in program
bool Picture::read_input(istream& ssref){

	stringstream sin;
	string line;
	int currentLineCount = 0;
	Pixel pix;

	// reading in each line from the file
	while (getline(ssref, line)){

		// skips comments in the file
		if (line[0] == '#'){

			continue;

		}

		// checks for "P3"
		if (currentLineCount == 0){

			if (line == "P3"){

				currentLineCount++;
				continue;

			} else {

				return false;
			}
		}

		// reads in width and height from the file - resizes array
		if (currentLineCount == 1){

			sin.clear();
			sin << line;
			sin >> pictureWidth >> pictureHeight;
			pixels.reserve(pictureWidth * pictureHeight);
		}

		// reads in maximum intensity from the file
		if (currentLineCount == 2){

			sin.clear();
			sin << line;
			sin >> maxIntensity;
		}
		

		// reads in pixel rgb from the file
		if (currentLineCount > 2){

			sin.clear();
			sin << line;

			while (sin >> pix.r >> pix.g >> pix.b){

				if (pix.r > maxIntensity){

					pix.r = maxIntensity;
					cerr << "";
				}

				if (pix.b > maxIntensity){

					pix.b = maxIntensity;
				}

				if (pix.g > maxIntensity){

					pix.g = maxIntensity;
				}

				pixels.push_back(pix);
			}

		}

		currentLineCount++;

	}

	return true;

}

// writes stored information into an output file
void Picture::write_output(ostream& osref){

	osref << "P3" << endl;
	osref << pictureWidth << " " << pictureHeight << endl;
	osref << maxIntensity << endl;

	for (size_t i = 0; i < pixels.size(); i++){

		/*for (int j = 0; j < pictureWidth; j++){

			osref << get_pixel(i, j).r << " " << get_pixel(i, j).b << " " << get_pixel(i, j).g << endl;
		}*/

		osref << pixels[i].r << " " << pixels[i].g << " " << pixels[i].b << endl;
	}
}

int main(int argc, char **argv) { 

	char* inputFilename = argv[1];
	char* outputFilename = argv[2];

	ifstream fin(inputFilename);
	ofstream fout(outputFilename);

	Picture pic;

	// error checks for too few command line arguments
	if (argc != 3 && argc != 4){

		cerr << "Usage: ./ppm <input_file> <output_file> [x|X|y|Y|i|I]" << endl;
		return 1;
	}

	// checks for stdin and proccesses fin input
	if ((string)argv[1] == "-"){

		// reads from stdin
		pic.read_input(cin);

	} else {

		// checks if input file is open
		if (fin.is_open()){

			pic.read_input(fin);
			fin.close();

		} else {

			cerr << "Unable to open unknown-input-filename.txt." << endl;
			return 1;
		}		

	}

	// checks for stdout and processes fout output
	if ((string)argv[2] == "-"){

		// reads from stdout
		pic.write_output(cout);

	} else {	

		// checks if output file is open
		if (fout.is_open()){

			pic.write_output(fout);
			fout.close();

		} else {

			cerr << "Unable to open unknown/path/unknown-output-filename.txt." << endl;
			return 1;
		}
	}

	if (argc == 4){

		string commandS = argv[3];
		char commandC = commandS[0];

		switch (commandC){

			case 'x': case 'X':
				pic.flip_x();
			break;

			case 'y': case 'Y':
				pic.flip_y();
			break;

			case 'i': case 'I':
				pic.invert();
			break;

			default:
				cerr << "Unknown operation: P" << endl;
				return 1;
			break;
		}
	}


	return 0; 
}
