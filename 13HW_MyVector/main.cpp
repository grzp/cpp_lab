#include <iostream>
#include <math.h>
using namespace std;


class MyVector
{
public:
    MyVector(size_t size)
    {
        double inlet=0;
        size_ = size;
        double *elems_ = new double [size_];
        while (size){
            cin >> inlet;
            elems_[size_ - size] = inlet;
            --size;
        }
    }

    // ////////////////////////////

    size_t dimens(){return size_;}

    double module()
    {
        double module_=0;
//        for(size_t i=0;i<size_;i++)
//        {
//            module_ = module_ + (elems_[i] * elems_[i]);
//        }
//        return sqrt(module_);
        module_ = elems_[0];
        return module_;
    }

private:
    double *elems_ ;        //wskaźnik do miejsca na stercie gdzie będzie vector
    size_t size_ ;          //ilość, elementów vectora
};

int main()
{
    size_t inlet=0;
    cin >> inlet;
    MyVector wektor1 = MyVector (inlet);
    cout << wektor1.dimens() << endl;
    cout << wektor1.module() << endl;
}
