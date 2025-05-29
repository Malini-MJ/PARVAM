#include<iostream>
#include<fstream>
#include<string>
#include<vector>
struct student
{
    std::string name;
    int age;
    float grade;
};
void writestudentstofile(const std::vector<student> &students , const std::string filename)
{
    std::ofstream outfile(filename);
    if(outfile.is_open())
{
    for(const auto &student:students)
    {
        outfile<<student.name<<","<< student.grade<<"\n";
    }
    outfile.close();
    std::cout<<"student data written to file,";

}
else
{
    std :: cout<<"unable to open file for writing";
}
}
void readstudentsfromfile(const std::string &filename)
{
    std::ifstream infile(filename);
    if(infile.is_open())
{
    std::string line;
    std:: cout<<"reading student data from file:";
    while(std::getline(infile,line))
    {
        std::cout<<line;

    }
    infile.close();
}
else{
        std::cout<<"unable to open file for reading";

}
}
int main()
{ 
    std::vector<student> students ={
{"alice" , 20 , 88.5},
{"bob" , 22 , 91.2},
{"charlie" , 28 , 79.8},

    };
    std::string filename = "students.txt";
    writestudentstofile(students,filename);
    readstudentsfromfile(filename);
    return 0;
}
