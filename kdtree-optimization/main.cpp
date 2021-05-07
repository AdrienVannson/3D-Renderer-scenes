#include <iostream>
#include <random>
#include <fstream>

#include "renderer/Box.hpp"
#include "renderer/Ray.hpp"

using namespace std;

ofstream output;

double rand (const double min, const double max)
{
    static std::default_random_engine re;
    return uniform_real_distribution<double>(min, max)(re);
}

// Returns the probability that a ray intersecting the box
// delimited by (0,0,0) and (1,1,1) intersects a box
double getProbability (const Box &box, const int testCount=10000)
{
    int intersectionCount = 0;

    for (int i=0; i<testCount; i++) {
        Vect pos(rand(0,1), rand(0,1), rand(0,1));

        const double theta = rand(0, 2*M_PI);
        const double phi = rand(0, M_PI);
        Vect dir(cos(theta)*sin(phi), sin(theta)*sin(phi), cos(phi));

        Ray ray1(pos, dir), ray2(pos, -dir);

        if (box.collisionDate(ray1) != INFINITY || box.collisionDate(ray2) != INFINITY) {
            intersectionCount++;
        }

        //output << (double)intersectionCount / (i+1) << endl;
    }

    return (double)intersectionCount / testCount;
}

int main()
{
    output.open("../kdtree-optimization/output");

    // xCenter yCenter zCenter xSize ySize zSize prob
    for (int i=0; i<10000; i++) {
        Vect min(rand(0,.9), rand(0,.9), rand(0,.9));
        Vect max(rand(min.x()+.099,1), rand(min.y()+.099,1), rand(min.z()+.099,1));

        for (int c=0; c<3; c++)
            output << (max[c] + min[c]) / 2 << " ";

        for (int c=0; c<3; c++)
            output << max[c] - min[c] << " ";

        output << getProbability(Box(min, max)) << "\n";
    }

    return 0;
}
