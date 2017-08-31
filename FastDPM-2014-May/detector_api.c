#include "detector_api.h"

//#include "detector_Impl.h"
extern int objDetector(Mat &img, float score_thresh /* = -FLOAT_INF */, bool show_hints /* = true */, bool show_img /* = true */, string save_img /* = */);
int Object_Detector(Mat &img, float score_thresh /* = -FLOAT_INF */, bool show_hints /* = true */, bool show_img /* = true */, string save_img /* = */)
{
	return FastDPM::detect(Mat &img, float score_thresh /* = -FLOAT_INF */, bool show_hints /* = true */, bool show_img /* = true */, string save_img /* = */);
}