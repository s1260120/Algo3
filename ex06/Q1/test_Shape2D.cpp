// COMPLETE include the necessary headers here
#include "Shape2D.h"
#include "Rectangle.h"
#include "Circle.h"


extern const float PI = 3.141593f;

int main(void) {
  const int NUM_SHAPES = 2;
  Shape2D* shapes[NUM_SHAPES];



  /*------------------- Circle ----------------------*/
  Point2D center(0.0f, 0.0f);
  shapes[0] = new Circle(center, 1.0f);
  cout << "Shape name: " << shapes[0]->get_name() << endl;
  cout << "Compute area: " << shapes[0]->compute_area() << endl;
  //  cout << "translate: " << shapes[0]->translate(tx,ty) << endl;

  cout << endl;

  /*------------------ Rectangle --------------------*/
  Point2D left_corner(-1.0f, -1.0f);
  shapes[1] = new Rectangle(left_corner, 4.0f, 2.0f);
  cout << "Shape name: " << shapes[1]->get_name() << endl;
  cout << "Compute area: " << shapes[1]->compute_area() << endl;



  for (int i = 0; i < NUM_SHAPES; ++i) {
    float tx = 1.0f;
    float ty = -1.0f;
    shapes[i]->translate(tx, ty);
  }


  assertFloat(shapes[0]->compute_area(), PI);
  assertFloat(shapes[1]->compute_area(), 8.0);

  // COMPLETE free memory for shapes
  delete shapes[0];
  delete shapes[1];


  return 0;
}
