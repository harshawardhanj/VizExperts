//================= Legacy Code ====================
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;

/**
*Modify templated SphereRenderTask class in such a way that it will accept only Integers or Real numbers.
* accepted :   SphereRenderTask<int>/SphereRenderTask<float>/SphereRenderTask<double>
* error : SphereRenderTask<anyother_type>
*/

template<class T>
class SphereRenderTask
{
	T  _coords[3];
public:
	void RenderSphereOnScreen(const T* _coords);
	SphereRenderTask(const double& x, const double& y, const double& z) : _coords{ (T)x, (T)y, (T)z } {}
	SphereRenderTask(const float& x, const float& y, const float& z) : _coords{ x, y, z } {}
	SphereRenderTask(const int& x, const int& y, const int& z) : _coords{ x, y, z } {}
	SphereRenderTask(const T x, const T y, const T z)
	{
		cout << "Error: Data types is not allowd";
	}
	void  operatorgo()
	{
		RenderSphereOnScreen(_coords);
	}
};

static long COUNT = 0;
std::mutex mtx;
template<class T>
void  SphereRenderTask<T>::RenderSphereOnScreen(const T* _coords)
{
	mtx.lock();
	cout <<" " << _coords[0] << " " << _coords[1] << " " << _coords[2] <<" "<< std::endl;
    //	std::this_thread::sleep_for(std::chrono::seconds(1));
	COUNT++;
	mtx.unlock();
}

/**
* (1) Identify which part of the code can be improved through multithreading, you can use any multi-threading library.
* (2) Apart from Multithreading, there is one more issue in the code below, Identify and fix it.
* @return
*/
void accumulator_function2(const std::vector<SphereRenderTask<int>*> &v,
	unsigned int beginIndex, unsigned int endIndex)
{
 	for (unsigned int i = beginIndex; i < endIndex; ++i)
	{
 		v[i]->operatorgo();
	}
}

void StartRendering(string fileName)
{
	std::vector<SphereRenderTask<int>*> taskList;
	// Open the File
	std::ifstream inputfile(fileName.c_str());
	// Check if object is valid
	if (!inputfile)
	{
		cout << "Cannot open the File : " << fileName.c_str() << std::endl;
	}
	// Read the next line from File untill it reaches the end.
	std::thread t3([&taskList, &inputfile] {
		double x, y, z;
		while (inputfile >> x >> y >> z)
		{   // Line contains string o f length > 0 then save it in vector
			taskList.push_back(new SphereRenderTask<int>(x, y, z));
		}
	});

	t3.join();
	//Close The File
	inputfile.close();

	// this is used to create parts of vector
	const int TotalThreads = 100;
	thread th[TotalThreads];
	int size = taskList.size();
	int t1 = 0;
	// creating same size of vector to travel 
	int s1 = (size / TotalThreads);
	int t2 = s1;

	for (int i = 0;i < TotalThreads;i++)
	{
		th[i] = thread(accumulator_function2, std::ref(taskList), t1, t2);
		t1 = t2;
		t2 = t2 + s1;
	}

	for(int i=0;i< TotalThreads;i++)
		th[i].join();

	std::cout << "Total Sphere coordinates are : " << COUNT;
	int a;
	cin >> a;
};

int main(int argc, const char* argv[])
{
	if (argc < 1)
	{
		cerr << "Bad Input" << std::endl;
		return EXIT_FAILURE;
	}
	//argv[1] := Pass the enclosed input "sphere.txt" file's path.
	StartRendering("sphere.txt");
	return 0;
}
