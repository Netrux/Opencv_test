#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
using namespace cv;
using namespace std;

void MyLine( Mat img, Point start, Point end );
Mat dst ;
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

	threshold(src,dst, 20, 200, THRESH_BINARY);

	
	
    cv::imshow("input image ",dst);
   // cv::imshow("cropped image ",image2);
    cv::waitKey(0);

    return(0);
}
