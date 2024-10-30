#include<iostream>
#include<cmath>

namespace first{
    int x = 100;

}

int main()
{

    double l,w,pR,aR,a,b,c,s,pT,aT,r,pC,aC;

    //Rectangle
    /*
    std::cout << "Enter Length: ";
    std::cin >> l;
    std::cout << "Enter Width: ";
    std::cin >> w;

    pR = 2*l + 2*w;
    aR = l*w;

    std::cout << "Perimeter: " << pR << "\tArea: " << aR <<"\n";
    */
    //Triangle
    /*
    std::cout << "Enter Side: ";
    std::cin >> a >> b >> c;
    s = (a + b + c)/2;
    pT = a + b + c;
    aT = sqrt(s*(s-a)*(s-b)*(s-c));
    std::cout << "Perimeter: " << pT << "\tArea: " << aT <<"\n";
    return 0;
    */
    //circle
    std::cout << "Enter Radius: ";
    std::cin >> r;
    pC = 2*M_PI*r;
    aC = M_PI*r*r;
    std::cout << "Perimeter: " << pC << "\tArea: " << aC <<"\n";

}