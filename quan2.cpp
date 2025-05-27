#include<iostream>
using namespace std;

class invoice
{
    public:
    void generateinvoice(int productid)
    {
        cout<<"generatibg invoice for productid:"<<productid<<endl;
        cout<<"default quantity :1 | no discount applied"<<endl;
    }

void generateinvoice(int productid , int quantity)
    {
 cout<<"generatibg invoice for productid:"<<productid<<endl;
        cout<<"default quantity "<<quantity<<"no discount applied"<<endl;
        }
        void generateinvoice(int productid , int quantity,float discount)

{
 cout<<"generatibg invoice for productid:"<<productid<<endl;
        cout<<"default quantity "<<quantity<<" discount applied"<<discount<<"%"<<endl;
        }
};
int main()
{
   invoice i;
   i.generateinvoice(101);
      i.generateinvoice(102,3);

         i.generateinvoice(103,5,10.5);

    return 0;
}