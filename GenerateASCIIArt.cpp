// Author: Neeraj Mishra
// nmcnemis@gmail.com

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdint.h>
#include <Windows.h>

using namespace cv;
using namespace std;

int main()
{
	system("Color 06");

	int r, c;
	int average;

	Mat img = imread("C:/location/.../fileName.extension");	// The file location.

	for (r = 0; r < img.rows; ++r)
	{
		for (c = 0; c < img.cols; ++c)
		{
			Vec3b pixels = img.at<Vec3b>(r, c);	// The pixels has rgb value as [r, g, b].

			int b = pixels[0];	// Gives us blue value.
			int g = pixels[1];	// Gives us green value.
			int r = pixels[2];	// Gives us red value.
			
			average = (b + g + r) / 3;	// The average for the brightness number.

			string ascii;	// String to store the ascii characters into, in place of the average values.

			if (average >= 0 && average < 50)
				ascii = "^^^";
			if (average >= 50 && average < 100)
				ascii = "***";
			if (average >= 100 && average < 150)
				ascii = "|||";
			if (average >= 150 && average < 200)
				ascii = "###";
			if (average >= 200 && average < 255)
				ascii = "&&&";

			cout << ascii;	// Printing the values out.
		}
		cout << "\n"; // New line here so as to format the pixels / ascii characters right.
	}

	waitKey(0);

	return 0;
}
