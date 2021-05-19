#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    // Declare the output variables
    Mat dst, cdst, cdstP;
    const char* default_file = "result.png";
    const char* filename = argc >=2 ? argv[1] : default_file;
    // Loads an image
    Mat src = imread( samples::findFile( filename ) );
	Mat cpy = src.clone();
    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default %s] \n", default_file);
        return -1;
    }
    // Edge detection
    Mat blr;
    GaussianBlur( src, blr, Size( 3, 3 ), 1.0);

    Canny(blr, dst, 50, 200, 3);
    // Copy edges to the images that will display the results in BGR
    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    cdstP = cdst.clone();

    // Probabilistic Line Transform
    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(dst, linesP, 1, CV_PI/180, 50, 40, 90 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line( src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255),1, LINE_AA);
    }
    Vec4i l1 = linesP[0];
    Vec4i l2 = linesP[1];
    line( src, Point(l1[0], l1[1]), Point(l2[0], l2[1]), Scalar(0,0,255),1, LINE_AA);
    line( src, Point(l1[2], l1[3]), Point(l2[2], l2[3]), Scalar(0,0,255),1, LINE_AA);
    // Show results
    imshow("Source", src);
    imwrite("result.png",src);
    imshow("blr",blr);
    imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
    // Wait and Exit
    waitKey();
    return 0;
}
