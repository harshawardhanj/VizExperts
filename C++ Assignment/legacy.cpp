//================= Legacy Code ====================

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>


template<typename NumType=float>
void RenderSphereOnScreen(const NumType* const _coords)
{
   //Some time consuming Graphics stuff
   // No need To implement it
   std::cout<<_coords[0]<<" "<<_coords[1]<<" "<<_coords[2]<<std::endl;

}

/**
*Modify templated SphereRenderTask class in such a way that it will accept only Integers or Real numbers.
* accepted :   SphereRenderTask<int>/SphereRenderTask<float>/SphereRenderTask<double>
* error : SphereRenderTask<anyother_type>
*/
template<typename NumType=float>
class SphereRenderTask
{
     NumType  _coords[3];

     public:
     SphereRenderTask(const NumType& x, const NumType& y, const NumType& z): _coords{x, y, z}{}

     void operator()() const
     {
          RenderSphereOnScreen(_coords);
     }
};

/**
* (1) Identify which part of the code can be improved through multithreading, you can use any multi-threading library.
* (2) Apart from Multithreading, there is one more issue in the code below, Identify and fix it.
* @return
*/
void StartRendering(const char* const inputFilePath)
{
   std::vector<SphereRenderTask<int>*> taskList;

   std::ifstream inputfile(inputFilePath);

   int x,y,z;

   while (inputfile >> x >> y>> z)
   {
     taskList.push_back(new SphereRenderTask<int>(x,y,z));
   }

   inputfile.close();

   for(std::vector<SphereRenderTask<int>*>::iterator iter=taskList.begin(); iter!=taskList.end(); ++iter)
   {
       (**iter)();
   }

}

int main(int argc, const char* argv[])
{

   if(argc<1)
   {
       std::cerr<<"Bad Input"<<std::endl;
       return EXIT_FAILURE;
   }
   //argv[1] := Pass the enclosed input "sphere.txt" file's path.
   StartRendering(argv[1]);

 return 0;
}
