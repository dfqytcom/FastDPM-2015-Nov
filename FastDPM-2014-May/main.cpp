#include "FastDPM.h"
#include <conio.h>

vector<string>  yuStdDirFiles( string DirName, vector<string> FileExtensions );
string trim_file_name( string FileName, int FLAG );

int	main()
{
	/* I. Get images */

	string	img_dir = "\\temp\\";
	string extensions[] = { ".jpg" };
	vector<string>	img_extensions( extensions, extensions+1 );
	vector<string>	imgnames = yuStdDirFiles( img_dir, img_extensions );
	double scale = 0.25;
	//imgnames.clear();
	//imgnames.push_back("000061.jpg");

	/* II. Perform Part_Model based detection */

	//FastDPM	PM( "model_inria_14_2_features.txt" );
	FastDPM	PM("person_final.txt");

////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef JPG
	bool	flag = false;
	for (unsigned i = 0; i < imgnames.size(); i++){
		string	img_name = imgnames[i];
		Mat	img_uint8 = imread(img_name.c_str());
		if (img_uint8.empty()){
			cout << "Cannot get image " << img_name << endl;
			getchar();
			return -2;
		}
		cout << "Processing " << trim_file_name(img_name, 0) << endl;
#else 
////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		bool flag = false;
		Mat img;
		VideoCapture cap(0);

		if (!cap.isOpened())
		{
			return -1;
		}

		while (!flag)
		{
			cap >> img;
			Size dsize = Size(img.cols*scale, img.rows*scale);
			Mat img_uint8 = Mat(dsize, CV_32S);
			resize(img, img_uint8, dsize);

			namedWindow("demo", 1);
			if (!img_uint8.empty())
			{
				imshow("demo", img_uint8);
			}
			if (waitKey(30) >= 0)
				flag = true;
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////

		Mat	img = PM.prepareImg( img_uint8 );
		PM.detect( img, -1.0f, true, true );	
		cout<<"------------------------------------------------------------"<<endl;
		if( PM.detections.empty() )
			continue;
		//flag = true;
		char key = waitKey(1000);
		if( key==27 )
			break;
	}
	cout<<"Finished!"<<endl;
	/*if( flag )
		waitKey();
	else
		_getch();
		*/
	return	0;
}