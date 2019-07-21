#include<type_traits>
#include<opencv2/opencv.hpp>

	/*int 
		int 	CV_16SC1 
		int 	CV_16SC2 
		int 	CV_16SC3 
		int 	CV_16SC4 
		int 	CV_16U 
		int 	CV_16UC1 
		int 	CV_16UC2 
		int 	CV_16UC3 
		int 	CV_16UC4 
		int 	CV_32F 
		int 	CV_32FC1 
		int 	CV_32FC2 
		int 	CV_32FC3 
		int 	CV_32FC4 
		int 	CV_32S 
		int 	CV_32SC1 
		int 	CV_32SC2 
		int 	CV_32SC3 
		int 	CV_32SC4 
		int 	CV_64F 
		int 	CV_64FC1 
		int 	CV_64FC2 
		int 	CV_64FC3 
		int 	CV_64FC4 
		int 	CV_8S 
		int 	CV_8SC1 
		int 	CV_8SC2 
		int 	CV_8SC3 
		int 	CV_8SC4 
		int 	CV_8U 
		int 	CV_8UC1 
		int 	CV_8UC2 
		int 	CV_8UC3 
		int 	CV_8UC4 
		int 	CV_USRTYPE1 */
namespace my {

struct None {};
template<class T=None, int W=0, int H=0> class Mat : public cv::Mat
{
public:
	Mat(const std::initializer_list<T> il)
		: cv::Mat(H, W, get_type(), (void*)&*il.begin())
	{
		clone();//Creates a full copy of the array and the underlying data. 
	}
	Mat() : cv::Mat{} 
	{ }

protected:

private:
	constexpr int get_type() {
		if constexpr(std::is_same<T, unsigned char>::value) return CV_8U;
		else if constexpr(std::is_same<T, char>::value) return CV_8S;
		else if constexpr(std::is_same<T, float>::value) return CV_32F;
		else if constexpr(std::is_same<T, double>::value) return CV_64F;
		else if constexpr(std::is_same<T, int>::value) return CV_32S;
		else return CV_USRTYPE1;
	}
};
}

