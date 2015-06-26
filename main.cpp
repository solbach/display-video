#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>

char key;

void readme()
{
    std::cout << "[INFO] you may specify the camera ID by: $./displayID <ID>" << std::endl;
}

int main( int argc, char* argv[] )
{
    readme();
    const int cameraNo = argc > 1 ? atoi(argv[1]) : 0;
    cvNamedWindow("Camera_Output", 1);
    CvCapture* capture = cvCaptureFromCAM( cameraNo );

    while(true){
        IplImage* frame = cvQueryFrame(capture);
        cvShowImage("Camera_Output", frame);
        key = cvWaitKey(10);
        if (char(key) == 27){
            break;      //If you hit ESC key loop will break.
        }
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Camera_Output"); //Destroy Window
    return 0;
}

