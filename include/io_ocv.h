//*--------------------------------------------------------------------------*//
//                                                                            //
//                          /$$  /$$$$$$  /$$$$$$$  /$$   /$$                 //
//                         |__/ /$$__  $$| $$__  $$| $$  | $$                 //
//                $$    /$$ /$$| $$  \__/| $$  \ $$| $$  | $$                 //
//              |  $$  /$$/| $$|  $$$$$$ | $$$$$$$/| $$$$$$$$                 //
//               \  $$/$$/ | $$ \____  $$| $$____/ | $$__  $$                 //
//                \  $$$/  | $$ /$$  \ $$| $$      | $$  | $$                 //
//                 \  $/   | $$|  $$$$$$/| $$      | $$  | $$                 //
//                  \_/    |__/ \______/ |__/      |__/  |__/                 // 
//                                                                            //
//*--------------------------------------------------------------------------*//

/**
 * @file io.cc
 * @author Julien Loiseau
 * @date April 2017
 * @brief Simple implementation for Input Output for serial and distributed
 */

#ifndef _visph_io_ocv_h_
#define _visph_io_ocv_h_

#include <cstdlib>
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


// #include <hdf5.h>
// #include <H5hut.h>

// #include "physics/particle.h"
// #include "utils/pixel.h"
#include "pixel.h"

namespace io{

/**
 * @brief      Output data to file
 */
void 
output_file(
	const char * filename,
	const std::vector<pixel_t>& pixels,
	const size_t& width,
	const size_t& height)
{

	assert(width*height == pixels.size());

	cv::Mat mat(height,width,CV_8UC3,(char*)&pixels[0]); 

	cv::imwrite( filename, mat );
	std::cout<<"Outputed: "<<filename<<std::endl;
}
/**
 * @brief      Output data to windows
 */
void 
output_window_wait(
	const char * filename,
	const std::vector<pixel_t>& pixels,
	const size_t& width,
	const size_t& height)
{

	assert(width*height == pixels.size());

	cv::Mat mat(height,width,CV_8UC3,(char*)&pixels[0]); 

	cv::imshow(filename, mat);
	cv::waitKey(0);
}

} // namespace io

#endif // __visph_io_ocv_h__


