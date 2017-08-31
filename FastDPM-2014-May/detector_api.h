#ifndef DETECTOR_API_H
#define DETECTOR_API_H
#include "FastDPM.h"


#ifdef OBJECT_DETECTOR_API 
#define DETECTOR_DLL __declspec(dllexport)
#else 
#define DETECTOR_DLL __declspec(dllimport)
#endif

DETECTOR_DLL int Object_Detector(Mat &img, float score_thresh /* = -FLOAT_INF */, bool show_hints /* = true */, bool show_img /* = true */, string save_img /* = */);
#endif