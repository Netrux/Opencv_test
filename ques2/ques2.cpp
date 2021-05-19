#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
using namespace cv;
using namespace std;

void MyLine( Mat img, Point start, Point end );
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
    for(int i = 0; i < 1500;i++){
	    Vec3f intensity = src.at<Vec3f>(i, 1400);
            float blue = intensity.val[0];
		//if(blue > 50)
		cout<<blue<<endl;
		//MyLine( src, Point (i,0), Point (i,1400) );
}	
    cv::imshow("input image ",src);
   // cv::imshow("cropped image ",image2);
    cv::waitKey(0);

    return(0);
}
