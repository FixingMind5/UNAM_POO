#include <iostream>
#include <cmath>
#ifndef FIGURES_H
#define FIGURES_H
#define PI 314159

using namespace std;

/*================================= */
//ALL CLASSES
/*================================ */

class Figure {
public:
  float position[2];
  Figure(float position[2]);
  void ocultar(); // FALTA ESTA
  void trasladar(); //FALTA ESTA
  float calcularArea();
  float calcularPerimetro();
};

template <typename Type>
class Rectangle: public Figure {
private:
  Type base;
  Type height;

public:
  Rectangle(Type base, Type height, float userPosition[2]);
  void setBase(Type base);
  void setHeight(Type height);
  Type getBase();
  Type getHeight();
  Type calcularArea();
  Type calcularPerimetro();
};

template <typename Type>
class Elipse: public Figure {
private:
  Type greaterRadio;
  Type minorRadio;

public:
  Elipse(Type greaterRadio, Type minorRadio, float userPosition[2]);
  void setGreaterRadio(Type greaterRadio);
  void setMinorRadio(Type minorRadio);
  Type getGreaterRadio();
  Type getMinorRadio();
  Type calcularArea();
  Type calcularPerimetro();
};


/*================================= */
//Helpful functions
/*================================ */

template <typename Type>
Type quad(Type number) {
  return number * number;
}

/*================================= */
//ALL CONSTRUCTORS
/*================================ */
template <typename Type>
Rectangle<Type>::Rectangle(Type base, Type height, float userPosition[2]) : Figure(userPosition) {
  this->base = base;
  this->height = height;
  for (int i = 0; i < 2; i++)
    this->position[i] = userPosition[i];
}

Figure::Figure(float position[2]) {
  for(int i = 0; i < 2; i++)
    this->position[i] = position[i];
}

template <typename Type>
Elipse<Type>::Elipse(Type greaterRadio, Type minorRadio, float userPosition[2]) : Figure(userPosition) {
  this->greaterRadio = greaterRadio;
  this->minorRadio = minorRadio;
  for (int i = 0; i < 2; i++)
    this->position[i] = userPosition[i];
}

/*================================= */
//SETTERS
/*================================ */

template <typename Type>
void Rectangle<Type>::setBase(Type base) {
  this->base = base;
}

template <typename Type>
void Rectangle<Type>::setHeight(Type height) {
  this->height = height;
}

template <typename Type>
void Elipse<Type>::setGreaterRadio(Type greaterRadio) {
  this->greaterRadio = greaterRadio;
}

template <typename Type>
void Elipse<Type>::setMinorRadio(Type minorRadio) {
  this->minorRadio = minorRadio;
}


/*================================= */
//GETTERS
/*================================ */

template <typename Type>
Type Rectangle<Type>::getBase(){
  return base;
}

template <typename Type>
Type Rectangle<Type>::getHeight() {
  return height;
}

template <typename Type>
Type Elipse<Type>::getGreaterRadio() {
  return greaterRadio;
}

template <typename Type>
Type Elipse<Type>::getMinorRadio() {
  return minorRadio;
}

/*================================= */
//Polymorphism
/*================================ */

template <typename Type>
Type Rectangle<Type>::calcularArea() {
  return base * height;
}

template <typename Type>
Type Rectangle<Type>::calcularPerimetro() {
  return (base * 2) + (height * 2);
}

template <typename Type>
Type Elipse<Type>::calcularArea() {
  return minorRadio * greaterRadio * PI;
}

template <typename Type>
Type Elipse<Type>::calcularPerimetro() {
  return (2 * PI) * sqrt((quad(greaterRadio) + quad(minorRadio) ) / 2);
}

#endif
