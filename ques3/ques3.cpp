#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    const char* filename = argc >=2 ? argv[1] : "smarties.png";
    // Loads an image
    Mat src = imread( samples::findFile( "1.jpg" ), IMREAD_COLOR );
    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default %s] \n", filename);
        return EXIT_FAILURE;
    }
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                 gray.rows/16,  // change this value to detect circles with different distances to each other
                 100, 30, 50, 300 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles
    );
    for( size_t i = 0; i < circles.size(); i++ )
    {
	
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
       // circle( src, center, 1, Scalar(0,100,100), 3, LINE_AA);
        // circle outline
        int radius = c[2];
       // circle( src, center, radius, Scalar(255,0,255), 1, LINE_AA);
	Mat1b mask(src.size(), uchar(0));

   	circle(mask, Point(c[0], c[1]), c[2], Scalar(255), cv::FILLED);
	Rect bbox(c[0] - c[2], c[1] - c[2], 2 * c[2], 2 * c[2]);
	Mat3b res(src.size(), Vec3b(0,0,0));
	src.copyTo(res, mask);
	res = res(bbox);

	
	imwrite("result.png", res);
	imshow("Result", res);
    	waitKey();


    }
    imshow("detected circles", src);
    waitKey();
    return EXIT_SUCCESS;
}
