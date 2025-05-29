#include<iostream>
#include<fstream>
int main()
{
std::ofstream outfile ("example.txt");
if (outfile.is_open())
{
    outfile<<"hello,file handling:";
    outfile.close();
    std::cout<<"data written to file sucesfully";

}
else{
        std::cout<<"unable to open file for writing";

}
return 0;
}