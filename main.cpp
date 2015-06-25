#include <iostream>
#include <cv.h>
#include <highgui.h>

char key;
int main()
{
    cvNamedWindow("Camera_Output", 1);
    CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY);

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
