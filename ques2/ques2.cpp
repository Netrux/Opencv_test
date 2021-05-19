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
	int flag = 0;
	Point pt1,pt2;
	for(int i = 0; i < dst.cols - 100; i++){

		Vec3f intensity = dst.at<Vec3f>(i, 1475);
            	float blue = intensity.val[0];
		if(blue == 0 && flag == 0){
			cout<<"pixel value" <<i<<endl;
			flag = 1;
			pt1.x = 1500;
			pt1.y = i;
			pt2.x = 0;
			pt2.y = i;
			line( src, pt1, pt2, Scalar(0,0,255), 1, LINE_AA);
			}
		else if(blue != 0 && flag ==1){
			cout<<"pixel value"<<i<<endl;
			flag = 0;
			pt1.x = 1500;
			pt1.y = i;
			pt2.x = 0;
			pt2.y = i;
			line( src, pt1, pt2, Scalar(0,0,255), 1, LINE_AA);
			}
}
    cv::imshow("input image ",src);
	imwrite("result.png", src);
    cv::waitKey(0);

    return(0);
}
